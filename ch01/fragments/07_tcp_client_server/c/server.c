#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        close(listen_fd);
        return 1;
    }

    if (bind(
        listen_fd,
        (struct sockaddr *)&server_addr,
        sizeof(server_addr)
    ) == -1) {
        perror("bind");
        close(listen_fd);
        return 1;
    }

    if (listen(listen_fd, 5) == -1) {
        perror("listen");
        close(listen_fd);
        return 1;
    }

    printf("Server listening on 127.0.0.1:8080\n");

    int client_fd = accept(listen_fd, NULL, NULL);

    if (client_fd == -1) {
        perror("accept");
        close(listen_fd);
        return 1;
    }

    printf("Client connected!\n");

    char buffer[1024];

    ssize_t received = recv(
        client_fd,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (received == -1) {
        perror("recv");
        close(client_fd);
        close(listen_fd);
        return 1;
    }

    buffer[received] = '\0';

    printf("Client sent: %s\n", buffer);

    const char *response = "Hello from server!";

    ssize_t sent = send(
        client_fd,
        response,
        strlen(response),
        0
    );

    if (sent == -1) {
        perror("send");
    }

    close(client_fd);

    close(listen_fd);

    return 0;
}