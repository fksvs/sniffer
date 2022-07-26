#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include "ip.h"

void ip_header(char *buffer)
{
	struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
	struct sockaddr_in src, dst;

	memset(&src, 0, sizeof(src));
	memset(&dst, 0, sizeof(dst));

	src.sin_addr.s_addr = iph->saddr;
	dst.sin_addr.s_addr = iph->daddr;

	printf("ipv%d     | ", iph->version);
	printf("%s", inet_ntoa(src.sin_addr));
	printf(" --> ");
	printf("%s", inet_ntoa(dst.sin_addr));
	printf(" serv:%d ttl:%d protocol:%d len:%d\n", (unsigned int)(iph->tos),
	       (unsigned int)(iph->ttl), (unsigned int)(iph->protocol),
	       (unsigned int)(iph->tot_len));
}

int get_protocol(char *buffer)
{
	struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
	return iph->protocol;
}
