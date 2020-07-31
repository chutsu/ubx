default: dirs ubx examples
.PHONY: dirs ubx examples

dirs:
	@mkdir -p bin

clean:
	@rm -rf bin

ubx:
	@gcc -g ubx/test_ublox.c -o bin/test_ublox

examples:
	@gcc ubx/example-base.c -o bin/example-base
	@gcc ubx/example-gps.c -o bin/example-gps
	@gcc ubx/example-rover.c -o bin/example-rover
