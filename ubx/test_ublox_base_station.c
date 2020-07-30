#include "ublox.h"

#define BASE_STATION_IP "127.0.0.1"
#define BASE_STATION_PORT 8080

int main() {
  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    LOG_ERROR("Socket creation failed!");
    return -1;
  } else {
    DEBUG("Created socket!");
  }

  // Configure server ip and port number
  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(BASE_STATION_IP);
  server.sin_port = htons(BASE_STATION_PORT);

  // Connect to server
  int retval = connect(sockfd, (struct sockaddr *) &server, sizeof(server));
  if (retval != 0) {
    LOG_ERROR("Connection with the base station failed!");
    exit(0);
  } else {
    DEBUG("Connected to the base station!");
  }

  // Loop
  while (1) {
    // Read byte
    uint8_t data = 0;
    if (read(sockfd, &data, 1) != 1) {
      LOG_ERROR("Failed to read byte from base station!");
      LOG_ERROR("Shutting down ...");
      return 0;
    }
    printf("Got byte 0x%02x\n", data);
  }

  return 0;
}
