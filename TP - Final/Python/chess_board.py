import chess
import chess.engine

# Create a new board
board = chess.Board()
# Create a new engine
engine = chess.engine.SimpleEngine.popen_uci("../stockfish/stockfish-ubuntu-x86-64-avx2")

def is_valid_move(move: str) -> bool:
    m = chess.Move.from_uci(move)
    return m in board.legal_moves

def move(move: str) -> str: # Returns the move in UCI format
    bmove = board.push_san(move)
    return bmove.uci()

def game_ended() -> bool:
    return board.is_game_over()

def print_board():
    print("\n-----------------")
    board_string = board.unicode(invert_color=False,empty_square=" ")
    # Separate the board into lines
    board_lines = board_string.split("\n")
    # Adding the line numbers to the board
    for i in range(8):
        board_lines[i] = str(8-i) + " " + board_lines[i]
        print(board_lines[i])
    # Adding the column letters to the board
    print("  a b c d e f g h")
    print("-----------------\n")

def get_best_move():
    result = engine.play(board, chess.engine.Limit(time=0.1))
    return result.move.uci()

def delete_engine():
    engine.quit()