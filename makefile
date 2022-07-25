CC = gcc
CFLAGS = -Wall

SOURCES = main.c listen.c eth.c icmp.c ip.c tcp.c udp.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = sniff

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY = clean
clean:
	rm -f $(TARGET) $(OBJECTS)
