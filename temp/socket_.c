#include <sys/socket.h>

int socket(int domain, int type, int protocol);     // 소캣 생성
//int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);       // 주소 할당
int listen(int sockfd, int backlog);       // Open상태
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);      // 연결요청 수랑
//int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);     // 연결 요청 
