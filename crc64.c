#include "crc64.h"

uint64_t crc64(uint8_t *data, uint16_t len){

    uint64_t crc64;     // crc64 result
    uint8_t i;

    /* initial CRC64 with initial value */
    crc64 = CRC64_INITIAL_VAL;

    /* calculate CRC64 */
    while(len--){

        uint64_t tmp;
        tmp = *data++;

        crc64 = crc64 ^ (tmp << 56);
        for( i = 0; i < 8; i++){
            if (crc64 & 0x8000000000000000){
                crc64 = (crc64 << 1) ^ CRC64_POLY;
            }else{
                crc64 = crc64 << 1;
            }
        }
    }

    /* do the final XOR */
    crc64 = crc64 ^ CRC64_FINAL_XOR_VAL;

    return crc64;
}
