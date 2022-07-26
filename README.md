Raw socket packet sniffer
--

### supported protocols ###

- ethernet
- ip
- icmp
- tcp
- udp

### you can use options to show only spesified protocols

    -e, for ethernet packets
    -c, for icmp packets
    -i, for ip packets
    -t, for tcp packets
    -u, for udp packets

### compile:
    make

### example usage:

    ./sniff -i -t (to listen only ip and tcp packets)
