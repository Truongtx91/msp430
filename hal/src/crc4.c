/*
 * crc4.c
 *
 *  Created on: Sep 20, 2018
 *      Author: truongtx
 */
////////////////////////////////////////// Include Files /////////////////////////////////////////////
#include "crc4.h"

///////////////////////////////////// Constant Definitions ///////////////////////////////////////////

/////////////////////////////////////// Type Definitions /////////////////////////////////////////////

///////////////////////////// Macros (Inline Functions) Definitions //////////////////////////////////

///////////////////////////////////// Function Prototypes ////////////////////////////////////////////

///////////////////////////////////// Variable Definitions ///////////////////////////////////////////
const uint8_t g_ucCRC4Table[16] =
{
    0b0000, 0b0011, 0b0110, 0b0101,
    0b1100, 0b1111, 0b1010, 0b1001,
    0b1011, 0b1000, 0b1101, 0b1110,
    0b0111, 0b0100, 0b0001, 0b0010
};

///////////////////////////////////// Function implements ////////////////////////////////////////////

// ---------------------------------------------------------------------------------------------------
//  @brief  :   Calculate 4 bit CRC
//
//  @param  :   None
//  @return :   void
//  @note   :
// ---------------------------------------------------------------------------------------------------
unsigned char CalculateCRC4(const unsigned char* pucData, unsigned char ucDataLength)
{
    unsigned char i;
    unsigned char ucCRC = 0;

    for(i = 0; i < ucDataLength; i++)
    {
        ucCRC ^= GetCRC4Table(pucData[i]);
    }

    return ucCRC;
}



