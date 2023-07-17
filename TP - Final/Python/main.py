import chess_board
import uart
import time

# Start communications
uart.wait_ready_init()
print("STM32 is ready.\n Game is starting, have fun!\n")
# Play chess
while chess_board.game_ended() == False: # While the game is not over
    # Get move from user
    move = input("Enter your move: ")
    # Check if user wants to exit
    if move in ["exit", "quit", "stop", "end", "q"]:
        break
    # Check if move is valid
    try:
        if chess_board.is_valid_move(move):
            # Make move
            move_coords = chess_board.move(move)
            # Send move to STM32
            uart.send_move(move_coords)
            print("Move sent to STM32: " + move_coords)
            # Print board
            chess_board.print_board()
        else:
            print("Invalid move, try again.")
            continue
        # Wait for STM32 to make move
        print("Waiting for STM32 to make move...")
        uart.wait_ready_next()
    except chess_board.chess.InvalidMoveError: # If move is invalid
        print("Invalid move, try again.") # Print error message and try again

        
# Send game over
uart.send_game_over()
print("Game over, thanks for playing!")