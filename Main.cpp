/*
*Peter MacLellan, Ben Soper
*Lab 1, part b
*
*Main file for Lab 1.  Asks user for input parameters to initialize a 
*Mastermind object which then handles the playing of the game.
*/

#include "Mastermind.h"

using namespace std;

int main()
{
    int codeLength;
    int range;

    //ask for input parameters
    cout << "\nHow long should the secret code be?\n";
    cin >> codeLength;
    cout << "\nWhat is the range for each secret digit?\n";
    cin >> range;

    //initialize Mastermind object and then start game
    Mastermind game = Mastermind(codeLength, range);
    game.play();

    system("Pause");
    return 0;
} // End main().



