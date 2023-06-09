/*
 * Console.h
 *
 *  Created on: 28 Mar 2020
 *      Author: stefanosperett
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <driverlib.h>
#include <stdarg.h>

extern "C" {
#include<string.h>
}

class Console
{
private:
    static unsigned int baudrate;

    // Private constructor to prevent instancing.
    Console();
    static char* itoa(char* str, uint32_t val, uint8_t base );
    static void log_insert( const char *text );

public:
    static bool isEnabled();
    static void init( unsigned int baudrate );
    static void log( const char *text, ... );
    static void log( void );
    static void flush( void );

};

#endif /* CONSOLE_H_ */
