#include "board.h"

distance_t parse_movement(char* movement){
    // Distance is in the form of "x,y", default is "-1,-1"
    distance_t distance;
    distance.x = -1;
    distance.y = -1;

    /* Check format */
    if (strlen(movement) != 4) // Movement should be A1B2 (ie 4 characters)
        return distance;
    
    if (movement[0] < 'A' || movement[0] > 'H') // First character should be A-H
        return distance;
    
    if (movement[1] < '1' || movement[1] > '8') // Second character should be 1-8
        return distance;

    if (movement[2] < 'A' || movement[2] > 'H') // Third character should be A-H
        return distance;
    
    if (movement[3] < '1' || movement[3] > '8') // Fourth character should be 1-8
        return distance;

    /* Parse (validations are complete) */
    distance.x = movement[2] - movement[0] + 48; // Convert ASCII to decimal
    distance.y = movement[3] - movement[1] + 48; // Convert ASCII to decimal

    /* Convert to milimiters */
    distance.x *= SQUARE_SIZE;
    distance.y *= SQUARE_SIZE;

    return distance;
}

bool is_valid_distance(distance_t distance){
    if (distance.x == -1 || distance.y == -1)
        return false;
    else
        return true;
}