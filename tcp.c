#include <stdio.h>
#include <string.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "tcp.h"

void tcp_header(char *buffer){
    struct iphdr *iph=(struct iphdr *)(buffer+sizeof(struct ethhdr));
    struct tcphdr *tcph=(struct tcphdr *)\
                        (buffer+sizeof(struct ethhdr)+(iph->ihl)*4);
    char tcp_flag[50];
    memset(tcp_flag,0,sizeof(tcp_flag));

    if ((unsigned int)(tcph->urg)==1)
        strcat(tcp_flag,"urg,");
    if ((unsigned int)(tcph->ack)==1)
        strcat(tcp_flag,"ack,");
    if ((unsigned int)(tcph->rst)==1)
        strcat(tcp_flag,"rst,");
    if ((unsigned int)(tcph->psh)==1)
        strcat(tcp_flag,"psh,");
    if ((unsigned int)(tcph->syn)==1)
        strcat(tcp_flag,"syn,");
    if ((unsigned int)(tcph->fin)==1)
        strcat(tcp_flag,"fin,");

    printf("tcp      | %d --> %d seq:%u ack:%u flag:%s win:%d len:%d\n",\
            ntohs(tcph->source),ntohs(tcph->dest),\
            ntohl(tcph->seq),ntohl(tcph->ack_seq),tcp_flag,\
            ntohs(tcph->window),(unsigned int)(tcph->doff)*4);
}
