#pragma once

#include <netinet/in.h>
#include <sys/types.h>
#define BUFFER_SIZE 16000
typedef struct Server server_t;
struct Server {
    int domain;
    int port;
    int service;
    int protocol;
    int backlog;
    u_long interface;
    int socket;
    struct sockaddr_in address;
    void (*init_server)(server_t *server);
};

server_t server_Constructor(int domain, int port, int service, int protocol,
                            int backlog, u_long interface,
                            void (*launch)(server_t *server));

void init_server(server_t *server);
