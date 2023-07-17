#include <iostream>
#include <cstdlib>
#include <ctime>

void drawBoard(char *spaces){
    system("cls");
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "     |     |     \n";

}
void playerMove(char *spaces, char player){
    int move;
    do
    {
        std::cout << "Enter your move (from 1 to 9): ";
        std::cin >>  move;
    } while (move < 1 || move >9);
    move--;
    if (spaces[move] == ' '){
        spaces[move] = player;
    } else{
        std::cout << "Try another move!\n";
        playerMove(spaces, player);
    }
}
void computerMove(char *spaces, char computer){
    srand(time(NULL));
    int move;
    do {
        move = rand() % 9;
    } while (spaces[move] != ' ');
    spaces[move] = computer;
}
bool checkWinner(char *spaces, char player){
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        if (spaces[0] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        if (spaces[0] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        if (spaces[0] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        if (spaces[3] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        if (spaces[6] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        if (spaces[1] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        if (spaces[2] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        if (spaces[2] == player){
            std::cout << "* You Won *\n";
        } else {
            std::cout << "! You Lose !\n";
        }
    } else {
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for (int i = 0; i < 9; i++){
        if (spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It is a tie!\n";
    return true;   
}

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);
    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player)){
        running = false;
        break;
        } else if (checkTie(spaces)){
            running = false;
            break;
        }

        std::cout << "\n";

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player)){
            running = false;
            break;
        } else if (checkTie(spaces)){
            running = false;
            break;
        }
    }
    
    return 0;
}