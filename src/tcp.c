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

	printf("tcp      | ");
	printf("%d", ntohs(tcph->source));
	printf(" --> ");
	printf("%d ", ntohs(tcph->dest));
	printf("seq:%u ", ntohl(tcph->seq));
	printf("ack:%u ", ntohl(tcph->ack_seq));
	printf("flag:%s ", flag_str);
	printf("win:%d ", ntohs(tcph->window));
	printf("len:%d\n", (tcph->doff) * 4);
}
