/*
 * fota.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */

#ifndef APP_FOTA_H_
#define APP_FOTA_H_

#include "fota_struct.h"

typedef struct fota_class_t fota_class;
struct fota_class_t{
	FOTA_STATUS_t status;
	fota_cmd commands;
	void (*poll)(fota_class *p_fota);
	uint8_t (*process)(fota_class *p_fota,uint8_t* data,uint16_t length);
	void (*set_satus)(fota_class *p_fota,FOTA_STATUS_t status);
	FOTA_STATUS_t (*get_status)(fota_class *p_fota);
};

extern fota_class fota;

#endif /* APP_FOTA_H_ */
