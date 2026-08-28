#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
    /* 1. Create TCP socket */
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1) {
        perror("socket");
        return 1;
    }

    /* 2. Build address of the server */
    struct sockaddr_in server_addr = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        close(fd);
        return 1;
    }

    /* 3. Connect to server */
    if (connect(
        fd,
        (struct sockaddr *)&server_addr,
        sizeof(server_addr)
    ) == -1) {
        perror("connect");
        close(fd);
        return 1;
    }

    printf("Connected to server!\n");

    /* 4. Send data */
    const char *message = "Hello from client!";

    ssize_t sent = send(
        fd,
        message,
        strlen(message),
        0
    );

    if (sent == -1) {
        perror("send");
        close(fd);
        return 1;
    }

    /* 5. Receive response */
    char buffer[1024];

    ssize_t received = recv(
        fd,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (received == -1) {
        perror("recv");
        close(fd);
        return 1;
    }

    buffer[received] = '\0';

    printf("Server sent: %s\n", buffer);

    /* 6. Close socket */
    close(fd);

    return 0;
}