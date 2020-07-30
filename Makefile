default: dirs ubx
.PHONY: dirs ubx

dirs:
	@mkdir -p bin

ubx:
	gcc ubx/test_ublox.c -o bin/test_ublox
	gcc ubx/test_ublox_base_station.c -o bin/test_ublox_base_station
