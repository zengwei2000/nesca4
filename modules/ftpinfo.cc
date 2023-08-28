/*
 * NESCA 4
 * by oldteam & lomaster
 * license GPL-3.0
 *   Сделано от души 2023.
*/

#include "include/ftpinfo.h"

std::string get_ftp_description(std::string server, std::string port, std::string username, std::string password)
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == EOF) {return FTP_ERROR;}

  struct sockaddr_in server_addr{};
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(std::stoi(port));
  if (inet_pton(AF_INET, server.c_str(), &(server_addr.sin_addr)) <= 0) {
    close(sockfd);
    return FTP_ERROR;
  }

  if (connect(sockfd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) == EOF) {
    close(sockfd);
    return FTP_ERROR;
  }

  char buffer[2026];
  memset(buffer, 0, sizeof(buffer));

  int bytes_sent = send(sockfd, ("USER " + username + "\r\n").c_str(), strlen(("USER " + username + "\r\n").c_str()), 0);
  if (bytes_sent == EOF) {
    close(sockfd);
    return FTP_ERROR;
  }

  bytes_sent = send(sockfd, ("PASS " + password + "\r\n").c_str(), strlen(("PASS " + password + "\r\n").c_str()), 0);
  if (bytes_sent == EOF) {
    close(sockfd);
    return FTP_ERROR;
  }

  bytes_sent = send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
  if (bytes_sent == EOF) {
    close(sockfd);
    return FTP_ERROR;
  }

	set_socket_timeout_pro(sockfd, 2000);

  int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received == EOF) {
    close(sockfd);
    return FTP_ERROR;
  }

  close(sockfd);

  std::string response(buffer);
  size_t pos = response.find(' ');
  if (pos == std::string::npos) {return FTP_ERROR;}

  std::string response_description = response.substr(pos + 1);
  response_description = std::regex_replace(response_description, std::regex("\r"), "");
  response_description = std::regex_replace(response_description, std::regex("\n"), "");

  return response_description;
}

