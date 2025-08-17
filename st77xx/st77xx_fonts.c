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
#include "st77xx_fonts.h"

void st77xx_print_symbol(uint8_t symbol_x, uint8_t symbol_y, uint16_t symbol, uint16_t color_symbol, uint16_t color_background_symbol)
{
  uint16_t shift_symbol;

  switch ((symbol >> 8))
  {
  case 0xD0:
    shift_symbol = 0xD090 - 94;
    break;
  case 0xD1:
    shift_symbol = 0xD180 - 94 - 48;
    break;
  default:
    shift_symbol = 0x21;
    break;
  }

  st77xx_set_col_row_addr(symbol_x, symbol_y, symbol_x + 7 - 1, symbol_y + 10 - 1);

  uint8_t buff_symbol[140];

  for (uint8_t i = 0; i < 10; i++)
  {
    for (uint8_t j = 0; j < 7; j++)
    {
      uint16_t index_pixel = 2 * (i * 7 + j);
      if ((fonts_7x10[(symbol - shift_symbol) * 10 + i] << j) & 0x80)
      {
    	  buff_symbol[index_pixel] = color_symbol >> 8;
        buff_symbol[index_pixel + 1] = color_symbol;
      }
      else
      {
        buff_symbol[index_pixel] = color_background_symbol >> 8;
        buff_symbol[index_pixel + 1] = color_background_symbol;
      }
    }
  }
  st77xx_write(buff_symbol, 140);
  /*
  uint8_t color_symbol_buff[2];
  color_symbol_buff[0] = color_symbol >> 8;
  color_symbol_buff[1] = color_symbol;

  uint8_t color_background_symbol_buff[2];
  color_background_symbol_buff[0] = color_background_symbol >> 8;
  color_background_symbol_buff[1] = color_background_symbol;

  for (uint8_t i = 0; i < 10; i++)
  {  
    for (uint8_t j = 0; j < 7; j++)
    {

      if ((fonts_7x10[(symbol - shift_symbol) * 10 + i] << j) & 0x80)
      {
        st77xx_write(color_symbol_buff, 2);
      }
      else
      {
        st77xx_write(color_background_symbol_buff, 2);
      }
    }
  }
  */
}
void st77xx_print_line(uint8_t line_x, uint8_t line_y, unsigned char *line, uint16_t color_line, uint16_t color_background_line)
{
  uint16_t symbol_line;
  uint16_t i = 0;

  while (line[i])
  {
    if (line[i] == 0x20)
    {
      i += 1;
      line_x += 7;
    }
    else
    {
      if (line[i] >= 0x20 && line[i] <= 0x7E)
      {
        symbol_line = line[i];
        i += 1;
      }
      else
      {
        symbol_line = line[i];
        symbol_line = (symbol_line << 8) + line[i + 1];
        i += 2;
      }
      st77xx_print_symbol(line_x, line_y, symbol_line, color_line, color_background_line);
      line_x += 7;
    }
  }
}
