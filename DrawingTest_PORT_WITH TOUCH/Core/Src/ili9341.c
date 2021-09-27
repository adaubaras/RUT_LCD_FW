/*
 * ili9341.c
 *
 *  Created on: 2019/12/26
 *      Author: Kotetsu Yamamoto
 *      Copyright [Kotetsu Yamamoto]

I refer https://github.com/dtnghia2206/TFTLCD/blob/master/TFTLCD/ILI9341/ILI9341_Driver.c

from Original source:

MIT License

Copyright (c) 2019 NghiaDT

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

 */

#include <ili9341.h>
#include "main.h" // Hardware setting
#include "rgb.c"
// This function is for compatible HiLetgo ILI9341

typedef enum {
	ROTATE_0,
	ROTATE_90,
	ROTATE_180,
	ROTATE_270
} LCD_Horizontal_t;

typedef struct {
	uint16_t width;
	uint16_t height;
} LCD_Window_t;

extern void Error_Handler(void);
extern SPI_HandleTypeDef hspi1;

//static LCD_Window_t lcd_window;

void ILI9341_Reset(void);
void ILI9341_SoftReset(void);

static void LCD_WR_REG(uint8_t data);
static void LCD_WR_DATA(uint8_t data);
static void LCD_direction(LCD_Horizontal_t direction);
static void RESET_L(void);
static void RESET_H(void);
static void CS_L(void);
static void DC_L(void);
static void DC_H(void);
static void LED_H(void);

// Initialization
void ILI9341_Init(void)
{
	ILI9341_Reset();

	ILI9341_SoftReset();


	//short setup
	/* Pixel Format Set */
	//LCD_WR_REG(0x3A);
	//LCD_WR_DATA(0x5);    //16bit RGB 5-6-5-bit input
	//LCD_WR_REG(0xB1);
	//LCD_WR_DATA(0x00);
	//LCD_WR_DATA(0x18);

	//EXIT SLEEP
	//LCD_WR_REG(0x11);

	//HAL_Delay(120);

	//TURN ON DISPLAY
//	LCD_WR_REG(0x29);
	//LCD_WR_DATA(0x2C);

//	LCD_direction(ROTATE_0);


#if 1

	/* Power Control A */
	LCD_WR_REG(0xCB);
	LCD_WR_DATA(0x39);
	LCD_WR_DATA(0x2C);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x02);
	/* Power Control B */
	LCD_WR_REG(0xCF);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xC1);
	LCD_WR_DATA(0x30);
	/* Driver timing control A */
	LCD_WR_REG(0xE8);
	LCD_WR_DATA(0x85);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x78);
	/* Driver timing control B */
	LCD_WR_REG(0xEA);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	/* Power on Sequence control */
	LCD_WR_REG(0xED);
	LCD_WR_DATA(0x64);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x81);
	/* Pump ratio control */
	LCD_WR_REG(0xF7);
	LCD_WR_DATA(0x20);
	/* Power Control 1 */
	LCD_WR_REG(0xC0);
	LCD_WR_DATA(0x10);
	/* Power Control 2 */
	LCD_WR_REG(0xC1);
	LCD_WR_DATA(0x10);
	/* VCOM Control 1 */
	LCD_WR_REG(0xC5);
	LCD_WR_DATA(0x3E);
	LCD_WR_DATA(0x28);
	/* VCOM Control 2 */
	LCD_WR_REG(0xC7);
	LCD_WR_DATA(0x86);
	/* VCOM Control 2 */
	LCD_WR_REG(0x36);
	LCD_WR_DATA(0x48);
	/* Pixel Format Set */
	LCD_WR_REG(0x3A);
	LCD_WR_DATA(0x55);    //16bit
	LCD_WR_REG(0xB1);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x18);



	/* Display Function Control */
	LCD_WR_REG(0xB6);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x82);
	LCD_WR_DATA(0x27);

	/* Display Function Control */
	LCD_WR_REG(0xB0);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x82);


	/* 3GAMMA FUNCTION DISABLE */
	//LCD_WR_REG(0xF2);
//	LCD_WR_DATA(0x00);
	/* GAMMA CURVE SELECTED */
//	LCD_WR_REG(0x26); //Gamma set
//	LCD_WR_DATA(0x01); 	//Gamma Curve (G2.2)
	//Positive Gamma  Correction
