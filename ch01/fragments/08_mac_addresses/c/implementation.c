#include <stdint.h>
#include<arpa/inet.h>
#include<stdio.h>
#include <stdio.h>
void byte_to_bits(uint8_t byte){
    for(int i = 7; i >=0; i--){
        printf("%d", (byte >> i) & 1);
    }
}

int main(void) {

uint32_t y = 0x12345678;
printf("The initial value: 0x%d", y);


uint8_t *p1 = (uint8_t *)&y;
printf("\nHost byte values for 0x12345678: \n");
for (int i = 0; i < sizeof(y); i++){
    printf("%02x ", p1[i]);
}
printf("\nNetwork byte values for 0x12345678: \n");

uint32_t nx = htonl(y);
uint8_t *p2 = (uint8_t *)&nx;
for (int i = 0; i < sizeof(nx); i++){
    printf("%02x ", p2[i] );
}

printf("\nInitial network value in binary:\n");
for (int i = 0; i < sizeof(y); i++){
    byte_to_bits(p2[i]);
    printf(" ");    
}


return 0;
}