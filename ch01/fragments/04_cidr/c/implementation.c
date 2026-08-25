#include<arpa/inet.h>
#include<stdio.h>

void print_in_bytes(uint32_t y){
    uint32_t z = htonl(y);
    uint8_t *p = (uint8_t *)&z;
    for(int i = 0; i < 4; i++){
        printf("%d.", p[i]);
    }printf("\n");
}

int main(void){
    const char input[] = "192.168.18.3/24";
    char IPv4_addr[INET_ADDRSTRLEN];
    int prefix;
    

    sscanf(input, "%15[^/]/%d", IPv4_addr, &prefix);
    if (prefix <= 0 || prefix >= 32){ printf("Error: Wrong prefix.");return 0;}
    int host_bits = 32 - prefix;

    uint32_t mask = 0xffffffff << (host_bits);

    struct in_addr addr; 
    if(inet_pton(AF_INET, IPv4_addr, &addr) != 1){printf(" IPv4_addr -> net_int failed"); return 0;}

    uint32_t ip = ntohl(addr.s_addr);

    uint32_t network = ip&mask;
    printf("Network: ");print_in_bytes(network);

    uint32_t broadcast = ip | ~mask;
    printf("Broadcast: ");print_in_bytes(broadcast);
    
    
    uint32_t first_addr = network + 1;
    uint32_t last_addr = broadcast - 1;

    printf("First usable: ");print_in_bytes(first_addr);
    printf("Last usable: ");print_in_bytes(last_addr);
    int addresses = 1ULL << host_bits;
    printf("Number of addresses: %d\n", addresses );
    printf("Number of usable addresses: %d", addresses -2 );
    return 0;  
}