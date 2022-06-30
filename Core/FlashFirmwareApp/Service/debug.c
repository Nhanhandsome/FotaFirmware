/*
 * debug.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */




#include "debug.h"

#ifdef DEBUG
#define default_buff_size 128
void debug_printf(const char* format,...){
	va_list args;
	char *buff = (char*) malloc(default_buff_size);
	memset(buff, 0, default_buff_size);
	va_start(args, format);
	vsprintf(buff, format, args);
	printf(buff);
	free(buff);
}
#endif
