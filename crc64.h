#ifndef CRC64_H_INCLUDED
#define CRC64_H_INCLUDED

#include <stdint.h>

#define CRC64_INITIAL_VAL   0xFFFFFFFFFFFFFFFF
#define CRC64_FINAL_XOR_VAL 0xFFFFFFFFFFFFFFFF


#define CRC64_POLY_ECMA_182     0x42F0E1EBA9EA3693
#define CRC64_POLY_GO_ISO       0x000000000000001B
#define CRC64_POLY_WE           0x42F0E1EBA9EA3693
#define CRC64_POLY_XZ           0x42F0E1EBA9EA3693

/* choose one from above */
#define CRC64_POLY              CRC64_POLY_ECMA_182


/* calculate CRC64 value
 *
 * @param uint8_t *data - input data
 * @param uint16_t len - the size of the data in bytes
 * @return - calculated crc64 value
 *
 */
uint64_t crc64(uint8_t *data, uint16_t len);


#endif // CRC64_H_INCLUDED
