#include <stdio.h>
#include "utils.h"

//TODO: use const for pointers


/*
 * Description: 
 * The function is reading a sequence of bits from provided input and returning them to the provided output.
 * Input: uint8_t * pu8Input is pointer to input data
 * Input: int16_t i16SizeOfInput is size of input data in bytes
 * Input/Output: uint8_t * pu8Output is pointer to output data
 * Input: int16_t i16SizeOfOutput is size of output data  in bytes
 * Input: int16_t i16StartBit specifies the position of a first bit in the Input from which the bit sequence shall be read. 
 *                            0 = lowest significant bit in the Input. StartBit should support range 0 - 32767.
 * Input: int16_t i16BitLen specifies the number of bits that shall be read counting from the start bit. BitLen should support range 1 - 32767.
 * 
 * Return: void
 * 
 * TODO: set error code
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

/*
 * Description:
 * Print binary and hex values of test input and output values into console to provide additional test information.
 *
 * Input: uint8_t * pu8Data is pointer to input data
 * Input: int16_t i16SizeOfData is size of input data in bytes
 * 
 * Return: void
 *
 * TODO: set error code
 */ 
void utils_vPrintDebug(uint8_t * pu8Data, int16_t i16SizeOfData)
{
    int16_t i16ByteIndex = 0;
    int16_t i16BitIndex = 0;    

    if (pu8Data == NULL) { return; }

    printf("0x ");
    for(i16ByteIndex = 0; i16ByteIndex < i16SizeOfData; i16ByteIndex++)
    {
        printf("%02X", pu8Data[i16ByteIndex]);
    }
    printf("\n");

    printf("0B ");
    for(i16ByteIndex = 0; i16ByteIndex < i16SizeOfData; i16ByteIndex++)
    {
        for(i16BitIndex = 0; i16BitIndex < 8; i16BitIndex++)
        {
            if (pu8Data[i16ByteIndex] & (1 << (7 - i16BitIndex)))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("|");
    }
    printf("\n"); 
} 
