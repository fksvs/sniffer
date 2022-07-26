#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "listen.h"
#include "eth.h"
#include "icmp.h"
#include "ip.h"
#include "tcp.h"
#include "udp.h"

void start_sniff(int flag)
{
	int sockfd;

	if (flag == 0)
		flag |= ALL;
	if ((sockfd = init_socket()) == -1)
		exit(EXIT_FAILURE);
	if (listen_data(sockfd, flag) == -1)
		exit(EXIT_FAILURE);
}

int parser(int argc, char *argv[])
{
	char *usage = " usage : sniff [options]\n\
 -e : ethernet\n -c : icmp\n -i : ip\n -t : tcp\n -u : udp";
	int flag = 0;
	int opt;

	while ((opt = getopt(argc, argv, "ecituh")) != -1) {
		switch (opt) {
		case 'e':
			flag |= ETH_FLAG;
			break;
		case 'c':
			flag |= ICMP_FLAG;
			break;
		case 'i':
			flag |= IP_FLAG;
			break;
		case 't':
			flag |= TCP_FLAG;
			break;
		case 'u':
			flag |= UDP_FLAG;
			break;
		case 'h':
			printf("%s\n", usage);
			exit(0);
		}
	}
	return flag;
}

int main(int argc, char *argv[])
{
	int flag;

	if (getuid() != 0) {
		printf("Operation not permitted\n");
		exit(0);
	}
	flag = parser(argc, argv);
	start_sniff(flag);

	return 0;
}
