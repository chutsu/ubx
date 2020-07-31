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

  /* Run ublox in gps mode */
  int loop = 1;
  if (ublox_run(&ublox, &loop) != 0) {
    FATAL("Failed to run ublox in GPS mode!");
  }

  return 0;
}
