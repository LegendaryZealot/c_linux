#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Content-Type: text/html\r\n\r\n");
    printf("GATEWAY_INTERFACE: %s;", getenv("GATEWAY_INTERFACE"));
    printf("</br>");
    printf("SERVER_NAME: %s;", getenv("SERVER_NAME"));
    printf("</br>");
    printf("SERVER_PORT: %s;", getenv("SERVER_PORT"));
    printf("</br>");
    printf("SERVER_PROTOCOL: %s;", getenv("SERVER_PROTOCOL"));
    printf("</br>");
    printf("SERVER_SOFTWARE: %s;", getenv("SERVER_SOFTWARE"));
    printf("</br>");
    printf("ACCEPT: %s;", getenv("ACCEPT"));
    printf("</br>");
    printf("REFERER: %s;", getenv("REFERER"));
    printf("</br>");
    printf("USER_AGENT: %s;", getenv("USER_AGENT"));
    printf("</br>");
    printf("ACCEPT_ENCODING: %s;", getenv("ACCEPT_ENCODING"));
    printf("</br>");
    printf("IF_MODIFIED_SINCE: %s;", getenv("IF_MODIFIED_SINCE"));
    printf("</br>");
    printf("AUTHORIZATION: %s;", getenv("AUTHORIZATION"));
    printf("</br>");
    printf("FROM: %s;", getenv("FROM"));
    printf("</br>");
    printf("REQUEST_METHOD: %s;", getenv("REQUEST_METHOD"));
    printf("</br>");
    printf("QUERY_STRING: %s;", getenv("QUERY_STRING"));
    printf("</br>");
    printf("CONTENT_LENGTH: %s;", getenv("CONTENT_LENGTH"));
    printf("</br>");
    printf("CONTENT_TYPE: %s;", getenv("CONTENT_TYPE"));
    return 0;
}


