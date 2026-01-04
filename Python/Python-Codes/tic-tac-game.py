# Codigo de prueba, en modificacion 
board = [" " for _ in range(9)]

def display_board():
    print("\n")
    for i in range(3):
        print(" " + board[i*3] + " | " + board[i*3+1] + " | " + board[i*3+2])
        if i < 2:
            print("---+---+---")
    print("\n")

def check_winner(player):
    winning_combinations = [
        [0,1,2], [3,4,5], [6,7,8],  # Rows
        [0,3,6], [1,4,7], [2,5,8],  # Columns
        [0,4,8], [2,4,6]            # Diagonals
    ]
    for a,b,c in winning_combinations:
        if board[a] == board[b] == board[c] == player:
            return True
    return False

def is_board_full():
    return " " not in board

def main():
    current_player = "X"
    
    while True:
        display_board()
        
        try:
            move = int(input(f"Player {current_player}, choose a position (1-9): ")) - 1
            
            if move < 0 or move > 8:
                print("Invalid position. Choose a number between 1 and 9.")
                continue
            
            if board[move] != " ":
                print("That position is already taken. Choose another.")
                continue
        except ValueError:
            print("Please enter a valid number.")
            continue
        
        board[move] = current_player
        
        if check_winner(current_player):
            display_board()
            print(f"Player {current_player} wins!")
            break
        
        if is_board_full():
            display_board()
            print("It's a tie!")
            break
        
        current_player = "O" if current_player == "X" else "X"

if __name__ == "__main__":
    main()
