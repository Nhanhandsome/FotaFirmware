/*
 * fota_event.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */

#ifndef FLASHFIRMWAREAPP_APP_FOTA_EVENT_H_
#define FLASHFIRMWAREAPP_APP_FOTA_EVENT_H_

#include "stdint.h"
#include "string.h"
#include "stdbool.h"

typedef enum{
	fota_no_message = 0,
	fota_new_message,
}fota_event_t;

typedef struct fota_event_queue_handle_t fota_event_queue_handle;

#define MAX_FOTA_EVENT_QUEUE 100

struct fota_event_queue_handle_t{
	fota_event_t buff[MAX_FOTA_EVENT_QUEUE];
	unsigned int size;
	volatile unsigned int tail;
	volatile unsigned int head;
	volatile unsigned int count;
};

void fota_event_creat(fota_event_queue_handle *p_fota_event);
bool fota_event_push_head(fota_event_queue_handle *p_fota_event, fota_event_t c);
bool fota_event_pop_tail(fota_event_queue_handle *p_fota_event, fota_event_t* data);




#endif /* FLASHFIRMWAREAPP_APP_FOTA_EVENT_H_ */
