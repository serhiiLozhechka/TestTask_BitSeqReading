#include <stdio.h>
#include "utils.h"

void utils_vPrintDebug(uint8_t * pu8Data, int16_t i16SizeOfData);

/*
 Description: 
 The function is reading a sequence of bits from provided input and returning them to the provided output.
 TODO: set error code
 TODO: use const for pointers
*/
void vGetBits(uint8_t * pu8Input, int16_t i16SizeOfInput, uint8_t * pu8Output, int16_t i16SizeOfOutput, int16_t i16StartBit, int16_t i16BitLen)
{
    int16_t i16StartByte = (i16StartBit >> 3);
    int16_t i16BytesLen  = ((i16BitLen + 7) >> 3);
    int16_t i16Index = 0;
    int16_t i16BitOffset = (i16StartBit & 7);

    if (pu8Input == NULL)                                   { return; }
    if (i16SizeOfInput <= 0)                                { return; }
    if (pu8Output == NULL)                                  { return; }    
    if (i16SizeOfOutput <= 0)                               { return; }    
    if (i16BitLen <= 0)                                     { return; }
    if (i16StartBit < 0)                                    { return; }     
    if (i16BytesLen > i16SizeOfInput)                       { return; } 
    if ((i16BytesLen + i16StartByte) > i16SizeOfInput)      { return; }
    if (i16BytesLen > i16SizeOfOutput)                      { return; }

    for(i16Index = 0; i16Index < i16BytesLen; i16Index++)
    {
        pu8Output[i16Index]  = (pu8Input[i16StartByte + i16Index] >> i16BitOffset);
        pu8Output[i16Index] |= (pu8Input[i16StartByte + i16Index + 1] << (8 - i16BitOffset));
    }
    pu8Output[i16Index - 1] &= 0xff >> (7 - ((i16BitLen - 1) & 7));
    printf("    Input data: \n");
    utils_vPrintDebug(pu8Input,  i16SizeOfInput);
    printf("    Output data: \n");
    utils_vPrintDebug(pu8Output, i16SizeOfOutput);
}

void utils_vPrintDebug(uint8_t * pu8Data, int16_t i16SizeOfData)
{
    int16_t i16Index = 0;

    printf("0x");
    for(i16Index = 0; i16Index < i16SizeOfData; i16Index++)
    {
        printf("%02X", pu8Data[i16Index]);
    }
    printf("\n"); 
}