/*
*Peter MacLellan, Ben Soper
*Lab 1, part b
*
*Header file for the Code class.  Contains the declarations and
*implementations for the member functions checkCorrect, checkIncorrect,
*and getSecretCode.
*/

#include "d_random.h"
#include <vector>
#include <algorithm>

using namespace std;

class Code
{
public:
    // Constructor:
    Code(int n, int m);
    Code();

    // Member Methods:
    int checkCorrect(const vector<int> &guess);
    int checkIncorrect(const vector<int> &guess);

    // Getter Methods:
    vector<int> getSecretCode();

    vector<int> correctLocation;
    // Helper vector to hold a list of correctly guessed digits.
    vector<int> incorrectLocation;

private:
    int codeLength;
    // Represents the number of digits in the secretCode vector
    int range;
    // Represents the range of values for each digit of the code.
    vector<int> secretCode;
    // Holds that sequence of numbers that the player is trying to guess.
   
}; // end Code class

Code::Code(int n, int m)
// Constructor for Code class.  Sets codelength and number range and then
// initializes a random code vector
{
    codeLength = n;
    range = m;

    randomNumber rand(1111);

    for (int i = 0; i < codeLength; ++i)
    {
        secretCode.push_back(rand.random(range));
    }
}

Code::Code()
{
    Code(1, 1);
}
int Code::checkCorrect(const vector<int> &guess)
// Public member function of Code class.  Takes a guess vector as a 
// parameter and returns the number of digits that match the code
// in the correct position.
{
    correctLocation.clear();
    // Reset number of correct digits for each guess.

    for (int i = 0; i < codeLength; i++)
    {
        // Loop through each digit of the two vectors.
        if (guess.at(i) == secretCode.at(i))
        {
            correctLocation.push_back(guess.at(i));
            correctLocation.push_back(i);
            // If the digits match in the proper place, the correct digit
            // is added to a vector which will be used in the 
            // checkIncorrect method (not yet implemented).
        }
    }

    return correctLocation.size() / 2;
    // Size of the correctLocation vector is the number of digits
    // that match the sercetCode and are in the correct place.
}

int Code::checkIncorrect(const vector<int> &guess)
{
    // Public member function of Code class.  Takes a guess vector as a 
    // parameter and returns the number of digits that match the code
    // in the incorrect position.
    int counter = 0;
    bool shouldAdd = false;

    //clear vector each time a new guess is being checked
    incorrectLocation.clear();

    for (int i = 0; i < guess.size(); i++)
    {
        //reset the flag for each new digit being checked, don't add by default
        shouldAdd = false;

        for (int j = 0; j < secretCode.size(); j++)
        {
            //reset flag again
            shouldAdd = false;

            if ((guess.at(i) == secretCode.at(j)) && (i != j))
            {
                //if guess digit matches one in secretCode but in a different
                //location, consider it to be added
                shouldAdd = true;

                for (int m = 1; m < correctLocation.size(); m+=2)
                {
                    //check if the digit is already in the 
                    //correctLocation vector, don't add if it is
                    if (correctLocation.at(m) == j)
                    {
                        shouldAdd = false;
                    }
                }

                for (int k = 0; k < incorrectLocation.size(); k++)
                {
                    //check if digit has already been counted as being in
                    //an incorrect location
                    if (guess.at(i) == incorrectLocation.at(k))
                    {
                        shouldAdd = false;
                    }
                }
                
                //if the digit passed all the checks, 
                //add it to incorrectLocation
                if (shouldAdd)
                {
                    incorrectLocation.push_back(guess.at(i));
                }
            } // end if
        } // end secretCode for
    } // end guess for

    //size of incorrectLocation vector gives the number of incorrect 
    //digits to be displayed to the player
    return incorrectLocation.size();
}


vector<int> Code::getSecretCode()
// Simple getter method.  Returns the sercetCode vector.
{
    return secretCode;
}
