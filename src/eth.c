#include <stdio.h>
#include <netinet/if_ether.h>
#include "eth.h"

void ethernet_header(char *buffer)
{
	struct ethhdr *eth = (struct ethhdr *)buffer;

	printf("ethernet | ");
	printf("%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",
			eth->h_source[0], eth->h_source[1] ,eth->h_source[2],
			eth->h_source[3], eth->h_source[4], eth->h_source[5]);
	printf(" --> ");
	printf("%.2x-%.2x-%.2x-%.2x-%.2x-%.2x\n",
			eth->h_dest[0], eth->h_dest[1] ,eth->h_dest[2],
			eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
}
