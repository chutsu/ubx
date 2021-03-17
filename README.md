# ubx
A C header only library to interface with the u-blox GPS modules (**Only tested
with the UBlox ZED-F9P**). This library contains:

- UBX Parser
- RTCM3 Parser
- RTK-GPS Server and Client (Designed to work over TCP/IP, i.e Wifi)


## Build

    make

Have a look at:

    ubx/example-gps.c
    ubx/example-base.c
    ubx/example-rover.c

for how to use this library to interface / setup GPS and RTK-GPS modes.

## License

The source code is released under MIT license.
