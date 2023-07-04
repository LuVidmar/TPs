#include "board.h"

point_t last_point = {0, 0};
point_t starting_point, ending_point;

bool board_parse_movement(char* movement){
    /* Check format */
    if (strlen(movement) != 4) // Movement should be A1B2 (ie 4 characters)
        return false;
    
    if (movement[0] < 'A' || movement[0] > 'H') // First character should be A-H
        return false;
    
    if (movement[1] < '1' || movement[1] > '8') // Second character should be 1-8
        return false;

    if (movement[2] < 'A' || movement[2] > 'H') // Third character should be A-H
        return false;
    
    if (movement[3] < '1' || movement[3] > '8') // Fourth character should be 1-8
        return false;
    
    return true; // If all checks passed, return true
}

bool board_move(char* movement){
    /* Parse movement */
    if (!board_parse_movement(movement)) {
        usart_print("\n\rInvalid movement!\n\r");
        lcd_change_text("Invalid mov!");
        return false;
    }

    /* Extract 2 points */
    starting_point.x = movement[0] - 'A'; // Convert A-H to 0-7
    starting_point.y = movement[1] - '1'; // Convert 1-8 to 0-7
    ending_point.x = movement[2] - 'A'; // Convert A-H to 0-7
    ending_point.y = movement[3] - '1'; // Convert 1-8 to 0-7

    return true;
}

void board_move_to_x(point_t point){
    // Move from latest point to new point
    int dx = point.x - last_point.x;

    // Distance in mm
    dx *= SQUARE_SIZE;

    // Inform user
    usart_print("\n\rMoving: ");
    char coordinates[16] = {0};
    sprintf(coordinates, "x: %d mm", dx);
    usart_print(coordinates);
    lcd_clear();
    lcd_change_text("MOVING");
    lcd_write_in_second_line();
    lcd_change_text(coordinates);

    // Move
    moverXmm(dx);
}

void board_move_to_y(point_t point){
    // Move from latest point to new point
    int dy = point.y - last_point.y;

    // Distance in mm
    dy *= SQUARE_SIZE;

    // Inform user
    usart_print("\n\rMoving: ");
    char coordinates[16] = {0};
    sprintf(coordinates, "y: %d mm", dy);
    usart_print(coordinates);
    lcd_clear();
    lcd_change_text("MOVING");
    lcd_write_in_second_line();
    lcd_change_text(coordinates);

    // Move
    moverYmm(dy);
}