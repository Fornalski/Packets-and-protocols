#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int hex_value(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;

    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;

    return -1;
}

int parse_mac(const char *str, uint8_t mac[6])
{
    for (int i = 0; i < 6; i++) {

        int high = hex_value(str[i * 3]);
        int low  = hex_value(str[i * 3 + 1]);

        if (high == -1 || low == -1)
            return 0;

        mac[i] = (high << 4) | low;

        if (i < 5 && str[i * 3 + 2] != ':')
            return 0;
    }

    return str[17] == '\0';
}

int main(void){
    uint8_t mac[6];

if (parse_mac("00:1A:2B:3C:4D:5E", mac)) {
    printf("Success\n");
}

return 0;
}