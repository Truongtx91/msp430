/*
 * crc8.h
 *
 *  Created on: Sep 20, 2018
 *      Author: truongtx
 */

#ifndef CRC_CRC8_H_
#define CRC_CRC8_H_

////////////////////////////////////////// Include Files /////////////////////////////////////////////
#include "type.h"

///////////////////////////////////// Constant Definitions ///////////////////////////////////////////

/////////////////////////////////////// Type Definitions /////////////////////////////////////////////

///////////////////////////// Macros (Inline Functions) Definitions //////////////////////////////////
#define ByteCRC8(crc, ch)   (g_byCRC8Table[crc ^ ch])

///////////////////////////////////// Function Prototypes ////////////////////////////////////////////
uint8_t CalCRC8(const uint8_t *pBuff, int nSize);

///////////////////////////////////// Variable Definitions ///////////////////////////////////////////
extern const uint8_t g_byCRC8Table[];




#endif /* CRC_CRC8_H_ */