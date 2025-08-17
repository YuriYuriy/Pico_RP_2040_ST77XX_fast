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
#ifndef _ST77XX_GRAPH
#define _ST77XX_GRAPH

#include "st77xx.h"

//----------------------------------------------------------------------------------------------------
// Function lib
//----------------------------------------------------------------------------------------------------
void st77xx_clear_screen(uint16_t clear_color);
void st77xx_draw_rect(uint16_t rect_x0, uint16_t rect_y0, uint16_t rect_x1, uint16_t rect_y1, uint16_t rect_color);
void st77xx_draw_pixel(uint16_t pixel_x, uint16_t pixel_y, uint16_t pixel_color);
void st77xx_draw_line(uint16_t line_x0, uint16_t line_y0, uint16_t line_x1, uint16_t line_y1, uint16_t line_color);
void st77xx_draw_poly(uint8_t facets_poly, uint16_t radius_poly, uint16_t degree_poly, uint16_t facets_color_poly);
void st77xx_draw_circle(uint16_t radius_circle, uint16_t color_circle);
void st77xx_draw_heart(uint16_t heart_color);
void st77xx_draw_curveLissajous(uint16_t curveLissajous_color);
void st77xx_draw_img(uint16_t img_x0, uint16_t img_y0, uint16_t img_x1, uint16_t img_y1, uint16_t *img_buff);

#endif

