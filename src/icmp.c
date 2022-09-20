#include <stdio.h>
#include <string.h>
#include <netinet/if_ether.h>
#include <netinet/ip_icmp.h>
#include "icmp.h"

void icmp_packet(char *buffer)
{
	struct iphdr *iph = (struct iphdr *)(buffer + sizeof(struct ethhdr));
	struct icmphdr *icmph = (struct icmphdr *)
		(buffer + sizeof(struct ethhdr) + (iph->ihl) * 4);
	char type_str[50];
	memset(type_str, 0, 50);

        if (icmph->type == 0) strcpy(type_str, "echo reply");
        if (icmph->type == 3) strcpy(type_str, "destination unreachable");
        if (icmph->type == 4) strcpy(type_str, "source quench");
        if (icmph->type == 5) strcpy(type_str, "redirect");
        if (icmph->type == 8) strcpy(type_str, "echo request");
        if (icmph->type == 11) strcpy(type_str, "time exceeded");
        if (icmph->type == 12) strcpy(type_str, "parameter unintelligible");
        if (icmph->type == 13) strcpy(type_str, "time-stamp request");
        if (icmph->type == 14) strcpy(type_str, "time-stamp reply");
        if (icmph->type == 15) strcpy(type_str, "information request");
        if (icmph->type == 16) strcpy(type_str, "information reply");
        if (icmph->type == 17) strcpy(type_str, "address mask request");
        if (icmph->type == 18) strcpy(type_str, "address mask reply");

	printf("icmp     | type:%d-%s code:%d\n", (unsigned int)(icmph->type),
	       type_str, (unsigned int)(icmph->code));
}
