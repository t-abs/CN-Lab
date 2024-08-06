#include <stdio.h>

int check_endianness() {
    unsigned int x = 1;
    char *c = (char *)&x;
    return (int)*c;
}

void print_bytes(unsigned int num) {
    unsigned char *byte = (unsigned char *)&num;
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: %02x\n", i, byte[i]);
    }
}

unsigned int convert_endianness(unsigned int num) {
    unsigned int b0, b1, b2, b3;
    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;
    return (b0 | b1 | b2 | b3);
}

int main() {
    if (check_endianness()) {
        printf("Host machine is Little Endian\n");
    } else {
        printf("Host machine is Big Endian\n");
    }
    unsigned int num=0x11223344;
    printf("Bytes of the original number:\n");
    print_bytes(num);
    unsigned int converted_num = convert_endianness(num);
    printf("Bytes of the converted number:\n");
    print_bytes(converted_num);
    return 0;
}