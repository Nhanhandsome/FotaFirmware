/*
 * flash_hw.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Admin
 */




#include "flash_hw.h"

#define PAGE_ADDR_BEGIN (uint32_t)0x800c000

uint8_t flash_hw_erase(uint32_t page_or_sector_addr, uint32_t nb_page_or_sector){
	FLASH_EraseInitTypeDef flash_erase;
	flash_erase.PageAddress = page_or_sector_addr;
	flash_erase.NbPages = nb_page_or_sector;
	flash_erase.TypeErase =  FLASH_TYPEERASE_PAGES;
	uint32_t page_error;
	if(HAL_FLASHEx_Erase(&flash_erase,&page_error) == HAL_OK){
		return 1;
	}
	return 0;
}
uint32_t flash_hw_read(uint32_t addr){
	return *(__IO uint32_t *)(addr);
}
void flash_hw_write(uint32_t addr,uint32_t data){
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,addr, data);
}
void flash_hw_unlock(void){
	HAL_FLASH_Unlock();
}
void flash_hw_lock(void){
	HAL_FLASH_Lock();
}
void jump_hw_app(uint32_t addr){
	HAL_RCC_DeInit();
	HAL_DeInit();
	//SCB->SHCSR &= ~( SCB_SHCSR_USGFAULTENA_Msk |SCB_SHCSR_BUSFAULTENA_Msk |SCB_SHCSR_MEMFAULTENA_Msk ) ;
	__set_MSP(*((volatile uint32_t*) addr));
	uint32_t JumpAddress = *((volatile uint32_t*) (addr + 4));
	void (*reset_handler)(void) = (void*)JumpAddress;
	reset_handler();
}
