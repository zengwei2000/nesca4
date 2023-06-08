#ifndef TCP_PING_H
#define TCP_PING_H
#include <stdio.h>

#define PING_SUCCESS 0
#define PING_ERROR -1

#ifdef __cplusplus
extern "C" {
#endif

/*Самый простой TCP пинг, использует функцию connect,
 * очень палевный, и легко баниться.*/
int
connect_tcp_ping(const char* ip, int port, int timeout_ms);

#ifdef __cplusplus
}
#endif

#endif