#include <stdio.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include "udp.h"

void udp_header(char *buffer)
{
	struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
	struct udphdr *udph = (struct udphdr *)(buffer + sizeof(struct ethhdr) +
						(iph->ihl) * 4);

	printf("udp      | ");
	printf("%d", ntohs(udph->source));
	printf(" --> ");
	printf("%d ", ntohs(udph->dest));
	printf("len:%d\n", ntohs(udph->len));
}
