#include <sys/types.h>
// -> primitive(고전적인) 자료형들을 다루고있음
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 100

void error_handling(char *message);

int main(int argc, char const *argv[])
{
    int fd;
    char buf[BUF_SIZE];
    
    fd = open("./data.txt", O_RDONLY);
    if(fd == -1) error_handling("File Open Error");
    printf("File's Descriptor : %d \n", fd);

    if(read(fd, buf, sizeof(buf)) == -1) error_handling("File Read Error");
    printf("file data : %s", buf);
    // ssize_t read(int fd, void *buf, size_t nbytes);
    /* 파일 내용을 읽어오는 함수 --- 성공시 읽어온 바이트 수(단, 끝을 만나면 0), 실패시 -1
    fd : 데이터 수신 대상의 파일 디스크립터
    buf : 수신한 데이터를 저장한 버퍼의 주소값
    nbytes : 수신할 최대 바이트 수
    */

    close(fd);
    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}