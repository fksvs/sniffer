#include <stdio.h>
#include <string.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "tcp.h"

void tcp_header(char *buffer)
{
	struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
	struct tcphdr *tcph = (struct tcphdr *)
		(buffer + sizeof(struct ethhdr) + (iph->ihl) * 4);
	char flag_str[32];
	memset(flag_str, 0, 32);

        if (tcph->fin) strcat(flag_str, "fin,");
        if (tcph->syn) strcat(flag_str, "syn,");
        if (tcph->rst) strcat(flag_str, "rst,");
        if (tcph->psh) strcat(flag_str, "psh,");
        if (tcph->ack) strcat(flag_str, "ack,");
        if (tcph->urg) strcat(flag_str, "urg,");

	printf("tcp      | %d --> %d seq:%u ack:%u flag:%s win:%d len:%d\n",
	       ntohs(tcph->source), ntohs(tcph->dest), ntohl(tcph->seq),
	       ntohl(tcph->ack_seq), flag_str, ntohs(tcph->window),
	       (unsigned int)(tcph->doff) * 4);
}
