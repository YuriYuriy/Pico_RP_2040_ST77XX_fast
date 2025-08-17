//----------------------------------------------------------------------------------------------------
// Program to work with an SD card for Petit FatFS
// Copyright (C) 2025 YuriYuri (Yuriy Golovin)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//----------------------------------------------------------------------------------------------------
#ifndef _ST77XX
#define _ST77XX

#include "main.h"
#include "st77xx_graph.h"
#include "st77xx_fonts.h"
#include "st77xx_img.h"

//----------------------------------------------------------------------------------------------------
// Used screen driver
//----------------------------------------------------------------------------------------------------
//#define ST7735S
#define ST7789V

//----------------------------------------------------------------------------------------------------
// Used interface ST77XX
//----------------------------------------------------------------------------------------------------
#define ST77XX_USED_SPI
//#define ST77XX_USED_DMA

#define ST77XX_SIZE_BUFF_SREEN 128

//----------------------------------------------------------------------------------------------------
// Screen size
//----------------------------------------------------------------------------------------------------
#define ST77XX_X_OFFSET  0
#define ST77XX_Y_OFFSET  0
#define ST77XX_X_SIZE    240
#define ST77XX_Y_SIZE    320

//----------------------------------------------------------------------------------------------------
// Pins SPI ST77XX
//----------------------------------------------------------------------------------------------------
#define ST77XX_SPI_PORT  spi1
#define ST77XX_PIN_MISO  12
#define ST77XX_PIN_SCK   10
#define ST77XX_PIN_MOSI  11
#define ST77XX_PIN_CS    13
#define ST77XX_PIN_RST   15
#define ST77XX_PIN_DC    14
#define ST77XX_PIN_BLK   1

//----------------------------------------------------------------------------------------------------
// Frequncy SPI ST77XX
//----------------------------------------------------------------------------------------------------
#define ST77XX_FREQUNCY_SPI  125 * 1000 * 1000

//----------------------------------------------------------------------------------------------------
// CS data
//----------------------------------------------------------------------------------------------------
#define ST77XX_DC_DATA     true
#define ST77XX_DC_COMMAND  false

//----------------------------------------------------------------------------------------------------
// Colors ST77XX
//----------------------------------------------------------------------------------------------------
#define ST77XX_BLACK    0x0000
#define ST77XX_BLUE     0x001F
#define ST77XX_RED      0xF800
#define ST77XX_GREEN    0x07E0
#define ST77XX_CYAN     0x07FF
#define ST77XX_MAGENTA  0xF81F
#define ST77XX_YELLOW   0xFFE0
#define ST77XX_WHITE    0xFFFF

//----------------------------------------------------------------------------------------------------
// Function lib
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// Implemented only for Pico RP2040
// If you want to use a other microcontroller. This function need to be implemented
//----------------------------------------------------------------------------------------------------
//void st77xx_spi_init(void);
void st77xx_write(uint8_t *st77xx_data_buff, uint32_t st77xx_size_buff);
void st77xx_delay_ms(uint16_t st77xx_delay_ms);
//void st77xx_reset_hardware(void);
void st77xx_dc(bool st77xx_dc_data);

//----------------------------------------------------------------------------------------------------
// This function don't need to be implemented
//----------------------------------------------------------------------------------------------------
void st77xx_send_command(uint8_t st77xx_command);
void st77xx_send_data(uint8_t st77xx_data);
void st77xx_init(void);
void st77xx_set_col_row_addr(uint16_t st77xx_x_start, uint16_t st77xx_y_stasrt, uint16_t st77xx_x_stop, uint16_t st77xx_y_stop);


#endif
