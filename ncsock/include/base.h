/*
 * NCSOCK & NESCA 4
 * by oldteam & lomaster
 * license GPL-2.0
 *   Сделано от души 2023.
*/

#ifndef NCSOCK_BASE_H
#define NCSOCK_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define CIDR  0
#define IPv4  1
#define RANGE 2
#define _URL_   3
#define DNS   4
int this_is(const char* node);
const char* get_this_is(int type);

int check_root_perms(void);
void delayy(int ms);
const char* get_time();
void get_current_date(char* formatted_date, size_t max_length);

/* calculation */
#define OUTRAGEOUS_SPEED 5
#define FIERCE_SPEED     4
#define FAST_SPEED       3
#define BALANCED_SPEED   2
#define NOT_SPEED        1
int calculate_timeout(double rtt, int speed);
int calculate_threads(int speed, int len);
int calculate_ping_timeout(int speed);

/* vector on c */
typedef struct
{
  char **data;
  size_t size;
  size_t capacity;
} string_vector;

typedef struct
{
  int *data;
  size_t size;
  size_t capacity;
} int_vector;

string_vector* create_string_vector();
void string_vector_add(string_vector* vec, const char* str);
void string_vector_free(string_vector* vec);

int_vector* create_int_vector();
void int_vector_add(int_vector* vec, int value);
void int_vector_free(int_vector* vec);

#ifdef __cplusplus
}
#endif

#endif