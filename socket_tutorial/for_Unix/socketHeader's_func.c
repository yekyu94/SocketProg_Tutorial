// 소켓프로그래밍에 필요한 소켓 생성을 위해서는 아래 socket.h 라는 헤더파일이 필요하다.
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int socket(int domain, int type, int protocol);
    // -> 소캣을 생성하는 함수인 "socket" 함수 --- 성공시 디스크립터, 실패시 -1 반환
    // 상세한 부분은 별도로 다룸(socket_func.c 참고)

    int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
    // -> "bind" 함수는 생성된 소켓에 IP주소와 포트번호등을 할당하는 함수이다. --- 성공시 0, 실패시 -1 반환

    int listen(int sockfd, int backlog);
    // -> "listen" 함수는 송신이 가능한 상태(listen 상태)로 소켓을 설정해주는 함수이다. --- 성공시 0, 실패시 -1 반환

    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    // -> 상대방의 요청이 들어왔을 때 연결요청을 수락하기 위한 함수이다. --- 성공시 디스크립터, 실패시 -1 반환

    /*
    수행단계
    소켓생성 -> IP주소와 Port번호 할당 -> 연결요청 가능한 Listen 상태로 설정 ( --> 클라이언트의 연결요청 ) -> 연결요청에 대한 수락
    */

   int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
   // -> 클라이언트에서 서버에 연결을 요청하는 함수 --- 성공시 0, 실패시 -1 반환

  
    return 0;
}
