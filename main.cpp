//Amanda Monaco 5/18/22 Project 2: Connect 4 game
#include <iostream>
#include <string>
using namespace std;

const int COLS = 7, ROWS = 6;

//function to ask for user needed information: names and pieces
void playerSetUp(string names[], char pieces[]){
    std::cout << "Enter Player 1's name: ";
    std::cin >> names[0];
    std::cout << "Enter Player 2's name: ";
    std::cin >> names[1];
    std::cout << "Enter Player 1's piece: ";
    std::cin >> pieces[0];
    std::cout << "Enter Player 2's piece: ";
    std::cin >> pieces[1];
}

//funtion that will initialize the board with each space as an underscore
void initializeBoard(char gameboard[][COLS]){
    for(int i = 0; i < ROWS; i++){
        std::cout << '|';
        for(int j = 0; j < COLS; j++) {
            gameboard[i][j] = '_';
            std::cout << gameboard[i][j];
            std::cout << '|';
        }
        std::cout << '\n';
    }
}

//function that asks the user for the column choice, makes sure it's a value from 1-7, and returns it as an int
int askColChoice(string player){
    int choice;
    std::cout << player << "'s turn. \n Pick a column to drop your piece: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2 && choice != 3 && choice != 4 &&
       choice != 5 && choice != 6 && choice != 7){
            cout << "Please enter a value from 1-7: ";
            cin >> choice;
    }
    return choice;
}

//function that will print out the board with all of the current pieces
void printBoard(char board[][COLS]){
    for(int i = 0; i < ROWS; i++){
        cout << '|';
        for(int j = 0; j < COLS; j++){
            cout << board[i][j] << '|';
        }
        cout << '\n';
    }
}

//function that puts the piece in the column chosen by the player
void placePiece(int col_choice, char gameBoard[][COLS], char piece){
    for(int i = ROWS - 1; i >= 0; i--){
        if(gameBoard[i][col_choice - 1] == '_') {
            gameBoard[i][col_choice - 1] = piece;
            break;
        }
    }
}

//function to check for all types of wins and return true when there is one
bool check_win(char board[][COLS], char piece){
    bool returnStmnt = false;
    //vertical win
    for(int a = 0; a < ROWS - 3; a++){
        for(int b = 0; b < COLS; b++){
            if(board[a][b] == board[a+1][b] && board[a+1][b] == board[a+2][b] &&
               board[a+2][b] == board[a+3][b] && board[a][b] == piece){
                    returnStmnt = true;
            }
        }
    }
    //horizontal win
    for(int a = 0; a < ROWS; a++){
        for(int  b = 0; b < COLS; b++){
            if(board[a][b] == board[a][b+1] && board[a][b+1] == board[a][b+2] &&
               board[a][b+2] == board[a][b+3] && board[a][b] == piece){
                    returnStmnt = true;
            }
        }

    }
    //upper right lower left diagonal win
    for(int a = 0; a < ROWS; a++){
        for(int b = 0; b < COLS; b++){
            if(board[a][b] == board[a+1][b-1] && board[a+1][b-1] == board[a+2][b-2] &&
               board[a+2][a-2] == board[a+3][b-3] && board[a][b] == piece){
                    returnStmnt = true;
            }
        }
    }
    //lower right upper left diagonal win
    for(int a = 0; a < ROWS; a++){
        for(int b = 0; b < COLS; b++){
            if(board[a][b] == board[a+1][b+1] && board[a+1][b+1] == board[a+2][b+2] &&
               board[a+2][b+2] == board[a+3][b+3] && board[a][b] == piece){
                    returnStmnt = true;
            }
        }
    }
    return returnStmnt;
}

//function that will print out the winner with their name
void endGame(string player){
    cout << player << " is the winner!!!\n";
}

//function to play connect 4 game
void playGame(char gameboard[][COLS]){
    string player_name[2];
    char player_piece[2];
    playerSetUp(player_name,player_piece);

    bool game_over = false;

    //game loop that places the piece, prints the board, and checks a win for each player until one wins
    while(game_over == false){
        for(int i = 0; i < 2; i++){
            placePiece(askColChoice(player_name[i]), gameboard, player_piece[i]);
            printBoard(gameboard);
            if(check_win(gameboard, player_piece[i])) {
                endGame(player_name[i]);
                game_over = true;
                break;
            }
        }
    }
}

//function that asks the user if they would like to play again and returns a character
char play_again(){
    char again;
    cout << "Would you like to play again? (y/n): ";
    cin >> again;
    return again;
}


int main() {
    bool play = true;
    string players[2];
    char piece[2];
    char board[ROWS][COLS];

    while(play == true){
        initializeBoard(board);
        playGame(board);
        if (play_again() == 'n') {
            cout << "Thanks for playing!";
            play = false;
        }
    }
}
