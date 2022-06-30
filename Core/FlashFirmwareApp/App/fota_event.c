/*
 * fota_event.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Admin
 */



#include "fota_event.h"


void fota_event_creat(fota_event_queue_handle *p_fota_event){
	memset(p_fota_event->buff,fota_no_message,MAX_FOTA_EVENT_QUEUE);
	p_fota_event->head = 0;
	p_fota_event->tail = 0;
	p_fota_event->count = 0;
	p_fota_event->size = MAX_FOTA_EVENT_QUEUE;
}
bool fota_event_push_head(fota_event_queue_handle *p_fota_event, fota_event_t c){
	unsigned int next = (unsigned int) (p_fota_event->head + 1) % p_fota_event->size;
	if (next != p_fota_event->tail) {
		p_fota_event->buff[p_fota_event->head] = c;
		p_fota_event->head = next;
		p_fota_event->count += 1;
		return true;
	}
	return false;
}
bool fota_event_pop_tail(fota_event_queue_handle *p_fota_event, fota_event_t* data){
	if (p_fota_event->head != p_fota_event->tail) {
		data[0] = p_fota_event->buff[p_fota_event->tail];
		p_fota_event->tail = (unsigned int) (p_fota_event->tail + 1) % p_fota_event->size;
		p_fota_event->count -= 1;
		return true;
	}
	return false;
}
