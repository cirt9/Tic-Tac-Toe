#include <iostream>
#include <windows.h>
#include "kih.h"

namespace TTT
{
    TickTackToe::TickTackToe()
    {
        scoreX_ = scoreO_ = 0;
        player = Cross;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                field_[i][j] = ' ';
            }
        }
    }

    void TickTackToe::play(int w, int k)
    {
        using std::cout;
        using std::endl;
        if(field_[w][k]==Nought_ || field_[w][k]==Cross_)
        {
            cout << "To pole jest juz uzupelnione!" << endl;
            Sleep(2000);
        }
        else if(w>2 || w<0 || k<0 || k>2)
        {
            cout << "Nie ma takiego pola!" << endl;
            Sleep(2000);
        }
        else
        {
            if(player == Cross)
            {
                field_[w][k] = Cross_;
                player = Nought;
            }
            else
            {
                field_[w][k] = Nought_;
                player = Cross;
            }
        }
    }

    bool TickTackToe::isFull()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(field_[i][j] == ' ') return false;
            }
        }
        return true;
    }

    char TickTackToe::ifWin()
    {

        int helpx=0, helpo=0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(field_[j][i] == Cross_)
                {
                    helpx++;
                    continue;
                }
                else if(field_[j][i] == Nought_)
                {
                    helpo++;
                    continue;                                           //vertical
                }
            }

            if(helpx!=3) helpx = 0;
            if(helpo!=3) helpo = 0;
            if(helpx == 3) return Cross_;
            else if(helpo == 3) return Nought_;
        }


        //-------------------------------------------------------------------------------------------------------

        helpo = helpx = 0;

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(field_[i][j] == Cross_)
                {
                    helpx++;
                    continue;
                }
                else if(field_[i][j] == Nought_)
                {
                    helpo++;                                        //horizontal
                    continue;
                }
            }

            if(helpx!=3) helpx = 0;
            if(helpo!=3) helpo = 0;
            if(helpx == 3) return Cross_;
            else if(helpo == 3) return Nought_;
        }

        //-------------------------------------------------------------------------------------------------------
        helpo = helpx = 0;

        for(int i=0, j=0; i<3; i++,j++)
        {
            if(field_[i][j] == Cross_)
            {
                helpx++;
                continue;
            }
            else if(field_[i][j] == Nought_)  //from top left to bottom right
            {
                helpo++;
                continue;
            }
        }
        if(helpx == 3) return Cross_;
        else if(helpo == 3) return Nought_;

        //-------------------------------------------------------------------------------------------------------
        helpo = helpx = 0;
        for(int i=0, j=2; i<3; i++, j--)
        {
            if(field_[i][j] == Cross_)
            {
                helpx++;
                continue;
            }
            else if(field_[i][j] == Nought_)  //from bottom right to top left
            {
                helpo++;
                continue;
            }
        }
        if(helpx == 3) return Cross_;
        else if(helpo == 3) return Nought_;

        return 'N';
    }

    /*void TickTackToe::ShowScore() const
    {
        using std::cout;
        using std::endl;
        cout << "Score: " << endl
             << "X: " << scoreX_ << endl
             << "Y: " << scoreO_ << endl;
    }*/

    void TickTackToe::ShowField() const
    {
        using std::cout;
        using std::endl;
        cout << "\t\t        KOLKO I KRZYZYK\n" << endl;
        cout << "\t\tAby wyjsc wpisz 999 w liczbe wierszy\n" << endl;
        cout << "\n\t\t\t   |1 |2 |3"<< endl;
        for(int i=0; i<3; i++)
        {
            cout << "\t\t\t" << i+1 << "  ";
            for(int j=0; j<3; j++)
            {
                cout << "|" <<" " <<field_[i][j];
            }
            cout << endl;
        }
        if(player == Nought) cout << "Teraz gracz O" << endl;
        else if(player == Cross) cout << "Teraz gracz X" << endl;
    }
}
