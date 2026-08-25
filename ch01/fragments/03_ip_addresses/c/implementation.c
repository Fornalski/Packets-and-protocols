
#include<arpa/inet.h>
#include<stdio.h>


void to_bits(uint8_t byte){
    for(int i = 7; i >= 0; i--){
        printf("%d", (byte >> i) & 1);
    }printf(" ");
}

int main(void) {
const char ip_str[] = "192.168.1.51";
char result[INET_ADDRSTRLEN];

struct in_addr addr;

printf("Starting address: %s\n", ip_str);
if(inet_pton(AF_INET, ip_str , &addr) == 1){
    printf("inet_pton conversion success\n");}else{
        printf("inet_pton conversion failed\n");
    }


if(inet_ntop(AF_INET, &addr, result, INET_ADDRSTRLEN)){
    printf("inet_ntop conversion success\n");}else{
        printf("inet_ntop conversion failed\n");
    }


uint8_t *p = (uint8_t *)&addr;
printf("Result: ");
for (int i = 0; i < 4; i++)
{
    to_bits(p[i]);
}
printf("\nResult: %s\n", result);
return 0;


}
