/*
 * fota_struct.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */

#ifndef SERVICE_FOTA_STRUCT_H_
#define SERVICE_FOTA_STRUCT_H_

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "utils.h"

typedef struct fota_cmd_t fota_cmd;

struct fota_cmd_t{
	uint8_t header;
	haftword_to_byte_t byte_count;
	haftword_to_byte_t checksum;
	uint8_t commands;
	uint8_t *data;
};

typedef enum{
	FOTA_ST_IDLE = 0,
	FOTA_ST_BEGIN,
	FOTA_ST_PROCESS,
	FOTA_ST_SUCCESS,
	FOTA_ST_END,
}FOTA_STATUS_t;
typedef enum{
	FOTA_GET_VERSION = 0,
	FOTA_START,
	FOTA_WRITE,
	FOTA_SUCCESS,
	FOTA_ERROR
}FOTA_COMMANDS_t;

#define FOTA_HEAD 0x7E


#endif /* SERVICE_FOTA_STRUCT_H_ */
