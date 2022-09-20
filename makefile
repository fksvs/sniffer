CC = gcc
CFLAGS = -Wall

SOURCES = src/main.c src/listen.c src/error_func.c\
	  src/eth.c src/icmp.c src/ip.c src/tcp.c src/udp.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = sniff

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY = clean
clean:
	rm -f $(TARGET) $(OBJECTS)
