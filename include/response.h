#include "../include/http.h"
#pragma once

typedef enum status_code {
    SUCESS = 200,
    MULTIPLE_CHOICES = 300,
    MOVED_PERMANETLY = 302,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500,
    BAD_GATEWAY = 502,

} Status_code_t;

typedef struct res_header {
    Http_header_t http_header_common;
    char *access_control_allow_origin;

}Res_header_t;

typedef struct res_body {

} Res_body_t;