/*	LCD_WR_REG(0xE0);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0x2B);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x4E);
	LCD_WR_DATA(0xF1);
	LCD_WR_DATA(0x37);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x00);
*/	//Negative Gamma  Correction
/*	LCD_WR_REG(0xE1);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x14);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0xC1);
	LCD_WR_DATA(0x48);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0x36);
	LCD_WR_DATA(0x0F);
*/
	/*Inversion on */
	LCD_WR_REG(0x21);
	HAL_Delay(10);
	//EXIT SLEEP
	LCD_WR_REG(0x11);

	HAL_Delay(120);

	//TURN ON DISPLAY
	LCD_WR_REG(0x29);
	LCD_WR_DATA(0x2C);

	LCD_direction(ROTATE_0);
	HAL_Delay(100);

#else
#endif
#if 0
	// I refer https://github.com/dtnghia2206/TFTLCD/blob/master/TFTLCD/ILI9341/ILI9341_Driver.c
	/* Power Control A */
/*	LCD_WR_REG(0xCB);  // nera tokio rego
	LCD_WR_DATA(0x39);
	LCD_WR_DATA(0x2C);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x02);  */
	/* Power Control B */
/*	LCD_WR_REG(0xCF);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xC1);
	LCD_WR_DATA(0x30);  */
	/* Driver timing control A */
/*	LCD_WR_REG(0xE8);
	LCD_WR_DATA(0x85);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x78); */
	/* Driver timing control B */
	LCD_WR_REG(0xEA);   //needed
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	/* Power on Sequence control */
/*	LCD_WR_REG(0xED);
	LCD_WR_DATA(0x64);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x81); */
	/* Pump ratio control */
/*	LCD_WR_REG(0xF7);
	LCD_WR_DATA(0x20);*/
//	 Power Control 1
/*	LCD_WR_REG(0xC0);
	LCD_WR_DATA(0x10);
	Power Control 2 */
/*	LCD_WR_REG(0xC1);
	LCD_WR_DATA(0x10);
	VCOM Control 1 */
	LCD_WR_REG(0xC5);    // needed
	LCD_WR_DATA(0x20);
//	LCD_WR_DATA(0x3E);
//	LCD_WR_DATA(0x28);
	/* VCOM Control 2 */
/*	LCD_WR_REG(0xC7);
	LCD_WR_DATA(0x86);
	VCOM Control 2 */
/*	LCD_WR_REG(0x36);
	LCD_WR_DATA(0x48);
	Pixel Format Set */
	LCD_WR_REG(0x3A);
	LCD_WR_DATA(0x55);    //16bit
//	LCD_WR_REG(0xB1);
//	LCD_WR_DATA(0x00);
//	LCD_WR_DATA(0x18);
	/* Display Function Control */
/*	LCD_WR_REG(0xB6);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x82);
	LCD_WR_DATA(0x27);
	3GAMMA FUNCTION DISABLE */
//	LCD_WR_REG(0xF2);
//	LCD_WR_DATA(0x00);

//	Inversion off
	//LCD_WR_REG(0x20);
	/*Inversion on */
	LCD_WR_REG(0x21);
	// RAMCTRL (B0h): RAM Control
	//LCD_WR_REG(0xB0);
	//LCD_WR_DATA(0x00);
	//LCD_WR_DATA(0x0);

	/*Inversion on */
//	LCD_WR_REG(0x21);
	/*MADCTL 36h Memory data access control*/
	//LCD_WR_REG(0x36);
	//LCD_WR_DATA(0x48);

	/*GAMMA CURVE SELECTED */
/*	LCD_WR_REG(0x26); //Gamma set
	LCD_WR_DATA(0x01); 	//Gamma Curve (G2.2)
	//Positive Gamma  Correction
	LCD_WR_REG(0xE0);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0x2B);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x4E);
	LCD_WR_DATA(0xF1);
	LCD_WR_DATA(0x37);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x00);
	//Negative Gamma  Correction
	LCD_WR_REG(0xE1);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x14);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0xC1);
	LCD_WR_DATA(0x48);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0x36);
	LCD_WR_DATA(0x0F);
*/

	//EXIT SLEEP
	LCD_WR_REG(0x11);

	HAL_Delay(120);

	//TURN ON DISPLAY
	LCD_WR_REG(0x29); // no parameter
