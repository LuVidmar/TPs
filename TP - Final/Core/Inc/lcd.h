/* -------- Includes -------- */
#include "main.h"

/* -------- Constants -------- */
#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup

/* -------- Functions -------- */

// Sends command to display
void lcd_send_cmd (char);
// Inits display
void lcd_init (void);
// Sends char to display
void lcd_send_data (char);
// Sends string to display
void lcd_send_string (char *);
// Clears display
void lcd_clear (void);