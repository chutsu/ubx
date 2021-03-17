#include "ubx.h"

int main() {
  /* Setup UART connection to UBlox */
  uart_t uart;
  if (uart_connect(&uart, "/dev/ttyACM0") != 0) {
    LOG_ERROR("Failed to connect to ublox!");
    return -1;
  }

  /* Setup ublox */
  ublox_t ublox;
  if (ublox_init(&ublox, &uart) != 0) {
    LOG_ERROR("Failed to initialize ublox!");
    return -1;
  }

  /* Run ublox in rover mode */
  const char *base_ip = "127.0.0.1";
  const int base_port = 8080;
  int loop = 1;
  if (ublox_rover_run(&ublox, base_ip, base_port, &loop) != 0) {
    FATAL("Failed to run ublox in rover mode!");
  }

  return 0;
}
