/* -------- Includes -------- */
#include "main.h"

/* -------- Constants -------- */
#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup
#define REFRESH_RATE 1 // in mS * 100

/* -------- Variables -------- */
extern char lcd_buffer[16];

/* -------- Functions -------- */

// Sends command to display
void lcd_send_cmd (char);
// Inits display
void lcd_init (void);
// Sends char to display
void lcd_send_data (char);
// Sends string to display
void lcd_send_string (char*);
// Clears display
void lcd_clear (void);
// Refresh display
void lcd_refresh (void);
// Change value to display
void lcd_change_text (char*);