#include <iostream>
#include "kih.h"

using TTT::TickTackToe;
int main()
{
    TickTackToe game;
    using std::cout;
    using std::endl;
    using std::cin;

    int line, column;
    game.ShowField();
    while(true)
    {
        if(game.ifWin() == 'X')
        {
            cout << "Wygral gracz X!" << endl;
            break;
        }

        else if(game.ifWin() == 'O')
        {
            cout << "Wygral gracz O!" << endl;
            break;
        }

        if(game.isFull())
        {
            cout << "Remis!" << endl;
            break;
        }

        cout << "Podaj wiersz, a nastepnie kolumne" << endl;
        cin >> line;
        if(line == 999) break;
        cin >> column;
        game.play(line-1, column-1);
        game.ShowField();

    }

    std::cin.get(); std::cin.get();

}
