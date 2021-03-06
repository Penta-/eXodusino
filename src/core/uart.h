#ifndef UART_H_
#define UART_H_

/**************************************************************************//**
 * @file uart.h
 * @brief Arduino-like library for MARY(LPC1114)
 * @version v.0.50
 * @date 1. August 2011.
 * @author @@lynxeyed_atsu
 * @note Copyright (c) 2011 Lynx-EyED's Klavier and Craft-works. <BR>
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions: <BR>
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.<BR>
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

#include <lpcdevice.h>
#include "Print.h"

#include <uart_middle.h>

#ifdef __cplusplus
extern "C" {
#endif



class USerial: public Print {
private:
	SERIAL_PORT port;
	//RADIX_FORMAT format;
	int speed;

public:
	USerial();//USerial(SERIAL_PORT port); // announce the constructor to initialize
	~USerial();

	void begin(int speed);
	void end();
	int read(void);
	int available(void);
	virtual void write(const char c);
	using Print::write; // pull in write(buf, size) from Print

};

extern USerial Serial;

#ifdef __cplusplus
}
#endif

#endif /* UART_H_ */
