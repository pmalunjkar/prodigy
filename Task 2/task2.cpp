#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!" << endl;

    do {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " correctly in " << attempts << " attempts." << endl;
        }
    } while (guess != randomNumber);

    return 0;
}
