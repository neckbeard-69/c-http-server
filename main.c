#include "include/server.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    server_t server = server_Constructor(AF_INET, 8080, SOCK_STREAM, 0, 10,
                                         INADDR_ANY, init_server);
    server.init_server(&server);
    return 0;
}
