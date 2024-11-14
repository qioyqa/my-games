#include <iostream>
using namespace std;

const char zero = 'o';
const char one = 'x';

char field[3][3]{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};
 
void print_field(char (&field)[3][3]){
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "|";
        for (int j = 0; j < 3; ++j) {
            cout << " " << field[i][j] << " |";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool update_field(char (&field)[3][3], int row, int col, char symbol) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && field[row][col] == ' ') {
        field[row][col] = symbol;
        return true;
    } else {
        cout << "Неверный ход! Попробуйте снова." << endl;
        return false;
    }
}

char check_winner(char (&field)[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ') {
            return field[i][0];
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' ') {
            return field[0][i];
        }
    }

    if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' ') {
        return field[0][0];
    }
    if (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != ' ') {
        return field[0][2];
    }

    // Ничья
    bool draw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (field[i][j] == ' ') {
                draw = false;
            }
        }
    }

    if (draw) return 'd'; 
    return ' '; 
}

int main(){
    char current_player = one; 
    bool game_over = false;
    char winner = ' ';

    print_field(field);

    while (!game_over) {
        int row, col;
        cout << "Игрок " << current_player << ", введите номер строки и столбца (0-2): ";
        cin >> row >> col;

        if (update_field(field, row, col, current_player)) {
            print_field(field);
            winner = check_winner(field);
            
            if (winner == one || winner == zero) {
                cout << "Победил игрок " << winner << "!" << endl;
                game_over = true;
            } else if (winner == 'd') {
                cout << "Ничья!" << endl;
                game_over = true;
            } else {
                current_player = (current_player == one) ? zero : one.;
            }
        }
    }

    return 0;
}
