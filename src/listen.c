#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include "listen.h"
#include "eth.h"
#include "icmp.h"
#include "ip.h"
#include "tcp.h"
#include "udp.h"

void output(char *buffer, int flag)
{
	int protocol = get_protocol(buffer);

	if ((flag & ETH_FLAG) == ETH_FLAG)
		ethernet_header(buffer);
	if ((flag & IP_FLAG) == IP_FLAG)
		ip_header(buffer);

	switch (protocol) {
	case 1:
		if ((flag & ICMP_FLAG) == ICMP_FLAG)
			icmp_packet(buffer);
		break;
	case 6:
		if ((flag & TCP_FLAG) == TCP_FLAG)
			tcp_header(buffer);
		break;
	case 17:
		if ((flag & UDP_FLAG) == UDP_FLAG)
			udp_header(buffer);
		break;
	}
}

int listen_data(int sockfd, int flag)
{
	char buffer[BUFF_SIZE];
	int total;

	while (1) {
		memset(buffer, 0, BUFF_SIZE);
		total = recvfrom(sockfd, buffer, BUFF_SIZE, 0, NULL, NULL);
		if (total < 0 || total == 0) {
			perror("[ERROR] [listen.c listen_data() recvfrom()] ");
			return -1;
		}
		output(buffer, flag);
	}
	return 0;
}

int init_socket()
{
	int sockfd;
	if ((sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
		perror("[ERROR] [listen.c init_socket socket] ");
		return -1;
	}
	return sockfd;
}
