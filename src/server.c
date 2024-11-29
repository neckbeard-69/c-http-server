#include "../include/server.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

server_t server_Constructor(int domain, int port, int service, int protocol,
                            int backlog, u_long interface,
                            void (*launch)(server_t *server)) {
    server_t server = (server_t){
        .domain = domain,
        .service = service,
        .port = port,
        .protocol = protocol,
        .backlog = backlog,
        .address.sin_family = domain,
        .address.sin_port = htons(port),
        .address.sin_addr.s_addr = htons(interface),
        .socket = socket(domain, service, protocol),
    };

    if (server.socket < 0) {
        perror("Failed to initialize/connect to socket...\n");
        exit(EXIT_FAILURE);
    }

    if (bind(server.socket, (struct sockaddr *)&server.address,
             sizeof(server.address)) < 0) {
        perror("Failed to bind socket...\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server.socket, server.backlog) < 0) {
        perror("Failed to start listening...\n");
        exit(EXIT_FAILURE);
    }

    server.init_server = launch;
    return server;
}

void init_server(struct Server *server) {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Listening for connection ... \n");
        int addrlen = sizeof(server->address);
        int new_socket =
            accept(server->socket, (struct sockaddr *)&server->address,
                   (socklen_t *)&addrlen);
        ssize_t bytesRead = read(new_socket, buffer, BUFFER_SIZE - 1);
        if (bytesRead >= 0) {
            buffer[bytesRead] = '\0';
            puts(buffer);
        } else {
            perror("Error reading buffer...\n");
        }
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                         "<!DOCTYPE html>\r\n"
                         "<html>\r\n"
                         "<head>\r\n"
                         "<title>some title</title>\r\n"
                         "</head>\r\n"
                         "<body>\r\n"
                         "<h1>it is working!!!!</h1>\r\n"
                         "</body>\r\n"
                         "</html>\r\n";
        write(new_socket, response, strlen(response));
        close(new_socket);
    }
}
