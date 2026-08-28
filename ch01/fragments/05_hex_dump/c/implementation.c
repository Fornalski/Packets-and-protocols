#include<ctype.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<stdbool.h>


int main(void) {
uint8_t data[] = {
    'T', 'h','e',  ' ', 'q', 'u', 'i', 'c',
    'k', ' ', 'b', 'r', 'w', 'n', ' ',
    'f', 'o', 'x', ' ', 'j', 'u', 'm', 'p',
    's', ' ', 'o', 'v', 'e', 'r', '!', 0x01,
    0x43, 0xff, 0x7f, 0x01, 'U', 'L', 'U' , 'B', 'I', 'O', 'N', 'A'
};
    for(size_t i = 0; i < sizeof(data); i +=16){

        for( size_t j = 0; j < 16 && i + j < sizeof(data); j++){
            printf("%02x ", data[i + j]);
        }

        for( size_t j = 0; j < 16 && i + j < sizeof(data); j++){
            if(isprint((unsigned char)data[i+j])) {printf("%c", data[i + j]);}else{printf(".");}
        }
        printf("\n");
    }
return 0;
}