#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    int socket(int domain, int type, int protocol);
    /* 
    1) domain에 대해서
    PF_INET : IPv4 체계
    PF_INET6 : IPv6 체계
    PF_LOCAL : 로컬통신을 위한 UNIX 프//로토콜 체계
    PF_PACKET : Low Level 소켓통신
    PF_IPX : IPX 노벨 프로토콜 체계
  
    2) type에 대해서
    SOCK_STRREAM : 연결지향형 소켓
    SOCK_DGRAM : 비 연결지향형 소켓

    3) protocol에 대해서
    실제 프로토콜이 무엇인지 명시함
    IPPROTO_TCP : TCP
    IPPROTO_UDP : UDP
    */

   int sk_TCP = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP 소켓 예시
   int sk_UDP = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP); // UDP 소켓 예시
}