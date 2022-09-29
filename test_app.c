#include <stdio.h>
#include "utils.h"

/*
Descripiton:
 A simple test application that will demonstrate the usage of the implemented vGetBits function with at least the following test examples:
* Input: UNSIGNED16 variable 0xBA98, StartBit = 3, BitLen = 5, Output: UNSIGNED8 variable. Expected Output value = 0x13.
* Input: UNSIGNED16 array with two items {0x9876, 0xDCBA}, StartBit = 0, BitLen = 30, Output: UNSIGNED32 variable. Expected Output value = 0x1CBA9876.
* Input: UNSIGNED32 variable 0xFEDCBA98, StartBit = 18, BitLen = 12, Output: UNSIGNED8 array with two items. Expected Output value = {0xB7, 0x0F}
* Input: UNSIGNED8 array with three items {0x98, 0xBA, 0xDC}, StartBit = 1, BitLen = 20, Output: UNSIGNED16 array with two items. Expected Output value = {0x5D4C, 0xE}.
* 
* TODO: make test cases more generic
*/


uint8_t * g_pu8Input;
uint8_t * g_pu8Output;
uint16_t g_i16SizeOfInput;
uint16_t g_i16SizeOfOutput;
uint16_t g_i16StartBit;
uint16_t g_i16BitLen;

void vTest1(uint8_t u8Index);    
void vTest2(uint8_t u8Index);   
void vTest3(uint8_t u8Index);
void vTest4(uint8_t u8Index);    

int main(void)
{
    vTest1(1);
    vTest2(2);
    vTest3(3);
    vTest4(4);

    return 0;
}

void vTest1(uint8_t u8Index)
{
    uint16_t u16InputData;
    uint8_t u8OutputData;

    printf("Test %d started \n", u8Index);
    u16InputData = 0xBA98;
    g_i16StartBit = 3;
    g_i16BitLen = 5;
    g_pu8Input = (uint8_t *)&u16InputData;
    g_i16SizeOfInput = (uint16_t)(sizeof(u16InputData));
    g_pu8Output = (uint8_t *)&u8OutputData;
    g_i16SizeOfOutput = (uint16_t)(sizeof(u8OutputData));

    vGetBits(g_pu8Input, g_i16SizeOfInput, g_pu8Output, g_i16SizeOfOutput, g_i16StartBit, g_i16BitLen);
    if (0x13 == u8OutputData)
    {
        printf("Test %d passed \n", u8Index);   
    }
    else
    {
        printf("Test %d failed \n", u8Index);
    }
     printf("---------------------------\n");
}

void vTest2(uint8_t u8Index)
{
    uint16_t au16InputData[2];
    uint32_t u32OutputData;

    printf("Test %d started \n", u8Index);
    au16InputData[0] = 0x9876;
    au16InputData[1] = 0xDCBA;
    g_i16StartBit = 0;
    g_i16BitLen = 30;
    g_pu8Input = (uint8_t *)&au16InputData[0];
    g_i16SizeOfInput = (uint16_t)(sizeof(au16InputData));
    g_pu8Output = (uint8_t *)&u32OutputData;
    g_i16SizeOfOutput = (uint16_t)(sizeof(u32OutputData));

    vGetBits(g_pu8Input, g_i16SizeOfInput, g_pu8Output, g_i16SizeOfOutput, g_i16StartBit, g_i16BitLen);
    if (0x1CBA9876 == u32OutputData)
    {
        printf("Test %d passed \n", u8Index);   
    }
    else
    {
        printf("Test %d failed \n", u8Index);
    }
    printf("---------------------------\n");
}

void vTest3(uint8_t u8Index)
{
    uint32_t u32InputData;
    uint8_t au8OutputData[2];

    printf("Test %d started \n", u8Index);
    u32InputData = 0xFEDCBA98;
    g_i16StartBit = 18;
    g_i16BitLen = 12;
    g_pu8Input = (uint8_t *)&u32InputData;
    g_i16SizeOfInput = (uint16_t)(sizeof(u32InputData));
    g_pu8Output = (uint8_t *)&au8OutputData[0];
    g_i16SizeOfOutput = (uint16_t)(sizeof(au8OutputData));

    vGetBits(g_pu8Input, g_i16SizeOfInput, g_pu8Output, g_i16SizeOfOutput, g_i16StartBit, g_i16BitLen);
    if ((0xB7 == au8OutputData[0]) && (0x0F == au8OutputData[1])) 
    {
        printf("Test %d passed \n", u8Index);   
    }
    else
    {
        printf("Test %d failed \n", u8Index);
    }
    printf("---------------------------\n");
}

void vTest4(uint8_t u8Index)
{
    uint8_t au8InputData[3];
    uint16_t au16OutputData[2];

    printf("Test %d started \n", u8Index);
    au8InputData[0] = 0x98;
    au8InputData[1] = 0xBA;
    au8InputData[2] = 0xDC;
    g_i16StartBit = 1;
    g_i16BitLen = 20;
    g_pu8Input = (uint8_t *)&au8InputData[0];
    g_i16SizeOfInput = (uint16_t)(sizeof(au8InputData));
    g_pu8Output = (uint8_t *)&au16OutputData[0];
    g_i16SizeOfOutput = (uint16_t)(sizeof(au16OutputData));

    vGetBits(g_pu8Input, g_i16SizeOfInput, g_pu8Output, g_i16SizeOfOutput, g_i16StartBit, g_i16BitLen);
    if ((0x5D4C == au16OutputData[0]) && (0x0E == au16OutputData[1])) 
    {
        printf("Test %d passed \n", u8Index);   
    }
    else
    {
        printf("Test %d failed \n", u8Index);
    }
    printf("---------------------------\n");
}
