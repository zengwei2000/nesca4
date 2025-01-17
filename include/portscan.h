/*
 *          NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
 *
*/

#ifndef SYN_SCAN_H
#define SYN_SCAN_H

#include <iostream>
#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
#include <string>
#include <random>
#include <netdb.h>
#include <cerrno>
#include <unistd.h>
#include <thread>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <mutex>
#include <vector>
#include <cstdint>
#include <ctime>
#include <string>

#include "../include/nescalog.h"
#include "../ncsock/include/ip.h"
#include "../ncsock/include/tcp.h"
#include "../ncsock/include/socket.h"
#include "../include/nescautils.h"

#define PORT_OPEN             0
#define PORT_CLOSED           1
#define PORT_FILTER           2
#define PORT_ERROR           -1
#define PORT_OPEN_OR_FILTER   3
#define PORT_NO_FILTER        4

#define SYN_SCAN              1
#define XMAS_SCAN             2
#define FIN_SCAN              3
#define NULL_SCAN             4
#define ACK_SCAN              5
#define WINDOW_SCAN           6
#define MAIMON_SCAN           7
#define PSH_SCAN              8

std::string get_type(uint8_t type);
int get_port_status(unsigned char* buffer, uint8_t scan_type);
std::string return_port_status(uint8_t type);

#endif
