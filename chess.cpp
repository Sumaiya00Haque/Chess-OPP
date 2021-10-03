#include<iostream>

#include<string>

#include<stdlib.h>


using namespace std;

const int pawn = 100;

const int bishop = 305;

const int knight = 300;

const int rook = 500;

const int queen = 900;

const int king = 2000;

int board[8][8];

const double startup[8][8] = { rook, knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};


void setup (void)
{

    int i, j;

    for (i = 0; i < 8; i++)
    {

        for (j = 0; j < 8; j++)
        {

            board[i][j] = startup[i][j];

        }

    }



}

void printb (void)
{

    using namespace std;

    int a, b;

    string piece;

    for (a = 7; a > -1; a--)
    {

        cout << endl;

        for (b = 0; b < 8; b++)
        {

            switch (board[a][b])
            {

            case 0:

                piece = "-";

                break;

            case pawn:

                piece = "P";

                break;

            case knight:

                piece = "N";

                break;

            case bishop:

                piece = "B";

                break;

            case rook:

                piece = "R";

                break;

            case queen:

                piece = "Q";

                break;

            case king:

                piece = "K";

                break;

            case -pawn:

                piece = "p";

                break;

            case -knight:

                piece = "n";

                break;

            case -bishop:

                piece = "b";

                break;

            case -rook:

                piece = "r";

                break;

            case -queen:

                piece = "q";

                break;

            case -king:

                piece = "k";

                break;

            }

            cout << " " << piece << " ";

        }

    }



    cout << endl << endl;

}



int main (void)
{



    using namespace std;



    cout << "welcome to simple chess 1.0!" << endl ;

    cout << "please enter your moves in 4 letter algebraic" << endl << "(ie e2e4 in lower case only)" << endl;
    cout<<"................Instruction.................."<<endl<<endl;

    cout << "exit = quit, abort = quit, print = displays the board," << endl << "new = new game" << endl << endl;



    string passd;
    setup();



    while (1)
    {



        getline (cin, passd );

        if (passd.substr(0, 4) == "exit" || passd.substr(0, 5) == "abort" || passd.substr(0, 4) == "quit")
        {


            break;

        }

        if (passd.substr(0, 5) == "print")
        {
            printb();

        }

        if (passd.substr(0, 3) == "new")
        {

            setup();

        }

        if (passd.substr(0, 1) >= "a" && passd.substr(0, 1) <= "h" && passd.substr(1, 1) >= "1" && passd.substr(1, 1) <= "8" && passd.substr(2, 1) >= "a" && passd.substr(2, 1) <= "h" && passd.substr(3, 1) >= "1" && passd.substr(3, 1) <= "8")     // this statement makes sure both squares are on the chess board when executing //a move
        {





            int a, b, c, d;




            a = passd[0] - 'a';

            b = passd[1] - '1';

            c = passd[2] - 'a';

            d = passd[3] - '1';


            board[d][c] = board[b][a];

            board[b][a] = 0;



            printb();

        }

    }

}

