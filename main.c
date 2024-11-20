#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int init_server(struct sockaddr_in *server_info) {
    int server_fd = socket(AF_INET, SOCK_STREAM,
                           0); // establish a socket with TCP connection
    if (server_fd == -1) {
        perror("Failed to initialize socket");
        exit(EXIT_FAILURE);
    }
    // bind the socket to an address
    if (bind(server_fd, (struct sockaddr *)server_info, sizeof(*server_info)) <
        0) {
        perror("Binding the socket failed");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

int main() {
    struct sockaddr_in server_info = {.sin_family = AF_INET,
                                      .sin_addr.s_addr = INADDR_ANY,
                                      .sin_port = htons(8000)};

    int server_fd = init_server(&server_info);
    return 0;
}
