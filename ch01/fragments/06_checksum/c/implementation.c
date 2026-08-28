
#include<arpa/inet.h>
#include<stdio.h>

uint16_t calculate_checksum(uint8_t *data, size_t len){
    u_int32_t sum = 0;
    for(size_t i = 0; i < len; i+=2){
        sum += ((uint16_t) data[i] << 8) + data[i +1];

     /*   printf("%02x %02x\n", data[i], data[i+1]);
        printf("Current sum: %08x\n", sum);*/
    }
    while(sum >> 16){
        sum = (sum & 0xffff) + (sum >> 16);
    }
    u_int16_t checksum = ~sum;
    return checksum;
}

int main(void) {
uint8_t data[] = "The quick brown fox jumps over the lazy dog";
size_t len = sizeof(data);

printf("Expected: 0x72A4\n");
printf("Calculated: 0x%04X\n", calculate_checksum(data, len));


return 0;
}