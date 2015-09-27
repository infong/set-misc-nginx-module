#include <ngx_core.h>
#include <ngx_config.h>
#include <ngx_http.h>

void ngx_rot13(u_char *dst, u_char *src, size_t n);

ngx_int_t ngx_http_set_misc_set_rot13(ngx_http_request_t *r,
        ngx_str_t *res, ngx_http_variable_value_t *v);

