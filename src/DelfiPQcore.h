/*
 * DelfiPQcore.h
 *
 *  Created on: 26 Aug 2019
 *      Author: stefanosperett
 */

#ifndef DELFIPQCORE_H_
#define DELFIPQCORE_H_

#include <driverlib.h>
#include "msp.h"

#define FCLOCK 48000000
#define SCLOCK 32768

class DelfiPQcore
{
public:
    static void initMCU( void );
    static bool getHFOscillatorStatus( void );
    static bool getLFOscillatorStatus( void );
};

#endif /* DELFIPQCORE_H_ */
