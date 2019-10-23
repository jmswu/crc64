#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "crc64.h"

#pragma pack(4)
typedef struct{
    uint32_t l_dword;
    uint32_t h_dword;
}two_dword_t;

typedef union{
    two_dword_t dword;
    uint64_t val;
}crc64_t;

int main()
{
    printf("Hello world! This is a crc64 test.\n");

    /* test string */
    uint8_t data[] = "Hello world, this is CRC64 test data!";

    /* calculate CRC64 */
    crc64_t crc64_data;
    crc64_data.val = crc64(data, sizeof(data)/sizeof(uint8_t) - 1);

    /* un-modified result of above string should be 0x53DE28BC101C444B */
    printf("CRC64 is: 0x%08X%08X\n", crc64_data.dword.h_dword, crc64_data.dword.l_dword);

    return 0;
}
