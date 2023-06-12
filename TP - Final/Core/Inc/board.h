#ifndef __BOARD_H
#define __BOARD_H

/* ------- Includes ------- */
#include "main.h"

/* ------- Constants ------- */
// Chess board
#define BOARD_SIDE 8 // in squares
#define SQUARE_SIZE 50 // in milimeters

/* ------- Variables ------- */
typedef struct {
    int x;
    int y;
} distance_t;

/* ------- Functions ------- */

//Given a movement string, returns the distance to move in both axis in milimeters
distance_t parse_movement(char*);
//Given a distance, returns if it valid or not
bool is_valid_distance(distance_t);

#endif // BOARD_H