/*
 * fota.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */

#ifndef APP_FOTA_H_
#define APP_FOTA_H_

#include "fota_struct.h"
#include "ringbuffer.h"
#include "fota_event.h"



typedef struct fota_class_t fota_class;
struct fota_class_t{
	uint8_t last_data;
	uint8_t is_push_fifo;
	fota_event_queue_handle event;
	Ring_Buffer_t fota_fifo;
	FOTA_STATUS_t status;
	fota_cmd commands;
	int (*poll)(fota_class *p_fota);
	uint8_t (*process)(fota_class *p_fota,uint8_t* data,uint16_t length);
	void (*set_satus)(fota_class *p_fota,FOTA_STATUS_t status);
	FOTA_STATUS_t (*get_status)(fota_class *p_fota);
};
void fota_init(fota_class *p_fota);
int fota_poll(fota_class *p_fota);
extern void fota_data_is_comming(fota_class *p_fota,uint8_t data);

extern fota_class fota;

#endif /* APP_FOTA_H_ */
