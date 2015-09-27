#ifndef DDEBUG
#define DDEBUG 0
#endif
#include "ddebug.h"

#include    <ndk.h>
#include "ngx_http_set_rot13.h"

ngx_int_t
ngx_http_set_misc_set_rot13(ngx_http_request_t *r, ngx_str_t *res,
    ngx_http_variable_value_t *v)
{

    ngx_str_t   src;

    src.len = v->len;
    src.data = v->data;

    res->len = v->len;
    ndk_palloc_re(res->data, r->pool, res->len);

    ngx_rot13(res->data, src.data, res->len);

    return NGX_OK;
}

void
ngx_rot13(u_char *dst, u_char *src, size_t n)
{
    while(n) {
        if (*src>='a' && *src<='m') *dst=*src-'a'+'n';
        else if (*src>='n' && *src<='z') *dst=*src-'n'+'a';
        else if (*src>='A' && *src<='M') *dst=*src-'A'+'N';
        else if (*src>='N' && *src<='Z') *dst=*src-'N'+'A';
        else *dst = *src;
        dst++;
        src++;
        n--;
    }
}
