# Mastermind
Lab 1 from Optimization Methods (EECE3326).  Prompts the user to enter guesses for a secret code.

From project description:

In this project, you will write a complete program that allows the user to play a game of Mastermind
against the computer. A Mastermind game has the following steps:

1. The user is prompted to enter two integers: the code length n, and the range of digits m.
2. The computer selects a code: A random sequence of n digits, each of which is in the range
   [0,m-1].
3. The user is prompted to enter a guess, an n-digit sequence.
4. The computer responds by printing two values that indicate how close the guess is to the
   code. The first response value is the number of digits that are the right digit in the right
   location. The second response value is the number of digits that are the right digit in the
   wrong location.
   For example if the code is 1, 2, 3, 4, 5 and the guess is 5, 0, 3, 2, 6, the response would be 1, 2
   because one digit (3) is the right digit in the right location, and two digits (2 and 5) are the
   right digits in the wrong locations.
   Note that no digit in the code or guess is counted more than once. If the code is 1, 2, 3, 4, 5
   and the guess is 2, 1, 2, 2, 2, the response is 0, 2. If the code is 3, 2, 3, 3, 3 and the guess is
   1, 3, 3, 4, 5, the response is 1, 1.
5. The user is prompted to continue entering guesses. The user wins if the correct code is
   guessed. The user loses if a predetermined maximum number of guesses has been made.
   
The version of the program you submit should print the secret code to the screen before the game
starts. We will use this information to see if your program is working correctly.

*Note: Implementation should be separated from .h files and put into .cpp, but there was some issue with the TA's getting linker errors or something so that's why it isn't.
