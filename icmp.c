#include <stdio.h>
#include <string.h>
#include <netinet/if_ether.h>
#include <netinet/ip_icmp.h>
#include "icmp.h"

void icmp_packet(char *buffer){
    struct iphdr *iph=(struct iphdr *)(buffer+sizeof(struct ethhdr));
    struct icmphdr *icmph=(struct icmphdr *)\
                         (buffer+sizeof(struct ethhdr)+(iph->ihl)*4);
    char type[50];
    memset(type,0,sizeof(type));

    switch ((unsigned int)(icmph->type)){
        case 0:
            strcpy(type,"echo reply");
            break;
        case 3:
            strcpy(type,"dest unreacahble");
            break;
        case 4:
            strcpy(type,"source quench");
            break;
        case 5:
            strcpy(type,"redirect");
            break;
        case 8:
            strcpy(type,"echo request");
            break;
        case 11:
            strcpy(type,"time exceeded");
            break;
        case 12:
            strcpy(type,"parameter unintelligible");
            break;
        case 13:
            strcpy(type,"time-stamp request");
            break;
        case 14:
            strcpy(type,"time-stamp reply");
            break;
        case 15:
            strcpy(type,"information request");
            break;
        case 16:
            strcpy(type,"information reply");
            break;
        case 17:
            strcpy(type,"address mask request");
            break;
        case 18:
            strcpy(type,"address mask reply");
            break;
    }
    printf("icmp     | type:%d-%s code:%d\n",(unsigned int)(icmph->type),\
                        type,(unsigned int)(icmph->code));
}
