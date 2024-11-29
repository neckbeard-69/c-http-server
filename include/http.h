#pragma once

typedef enum status_code {
    SUCESS = 200,
    NO_CONTENT = 204,
    MULTIPLE_CHOICES = 300,
    MOVED_PERMANETLY = 302,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500,
    BAD_GATEWAY = 502,
} Status_code_t;

typedef struct response_header {
    char *http_version;
    char *host;
    char *content_type;
    char *content_length;
    char *user_agent;
    Status_code_t status_code;
    void (*set_status)(Status_code_t);
} Response_Header_t;

typedef struct response_body {
    char *data; // Response payload (e.g., HTML, JSON).
} Response_Body_t;

typedef struct response {
    Response_Header_t header;
    Response_Body_t body;
} Response_t;

typedef struct request_header {
    char *http_version;
    char *host;
    char *content_type;
    char *content_length;
    char *user_agent;
} Request_Header_t;

typedef struct request_body {
    char *data; // Request payload (e.g., JSON).
} Request_Body_t;

typedef struct request {
    Request_Header_t header;
    Request_Body_t body;
} Request_t;

typedef enum http_method {
    GET,
    POST,
    PUT,
    DELETE,
    UPDATE,
    PATCH
} HTTP_Method_t;

typedef struct http {
    HTTP_Method_t method;
    Request_t request;
    Response_t response;
} http_t;
