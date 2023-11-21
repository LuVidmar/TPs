import chess_board
import uart
import time

"""
----------------FUNCTIONS----------------
"""

def user_make_move() -> bool:
    # Get move from user
    move = input("Enter your move: ").lower()
    # Check if user wants to exit
    if move in ["exit", "quit", "stop", "end", "q"]:
        return False
    # Check if move is valid
    try:
        if chess_board.is_valid_move(move):
            # Check if a piece was captured
            move_is_capture = chess_board.is_capture(move)
            # Make move
            move_coords = chess_board.move(move)
            if move_is_capture: # Move piece out of board
                print("Piece captured, moving out of board...")
                move_coords_out = chess_board.move_out_of_board(move_coords)
                uart.send_move(move_coords_out) # Send move to STM32
                print("Move sent to STM32: " + move_coords_out)
                print("Waiting for STM32...")
                if uart.wait_ready_next(): # If move is valid (correctly received by STM32)
                    # wait for STM32 to make move (3s)
                    time.sleep(3)
            # Send move to STM32
            uart.send_move(move_coords)
            print("Move sent to STM32: " + move_coords)
            # Print board
            chess_board.print_board()
        else:
            print("Invalid move, try again.")
            user_make_move()
        # Wait for STM32 to make move
        print("Waiting for STM32...")
        if uart.wait_ready_next(): # If move is valid (correctly received by STM32)
            # wait for STM32 to make move (3s)
            time.sleep(3)
            return True
        else: # If move is invalid (not correctly received by STM32)
            # undo latest move
            chess_board.board.pop() # Pop the latest move
            print("Error, please try again.")
            user_make_move() # Restart game
    except chess_board.chess.InvalidMoveError: # If move is invalid
        print("Inexistent move, try again.") # Print error message and try again
        user_make_move()

def make_computer_move():
    computer_move = chess_board.get_best_move()
    # Check if a piece was captured
    move_is_capture = chess_board.is_capture(computer_move)
    # Make move
    move_coords = chess_board.move(computer_move)
    if move_is_capture: # Move piece out of board
        print("Piece captured, moving out of board...")
        move_coords_out = chess_board.move_out_of_board(move_coords)
        uart.send_move(move_coords_out) # Send move to STM32
        print("Move sent to STM32: " + move_coords_out)
        print("Waiting for STM32...")
        if uart.wait_ready_next(): # If move is valid (correctly received by STM32)
            # wait for STM32 to make move (3s)
            time.sleep(3)
    # Send move to STM32
    uart.send_move(move_coords)
    print("Move sent to STM32: " + move_coords)
    # Print board
    chess_board.print_board()
    # Wait for STM32 to make move
    print("Waiting for STM32...")
    if uart.wait_ready_next(): # If move is valid (correctly received by STM32)
        return
    else: # If move is invalid (not correctly received by STM32)
        # undo latest move
        chess_board.board.pop() # Pop the latest move
        print("Error, please try again.")
        make_computer_move() # Restart game


def pvp():
    while chess_board.game_ended() == False: # While the game is not over
        if not user_make_move():
            return # If user wants to exit

def pve():
    # Select color
    input_color = input("Select color (white or black): ").lower()
    if input_color not in ["white", "black"]:
        print("Invalid color, try again.")
        pve()

    # If user is white
    if input_color == "white":
        while chess_board.game_ended() == False: # While the game is not over
            # First, user move
            if not user_make_move():
                return # If user wants to exit
            # Then, computer move
            make_computer_move()
    # If user is black
    elif input_color == "black":
        while chess_board.game_ended() == False: # While the game is not over
            # First, computer move
            make_computer_move()
            # Then, user move
            user_make_move()


def eve():
    while chess_board.game_ended() == False: # While the game is not over
        make_computer_move() # Make move
        # Delay 5s
        time.sleep(5)

"""
----------------FLOW----------------
"""
# Start communications
uart.wait_ready_init()
print("STM32 is ready.\n Game is starting, have fun!\n")
# Select mode: PVP, PVE or EVE
while True:
    mode = input("Select mode: PVP, PVE or EVE: ").lower()
    if mode == "pvp":
        pvp()
        # Send game over
        uart.send_game_over()
        print("Game over, thanks for playing!")
    elif mode == "pve":
        pve()
        # Send game over
        uart.send_game_over()
        print("Game over, thanks for playing!")
    elif mode == "eve":
        eve()
        # Send game over
        uart.send_game_over()
        print("Game over, thanks for playing!")
    else:
        print("Invalid mode, try again.")
        continue
    # Ask if user wants to play again
    play_again = input("Do you want to play again? (y/n): ").lower()
    if play_again in ["y", "yes"]:
        # Reset board
        chess_board.board.reset()
        continue
    else:
        break