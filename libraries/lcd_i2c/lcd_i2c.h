#include "stm32f1xx_hal.h"

static I2C_HandleTypeDef hi2cx;
extern I2C_HandleTypeDef hi2c1;
static void hi2cx_define(void)
{
	hi2cx = hi2c1;
}

static const uint8_t BFR_MAX = 100;

	
#define	LCD_CLEAR_DISPLAY           0x01 
#define	LCD_RETURN_HOME             0x02
#define	LCD_ENTRYMODE_SET           0x04
#define	LCD_DISPLAY_CONTROL         0x08
#define	LCD_CURSORDISPLAY_SHIFT     0x10
#define	LCD_FUNCTION_SET            0x20
#define	LCD_SET_CGRAMADDR           0x40
#define	LCD_SET_DDRAMADDR           0x80

typedef enum {
	ENTRY_INCREMENT       = 0x02,
	ENTRY_DECREMENT       = 0x00,
	ENTRY_DISPLAY_SHIFT   = 0x01,
	ENTRY_DISPLAY_NOSHIFT = 0x00
} lcd_EntryMode_set_t;

typedef enum {
	DISPLAY_ON   = 0x04,
	DISPLAY_OFF  = 0x00,
	CURSOR_ON    = 0x02,
	CURSOR_OFF   = 0x00,
	BLINK_ON  = 0x01,
  	BLINK_OFF = 0x00,
} lcd_display_control_t;
	
typedef enum {
	DISPLAY_SHIFT  = 0x08,
	CURSOR_SHIFT   = 0x00,
	SHIFT_TO_RIGHT = 0x04,
	SHIFT_TO_LEFT  = 0x00
} lcd_CursorDisplay_shift_t;  	

typedef enum {
	MODE_8B        = 0x10,
	MODE_4B        = 0x00,
	MODE_2L        = 0x08,
	MODE_1L        = 0x00,
	MODE_5X10_DOTS = 0x04,
	MODE_5X8_DOTS  = 0x00
} lcd_function_set_t;  

//LCD backlight, RS, RW, E definitions for i2c module
//P7............P0 is data that will be sent to lcd through i2c module(PCF8574); 
//P0 : RS
//P1 : RW
//P2 : E
//P3 : BT --> backlight pin activation
//P4 : D4
//P5 : D5
//P6 : D6
//P7 : D7
#define LCD_RS     0x01	
#define LCD_RW     0x02
#define LCD_E      0x04
#define LCD_BL_ON  0x08 //Backlight on
#define LCD_BL_OFF 0x00 //Backlight off
	
//Define lcd string mode;
#define STR_NOSLIDE 0x00
#define STR_SLIDE 0x01

void LCD_i2cDeviceCheck(void);

void LCD_Init(void);

void LCD_Clear(void);

void LCD_SetCursor(int line_x, int chr_x);

void LCD_BackLight(uint8_t light_state);

void LCD_Set_Command(uint8_t cmd);

void LCD_Write_Data(uint8_t datax);

void LCD_Send_String(char str[], uint8_t mode);

void LCD_Print(char const *ch, int value);

void LCD_PrintF(char const *ch, float value);

void LCD_PrintWithDouble(char const *ch, double value);

