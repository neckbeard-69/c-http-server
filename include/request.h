#include "../include/http.h"
#pragma once


typedef struct req_body {
    char *data;
    size_z length;
} Request_body_t;

typedef struct req_header {
    Request_header_t http_header_common; 
    Method method;
    char *url;

} Request_header_t;

typedef struct request {
    Request_header_t header;
    req_body body;
} Request_t;
