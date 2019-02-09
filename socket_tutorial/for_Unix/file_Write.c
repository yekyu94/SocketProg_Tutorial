#include <sys/types.h>
// -> primitive(고전적인) 자료형들을 다루고있음
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void error_handling(char *message);

/* 파일 디스크립터  
0 : 표준입력
1 : 표준출력
2 : 표준애러 */

int main(int argc, char const *argv[])
{
    int fd;
    char buf[]="파일입출력!!!!\n";
    
    fd = open("./data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if(fd==-1) error_handling("File open error!");
    printf("FIle's Descriptor : %d \n", fd);
    // int open(const char *path, int flag);
    /* "open" 함수는 파일을 여는 함수 --- 성공시 파일 디스크립터, 실패시 -1
    flag 인자는 아래와 같음
    O_CREAT : 필요하면 파일 생성                |       OTRUNC : 기존 데이터 전부 삭제
    O_APPEND : 기존 데이터 보존하고, 뒤에 저장     |       O_RDONLY : 읽기 전용으로 파일 오픈
    O_WRONLY : 쓰기 전용을 파일 오픈             |       O_RDWR : 읽기, 쓰기 겸용으로 파일 오픈
    flag로 인자 전달시 여러개의 인자를 전달할때는 OR연산자(|)를 이용한다.
    */

    if(write(fd, buf, sizeof(buf)) == -1) error_handling("File Write error!");
    // ssize_t write(int fd, const void *buf, size_t nbytes);
    /* -> 파일에 데이터를 쓰는 함수
    fd : 데이터를 받을 파일 디스크립터 번호
    buf : 전송할 데이터가 저장된 버퍼의 주소값
    nbytes : 전송할 데이터의 바이트 수
    size_t : unsigned int
    ssize_t : signed int
    */

    close(fd);
    // nt close(int fd);
    // -> 파일 닫는 함수 --- 성공시 0, 실패시 -1

    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}