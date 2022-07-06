/*
 * flash_firmware.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Admin
 */

#include <config.h>
#include <flash_firmware.h>
#include "ringbuffer.h"
#include "fota.h"
Ring_Buffer_t firmware_buffer;

uint16_t firmware_size = 1024;

uint8_t check_new_firmware() {
	uint32_t check_firmware = flash_read(FIRMWARE_AVAILABLE_ADDR);
	if(check_firmware == (uint32_t)0x01){
		return 1; // firmware available
	}
	else if(check_firmware == (uint32_t)0x02){
		return 2;
	}

	return 0;
}
void flash_firmware_process() {
	if (check_new_firmware() == 1) {
		fota_init(&fota);
		int result = fota_poll(&fota);
		if(result == 2){
			checkout_firmware(app_firmware);
		}
		else if(result == -1){
			checkout_firmware(factory_firmware);
		}
	}
	else if(check_new_firmware() == 2){
		checkout_firmware(factory_firmware);
	}
	checkout_firmware(app_firmware);
}
void checkout_firmware(firmware_type_t firmware) {
	switch (firmware) {
	case bootloader_firmware:
		jump_app(BOOTLOADER_ADDR);
		break;
	case flash_firmware:
		jump_app(FLASH_FIRMWARE_ADDR);
		break;
	case app_firmware:
		jump_app(APP_FIRMWARE_ADDR);
		break;
	case factory_firmware:
		jump_app(FACTORY_FIRMWARE_ADDR);
		break;
	default:
		break;
	}
}

