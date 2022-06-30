/*
 * debug.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */

#ifndef FLASHFIRMWAREAPP_SERVICE_DEBUG_H_
#define FLASHFIRMWAREAPP_SERVICE_DEBUG_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "config.h"
#include "string.h"

#define DEBUG(x,...) debug_printf(x,...)

//__weak void debug_printf(const char* format,...);

#ifdef DEBUG
void debug_printf(const char* format,...);
#endif


#endif /* FLASHFIRMWAREAPP_SERVICE_DEBUG_H_ */
