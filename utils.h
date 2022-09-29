#ifndef UTILS_H
#define UTILS_H

#include "data_types.h"

#define START_BIT_MAX 32767
#define START_BIT_MIN 0
#define BIT_LENGTH_MAX 32767
#define BIT_LENGTH_MIN 1

void vGetBits(uint8_t * pu8Input, int16_t i16SizeOfInput, uint8_t * pu8Output, int16_t i16SizeOfOutput, int16_t i16StartBit, int16_t i16BitLen);

#endif