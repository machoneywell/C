#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

uint8_t gencrc(uint8_t *data, size_t len)
{
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ 0x31);
            else
                crc <<= 1;
        }
    }
    return crc;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];
    file = fopen(argv[1], "r");

    size_t bytes = fread(buffer, sizeof(char), 1023, file);
    buffer[bytes] = '\0';

    printf("%s \ncrc=%d\n", buffer, gencrc((uint8_t *)&buffer, strlen(buffer)));
    fclose(file);

    return 0;
}