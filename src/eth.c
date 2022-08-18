#include <stdio.h>
#include "eth.h"
#include "type.h"

void ethernet_header(char *buffer)
{
	struct eth_hdr *eth = (struct eth_hdr *)buffer;

	printf("ethernet | %.2x-%.2x-%.2x-%.2x-%.2x-%.2x --> \
%.2x-%.2x-%.2x-%.2x-%.2x-%.2x- %u\n",
	       eth->src[0], eth->src[1], eth->src[2],
	       eth->src[3], eth->src[4], eth->src[5],
	       eth->dst[0], eth->dst[1], eth->dst[2], eth->dst[3],
	       eth->dst[4], eth->dst[5], eth->protocol);
}
