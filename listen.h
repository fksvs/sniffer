#ifndef LISTEN
#define LISTEN

#define BUFF_SIZE 65535

#define ETH_FLAG 1
#define ICMP_FLAG 2
#define IP_FLAG 4
#define TCP_FLAG 8
#define UDP_FLAG 16
#define ALL 31

void output(char *buffer, int flag);
int listen_data(int sockfd, int flag);
int init_socket();

#endif
