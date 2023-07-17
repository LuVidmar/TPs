import chess

# Create a new board
board = chess.Board()

def is_valid_move(move: str) -> bool:
    m = chess.Move.from_uci(move)
    return m in board.legal_moves

def move(move: str) -> str: # Returns the move in UCI format
    bmove = board.push_san(move)
    return bmove.uci()

def get_board():
    return board

def game_ended() -> bool:
    return board.is_game_over()