#ifndef __BOARD_H
#define __BOARD_H

/* ------- Includes ------- */
#include "main.h"
#include <stdbool.h>
#include <stdio.h>

/* ------- Constants ------- */
// Chess board
#define BOARD_SIDES 8 // in squares
#define SQUARE_SIZE 50 // in milimeters

/* ------- Variables ------- */
typedef struct {
    int x;
    int y;
} point_t;

extern enum direction { Z_UP, Z_DOWN };
extern point_t last_point; // in squares
extern point_t starting_point, ending_point;

/* ------- Functions ------- */
// Handles a movement, returns if valid or not
bool board_move(char*);
// Given a distance, returns if it valid or not
bool board_parse_movement(char*);
// Given a point, moves the arm from last point to that point
void board_move_to_x(point_t point);
void board_move_to_y(point_t point);
void board_move_to_z(int direction);

#endif // BOARD_H