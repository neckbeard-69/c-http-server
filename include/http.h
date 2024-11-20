#pragma once


typedef enum http_method {
    GET,
    POST,
    DELETE,
    PATCH,
    PUT,
    UPDATE

} Method;

typedef struct http_headers {
    char *content_type;
    char *content_length;
    char *user_agent;
    char *accept;
    char *accept_language;
    char *accept_encoding;
    char *connection;
    char *host;
} Http_headers_t;
