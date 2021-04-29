#Game board - Game state
def create_board():
    board = [
                [' ', ' ', ' '],
                [' ', ' ', ' '],
                [' ', ' ', ' ']
            ]
    return board

def print_board(board):
    print(f' {board[0][0]} | {board[0][1]} | {board[0][2]} ')
    print('---|---|---')
    print(f' {board[1][0]} | {board[1][1]} | {board[1][2]} ')
    print('---|---|---')
    print(f' {board[2][0]} | {board[2][1]} | {board[2][2]} ')

def user_move(board, player):
    move = int(input('Enter your move (1 - 9): '))
    place = 1
    row = 0
    found = False
    if move >= 1 and move <= 9:
        for times in range(len(board)):
            for col in range(len(board)):
                if move == place and board[row][col] == ' ':
                    board[row][col] = player
                    found = True
                    break
                else:
                    place += 1
            if found == True:
                break
            row += 1
    else:
        print(f'Invalid move "{move}".')

def check_for_winner(board, player):
    #check rows
    if board[0][0] == player and board[0][1] == player and board[0][2] == player:
        return player
    if board[1][0] == player and board[1][1] == player and board[1][2] == player:
        return player
    if board[2][0] == player and board[2][1] == player and board[2][2] == player:
        return player

    #check cols
    if board[0][0] == player and board[1][0] == player and board[2][0] == player:
        return player
    if board[0][1] == player and board[1][1] == player and board[2][1] == player:
        return player
    if board[0][2] == player and board[1][2] == player and board[2][2] == player:
        return player

    #check diags
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return player
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return player
    if board[0][0] != ' ' and board[0][1] != ' ' and board[0][2] != ' ' and board[1][0] != ' ' and board[1][1] != ' ' and board[1][2] != ' ' and board[2][0] != ' ' and board[2][1] != ' ' and board[2][2] != ' ':
        return "cat"

#Main program
board = create_board()
print_board(board)
player = 'x'
winner = None

#Game loop
while winner == None:
    # player move
    user_move(board, player)

    #print board
    print_board(board)

    #check for winner
    winner = check_for_winner(board, player)

    #switch player (toggle pattern)
    if player == 'x':
        player = 'o'
    else:
        player = 'x'
if winner == 'cat':
    print('Tie game!')
else:
    print(f'Player "{winner}" has won the game!')
