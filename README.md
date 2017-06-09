rs485cfg
========

Small application to configure a serial (TTY) port in RS485 mode for Turing Boards.
It only configures RS485 mode. It does not configure baud rate, parity or flow control.
Once configured, one can use other tools or libraries to read and write data to the serial port.

Usage:

Configure a serial port in RS485 mode:
rs485cfg /dev/ttyS0

Set baud rate:
stty -F /dev/ttyS0 57600

Read:
cat /dev/ttyS0

Write:
echo "Test String" > /dev/ttyS0
