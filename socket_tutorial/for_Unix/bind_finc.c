#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);


int main(void)
{
    struct sockaddr_in serv_addr;
    /*
    struct sockaddr_in
    {
        sa_family_t         sin_family;  // 주소체계
        uint16_t            sin_port;    // 16비트 TCP/UDP 포트번호
        struct in_addr      sin_addr;    // 32비트 IP주소
        char                sin_size[8]; // 사용X
    }
    struct in_addr
    {
        in_addr_t           s_addr;     // 32비트 IPv4 인터넷 주소
    }
    sockaddr -> sin_family 멤버
        AF_INET : IPv4 주소체계
        AF_INET : IPv6 주소체계
        AF_LOCAL : 로컬통신 주소체계
    */
    
    struct sockaddr serv_addr2;
    /*
    struct sockaddr
    {
        sa_family_t     sin_family;     // 주소체계
        char            sa_data[14];    // 주소정보( IP 주소 + Port 번호 )
    }
    */

    int serv_sock = socket(PF_INET, SOCK_STREAM, 0); // 여기서 0은 TCP의미

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) error_handling("Error");
    /*
    bind 함수는 인자에는 정보를 채우고 남은 부분을 0으로 채울것을 요구한다. sockaddr 구조체는 이러한 정보 입력에 부적절하다.
    그래서 sockaddr_in 구조체에 데이터를 입력한 후 sockaddr 구조체 형으로 변환하여 입력해주는 방식을 사용한다.
    */
}


void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}