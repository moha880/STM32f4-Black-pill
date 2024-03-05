/*
 * TFT_int.h
 *
 *  Created on: Jun 9, 2023
 *      Author: Ibrahem
 */

#ifndef HAL_TFT_TFT_INT_H_
#define HAL_TFT_TFT_INT_H_









typedef struct
{
	u16 Blu:5;
	u16 Grn:6;
	u16 Red:5;
}Pixel_Color;

typedef union
{
	Pixel_Color pixel;
	u16         Color;
}Color_t;





void TFT_vInit(void);

void TFT_vShowImage(const u16 A_pu16Img[],u32 A_u32ImgSize);

void TFT_vSetXPos(u16 xStart, u16 xEnd);
void TFT_vSetYPos(u16 yStart, u16 yEnd);
void TFT_vFillRectangle(Color_t Color);
void TFT_vFillBackground(Color_t Color);


void TFT_vDrawLine(u16 x1, u16 y1,u16 x2, u16 y2);
void TFT_vRectangle(/*4 lines */);
void TFT_vTriangle(/*3 lines */);
void TFT_vCircle(u16 r, u16 centerX, u16 centerY);


#endif /* HAL_TFT_TFT_INT_H_ */
