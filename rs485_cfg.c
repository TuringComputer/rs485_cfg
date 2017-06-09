#include <linux/serial.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "rs485_cfg.h"

int main(int argc, char **argv)
{
	struct serial_rs485 rs485conf;

	/* Open your specific device (e.g., /dev/ttySC0): */
  	int fd = open (argv[1], O_RDWR);
  	if (fd < 0) {
		printf("Error while openning serial port (%d).\n", fd);
                return fd;
  	}

	rs485conf.flags = 0;
	/* Enable RS485 mode: */
	rs485conf.flags |= SER_RS485_ENABLED;
	/* Set logical level for RTS pin equal to 1 when sending: */
	rs485conf.flags &= ~(SER_RS485_RTS_ON_SEND);
	/* Set logical level for RTS pin equal to 0 after sending: */
	rs485conf.flags |= SER_RS485_RTS_AFTER_SEND;

	rs485conf.delay_rts_after_send = 0;
	rs485conf.delay_rts_before_send = 10;

	if (ioctl (fd, TIOCSRS485, &rs485conf) < 0) {
		printf("Error while configuring serial port (%d).\n", errno);
		return errno;
        }

	if (close (fd) < 0) {
		printf("Error while closing serial port (%d).\n", errno);
		return errno;
        }

	return 0;
}
