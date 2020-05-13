#include "lcd.h"
#include "lcd_i2c.h"

LCDDisplay::LCDDisplay() {
	this->isBacklightEnabled = true;
}

void LCDDisplay::init() {
	LCD_i2cDeviceCheck();		
	LCD_Init();
	LCD_BackLight(LCD_BL_ON);
	LCD_SetCursor(1,1);
}

void LCDDisplay::enableBacklight() {
	LCD_BackLight(LCD_BL_ON);
}

void LCDDisplay::disableBacklight() {
	LCD_BackLight(LCD_BL_OFF);
}

void LCDDisplay::toggleBacklight() {
	if (this->isBacklightEnabled) {
		this->disableBacklight();
	} else {
		this->enableBacklight();
	}
	this->isBacklightEnabled = !this->isBacklightEnabled;
}

void LCDDisplay::clearDisplay() {
	LCD_Clear();
}

void LCDDisplay::setLineText(char* text, int line) {
	LCD_SetCursor(line, 1);
	LCD_Send_String(text, STR_NOSLIDE);	 
}

void LCDDisplay::printCoordinate(char* text, double coord, int line) {
	LCD_SetCursor(line, 1);
	LCD_PrintWithDouble(text, coord);
}

void LCDDisplay::printInt(char* text, int val, int line) {
	LCD_SetCursor(line, 1);
	LCD_Print(text, val);
}