//	LCD_WR_DATA(0x2C); no



	LCD_direction(ROTATE_0);
	//LED_H();



	#endif

#if 0


		LCD_WR_REG(0x11);  //EXIT SLEEP

		LCD_WR_REG(0x3A);
		LCD_WR_DATA(0x55);    //16bit

		/*Inversion on */
		LCD_WR_REG(0x21);



//	const char st_init[]={
//	   10,                       				// 9 commands in list:
//	    ST7789_SWRESET,   ST_CMD_DELAY,  		// 1: Software reset, no args, w/delay
//	      150,                     				// 150 ms delay
//	    ST7789_SLPOUT ,   ST_CMD_DELAY,  		// 2: Out of sleep mode, no args, w/delay
//	      255,                    				// 255 = 500 ms delay
//	    ST7789_COLMOD , 1+ST_CMD_DELAY,  		// 3: Set color mode, 1 arg + delay:
//	      0x55,                   				// 16-bit color
//	      10,                     				// 10 ms delay
//	    ST7789_MADCTL , 1,  					// 4: Memory access ctrl (directions), 1 arg:
//	      0x00,                   				// Row addr/col addr, bottom to top refresh
//	    ST7789_CASET  , 4,  					// 5: Column addr set, 4 args, no delay:
//	      0x00, ST7789_240x240_XSTART,          // XSTART = 0
//		  (ST7789_TFTWIDTH+ST7789_240x240_XSTART) >> 8,
//		  (ST7789_TFTWIDTH+ST7789_240x240_XSTART) & 0xFF,   // XEND = 240
//	    ST7789_RASET  , 4,  					// 6: Row addr set, 4 args, no delay:
//	      0x00, ST7789_240x240_YSTART,          // YSTART = 0
//	      (ST7789_TFTHEIGHT+ST7789_240x240_YSTART) >> 8,
//		  (ST7789_TFTHEIGHT+ST7789_240x240_YSTART) & 0xFF,	// YEND = 240
//	    ST7789_INVON ,   ST_CMD_DELAY,  		// 7: Inversion ON
//	      10,
//	    ST7789_NORON  ,   ST_CMD_DELAY,  		// 8: Normal display on, no args, w/delay
//	      10,                     				// 10 ms delay
//	    ST7789_DISPON ,   ST_CMD_DELAY,  		// 9: Main screen turn on, no args, w/delay
//	    255 };
//


	//EXIT SLEEP
	LCD_WR_REG(0x11);

	HAL_Delay(120);

	//TURN ON DISPLAY
	LCD_WR_REG(0x29); // no parameter
//	LCD_WR_DATA(0x2C); no

	LCD_direction(ROTATE_0);
	//LED_H();


#endif

}

void ILI9341_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y)
{
	// Set Window
	LCD_WR_REG(0x2a);
	LCD_WR_DATA(start_x >> 8);
	LCD_WR_DATA(0xFF & start_x);
	LCD_WR_DATA(end_x >> 8);
	LCD_WR_DATA(0xFF & end_x);

	LCD_WR_REG(0x2b);
	LCD_WR_DATA(start_y >> 8);
	LCD_WR_DATA(0xFF & start_y);
	LCD_WR_DATA(end_y >> 8);
	LCD_WR_DATA(0xFF & end_y);

}

void ILI9341_WritePixel(uint16_t x, uint16_t y, uint16_t color)
{
	uint8_t data[2];
	data[0] = color >> 8;
	data[1] = color;
	ILI9341_SetWindow(x, y, x, y);
	// Enable to access GRAM
	LCD_WR_REG(0x2c);
	DC_H();
	if (HAL_SPI_Transmit(&hspi1, data, 2, 1000) != HAL_OK) {
		Error_Handler();
	}
}

// Call this function after ILI9341_SetWindow
// This function is non blocked
// The variable for Callback is open. User should set by himself
void ILI9341_DrawBitmap(uint16_t w, uint16_t h, uint8_t *s)
{
	// Enable to access GRAM
	LCD_WR_REG(0x2c);

	DC_H();
	HAL_SPI_Transmit_DMA(&hspi1, (uint8_t*)s, w * h *sizeof(uint16_t));
}

