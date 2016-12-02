#ifndef KIH_H_INCLUDED
#define KIH_H_INCLUDED
namespace TTT
{
    class TickTackToe
    {
    private:
        int scoreX_;
        int scoreO_;
        static const char Nought_ = 'O';
        static const char Cross_ = 'X';
        char field_[3][3];
        enum Player_ {Nought, Cross};
        Player_ player;

    public:
        TickTackToe();
        ~TickTackToe() {};

        bool isFull();
        char ifWin();
        int Xscore() const {return scoreX_;}
        int Oscore() const {return scoreO_;}
        void play(int w, int k);
        //void ShowScore() const;
        void ShowField() const;
    };
}



#endif // KIH_H_INCLUDED
