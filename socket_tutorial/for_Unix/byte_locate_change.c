#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    /*
    CPU에 따라서 데이터를 메모리에 저장하는 방식이 다르다.
    1을 데이터에 저장하는 경우 아래와 같은 차이가 있다.
    빅 엔디안식 표현 : 00000000 00000000 00000000 00000001
    리틀 엔디안식 표현 : 00000001 00000000 00000000 00000000 (일반적인 인텔, AMD의 CPU)
    ps, 이걸 컴파일러가 설정해주는줄 알고 열심히 컴파일 설정을 찾았던 기억이...

    위와 같이 저장하는 방식의 차이때문에 송신자와 수신자가 서로다른 방식의 데이터 저장방식을 사용할 경우 문제가 생길수있다.
    따라서, 네트워크에서의 데이터 전송에있어서는 항상 빅 엔디안식 표현으로 셋팅하여 전송하는 방식을 채용했다.
    */

    /* 다음 네가지 방식을 사용
    unsigned short htons(unsigned short);
    unsigned short ntohs(unsigned short);
    unsigned long htonl(unsigned long);
    unsigned long ntohl(unsigned long);
    htons : host to networt use short
    short 는 PORT 번호
    Long 은 IP 주소
    */
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("HOST Port : %#x \n", host_port);
    printf("NET Port : %#x \n", net_port);
    printf("HOST Addr : %#lx \n", host_addr);
    printf("NET Addr : %#lx \n", net_addr);
    
    // 만약 실행결과에서 HOST와 NET정보가 서로 반대로 나오면 사용중인 CPU가 리틀 엔디안을 채용했다 볼수있다.

    /* IP주소일 경우에 Long 을 쓴다고 했는데 일반적으로 IP주소는 '.'으로 구분되는 문자열을 입력으로 넣는다. 따라서 다른방법이 필요 */

    char *addr1 = "1.2.3.4";
    char *addr2 = "127.0.0.300";

    unsigned long conv_addr = inet_addr(addr1);
    if(conv_addr==INADDR_NONE){
        printf("ERROR\n");
    }else(printf("ADDR1 => %#lx\n", conv_addr));

    conv_addr = inet_addr(addr2);
    if(conv_addr==INADDR_NONE){
        printf("ERROR > 올바르지 못한 IP주소형태\n");
    }else(printf("ADDR2 => %#lx\n", conv_addr));

    printf("\n");
    struct sockaddr_in addr_inet;
    if( !inet_aton(addr1, &addr_inet.sin_addr))
        printf("ERROR\n");
    else 
        printf("Network ordered integer addr : %#x \n", addr_inet.sin_addr.s_addr );
    

    return 0;
}