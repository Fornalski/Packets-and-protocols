#include <stdint.h>
#include <arpa/inet.h>
#include <stdio.h>

void bit_representation(uint8_t byte)
{
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }

    printf(" ");
}

void byte_representation(uint32_t *y)
{
    uint8_t *p1 = (uint8_t *)y;

    for (size_t i = 0; i < sizeof(*y); i++) {
        printf("%02x ", p1[i]);
    }
}

void bit(uint8_t *p1, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        bit_representation(p1[i]);
    }
}

void to_binary(int y)
{
    int i = 0;
    int bin_number[32];

    while (y > 0) {
        bin_number[i] = y % 2;
        y = y / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin_number[j]);
    }
}

int main(void)
{
    uint32_t y = 255;

    printf("input: %d\n", y);

    printf("Stored internally: uint32_t number %d\n", y);

    printf("Hexadecimal: %x\n", y);

    printf("Decimal: %d\n", y);

    printf("Octal: %o\n", y);

    printf("Binary: ");
    to_binary(y);

    printf("\nHost memory hexadecimal: ");
    byte_representation(&y);

    printf("\nNetwork memory hexadecimal: ");
    uint32_t network_y = htonl(y);
    byte_representation(&network_y);

    printf("\nHost memory binary: ");
    bit((uint8_t *)&y, sizeof(y));

    printf("\nNetwork memory binary: ");
    bit((uint8_t *)&network_y, sizeof(network_y));

    return 0;
}