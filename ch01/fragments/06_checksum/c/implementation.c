
#include<stdint.h>
#include<stdio.h>

uint16_t calculate_checksum(uint8_t *data, size_t len)
{
    uint32_t sum = 0;

    for (size_t i = 0; i + 1 < len; i += 2) {
        sum += ((uint16_t)data[i] << 8) | data[i + 1];}

    if (len % 2 != 0) {
        sum += (uint16_t)data[len - 1] << 8;}

    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);}

    return (uint16_t)~sum;
}
int main(void) {
uint8_t data[] = "The quick brown fox jumps over the lazy dog";
size_t len = sizeof(data);

printf("Expected: 0x72A4\n");
printf("Calculated: 0x%04X\n", calculate_checksum(data, len));


return 0;
}