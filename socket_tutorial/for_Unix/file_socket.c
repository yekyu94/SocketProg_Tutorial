#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(void)
{
    int fd1, fd2, fd3;
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    fd2 = open("./files/test.txt", O_CREAT|O_WRONLY|O_TRUNC);
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    printf("File's Descriptor fd1 : %d\n", fd1);
    printf("File's Descriptor fd2 : %d\n", fd2);
    printf("File's Descriptor fd3 : %d\n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}