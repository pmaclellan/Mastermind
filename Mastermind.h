/*
*Peter MacLellan, Ben Soper
*Lab 1, part b
*
*Header file for the Mastermind class.  Contains the declarations and
*implementations for the member functions play, hasBeenWon, and overloaded
*operators.
*/

#include "Code.h"

using namespace std;

class Mastermind
{
public:
    //Constructors
    Mastermind();
    Mastermind(int size, int range);

    //Member methods
    void play();
    bool hasBeenWon();

    //Friend operator overloads
    friend ostream &operator << (ostream &ostr, Mastermind &md);
    friend istream &operator >> (istream &istr, Mastermind &md);

private:
    Code secretCode;
    vector<int> guess;
    int maxGuesses;
    int guessCounter;
};

Mastermind::Mastermind(int size, int range)
{
 // User input constructor
    secretCode = Code(size, range);
    guess = vector<int>(size);
    maxGuesses = 10;
    guessCounter = 0;
}

Mastermind::Mastermind()
{
// Default constructor (should never be used)
    secretCode = Code(5, 5);
    maxGuesses = 10;
    guessCounter = 0;
}

bool Mastermind::hasBeenWon()
{
    // returns true if all digits in guess match secret code
    return (secretCode.checkCorrect(guess) == 
            secretCode.getSecretCode().size());
}

void Mastermind::play()
{
//handles the playing of the entire game, called by main
    while (guessCounter < maxGuesses)
    {
        // check if the user has already won
        if (hasBeenWon())
        {
            cout << "You Won!\n";
            return;
        }

        // Guess must be entered one digit at a time, with new lines in between
        cout << "Enter your guess:\n";
        cin >> *this;
        guessCounter++; // increment guess counter to be checked for loss

        //output the secretCode and guess vectors
        cout << *this;

        //output the number of correct and incorrect guesses
        cout << secretCode.checkCorrect(guess) << " ";
        cout <<  secretCode.checkIncorrect(guess) << endl;
    }// end while

    //if guessCounter > maxGuesses, player has lost
    cout << "You Lost!\n";
    return;
}

ostream &operator << (ostream &ostr, Mastermind &md)
{
    for (int i = 0; i < md.secretCode.getSecretCode().size(); i++)
    {
        ostr << md.secretCode.getSecretCode().at(i);
    }
    cout << endl;

    for (int i = 0; i < md.guess.size(); i++)
    {
        ostr << md.guess[i];
    }

    cout << endl;
    return ostr;
}

istream &operator >> (istream &istr, Mastermind &md)
{
    for (int i = 0; i < md.guess.size(); i++)
    {
        istr >> md.guess[i];
    }

    return istr;
}

