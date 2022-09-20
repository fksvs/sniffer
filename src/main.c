#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "listen.h"
#include "error_func.h"
#include "eth.h"
#include "icmp.h"
#include "ip.h"
#include "tcp.h"
#include "udp.h"

int sockfd;
int flag = 0;

void print_usage()
{
	printf("\nusage : sniff [protocol]\n\n\
 -e : ethernet\n\
 -c : icmp\n\
 -i : ip\n\
 -t : tcp\n\
 -u : udp\n\n");
	exit(EXIT_FAILURE);
}

void parser(int argc, char *argv[])
{
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
			print_usage();
		}
	}

	if (flag == 0) flag |= ALL;
}

int main(int argc, char *argv[])
{
	if (getuid()) err_exit("permission denied.");

	parser(argc, argv);
	sockfd = init_socket();
	listen_data(sockfd, flag);

	return 0;
}