void ILI9341_Fill(uint16_t color)
{
	uint8_t data[320*2];

	// Prepare line data
	for (int i = 0; i < 240*2;){
		data[i++] = color;
		data[i++] = color >> 8;

	}

	ILI9341_SetWindow(0, 0, 240-1, 320-1);

	// Enable to access GRAM
	LCD_WR_REG(0x2c);

	//CS_L();
	DC_H();
	for (int i = 0; i < 320; i++) {
		HAL_SPI_Transmit(&hspi1, data, 240*2, 1000);
	}
	//CS_H();

}
void ILI9341_DrawBitmap_SPI(uint16_t w, uint16_t h, uint8_t *s)
{
	uint8_t data[320*2];

	// Prepare line data
for (int col = 0; col < 320;col += 1){


	//		for (uint32_t y = 0; y <  GUI_HEIGHT; y += 80) {
	//			ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+80-1);
	//			//Done = 0;
	//			ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_rgb[image_data_logo]);


	for (int i = 0; i < 240*2;){
		data[i++] = *s++;
		data[i++] = *s++ >> 8;

	}

	ILI9341_SetWindow(0, 0, 240-1, 320-1);

	// Enable to access GRAM
	LCD_WR_REG(0x2c);

	//CS_L();
	DC_H();
	for (int i = 0; i < 320; i++) {
		HAL_SPI_Transmit(&hspi1, data, 240*2, 1000);
	}
}
	//CS_H();
//	ILI9341_DrawBitmap(GUI_WIDTH, 80, &image_data_rgb[image_data_logo]);

//			image_data_logo += 80*GUI_WIDTH*2;

}
//void ILI9341_Fill(uint16_t color)
//{
//	uint8_t data[320*2];
//
//	// Prepare line data
//	for (int i = 0; i < lcd_window.width*2;){
//		data[i++] = color;
//		data[i++] = color >> 8;
//
//	}
//
//	ILI9341_SetWindow(0, 0, lcd_window.width-1, lcd_window.height-1);
//
//	// Enable to access GRAM
//	LCD_WR_REG(0x2c);
//
//	//CS_L();
//	DC_H();
//	for (int i = 0; i < lcd_window.height; i++) {
//		HAL_SPI_Transmit(&hspi1, data, lcd_window.width*2, 1000);
//	}
//	//CS_H();
void ILI9341_Reset(void)
{
	HAL_Delay(100);
	RESET_L();
	HAL_Delay(100);
	RESET_H();
	HAL_Delay(100);
	CS_L();
	LED_H();
	HAL_Delay(100);
}

void ILI9341_SoftReset(void)
{
	HAL_Delay(100);
	uint8_t cmd;
	cmd = 0x01; //Software reset
	HAL_Delay(100);
	DC_L();
	if (HAL_SPI_Transmit(&hspi1, &cmd, 1, 1000) != HAL_OK) {
		Error_Handler();
		HAL_Delay(200);
	}
}


static void LCD_WR_REG(uint8_t data)
{
	DC_L();
	if (HAL_SPI_Transmit(&hspi1, &data, 1, 1000) != HAL_OK) {
		Error_Handler();
	}
}

static void LCD_WR_DATA(uint8_t data)
{
	DC_H();
	if (HAL_SPI_Transmit(&hspi1, &data, 1, 1000) != HAL_OK) {
		Error_Handler();
	}
}

static void LCD_direction(LCD_Horizontal_t direction)
{
	switch (direction) {
	case ROTATE_0:
		LCD_WR_REG(0x36);
		LCD_WR_DATA(0x48);
		break;
	case ROTATE_90:
		LCD_WR_REG(0x36);
		LCD_WR_DATA(0x28);
		break;
	case ROTATE_180:
		LCD_WR_REG(0x36);
		LCD_WR_DATA(0x88);
	case ROTATE_270:
		LCD_WR_REG(0x36);
		LCD_WR_DATA(0xE8);
		break;
	}
}


static void RESET_L(void)
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
}

static void RESET_H(void)
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
}

static void CS_L(void)
{
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
}

static void DC_L(void)
{
	HAL_GPIO_WritePin(DCX_GPIO_Port, DCX_Pin, GPIO_PIN_RESET);
}

static void DC_H(void)
{
	HAL_GPIO_WritePin(DCX_GPIO_Port, DCX_Pin, GPIO_PIN_SET);
}

static void LED_H(void)
{
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}

