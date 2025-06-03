
// A simple command-line game where the user tries to guess a randomly
// generated number within a certain range.

#include <iostream> // Required for input/output operations (cin, cout)
#include <cstdlib>  // Required for std::rand() and std::srand()
#include <ctime>    // Required for std::time() to seed the random number generator

int main() {
    // Seed the random number generator.
    // std::time(nullptr) returns the current calendar time as a time_t object.
    // Using it as a seed ensures that the sequence of random numbers is different
    // each time the program runs.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range for the secret number.
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 1000;

    // Generate a random secret number within the defined range.
    // std::rand() % (MAX_NUMBER - MIN_NUMBER + 1) generates a number from 0 to (MAX_NUMBER - MIN_NUMBER).
    // Adding MIN_NUMBER shifts the range to [MIN_NUMBER, MAX_NUMBER].
    const int secretNumber = std::rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    int guess = 0;        // Variable to store the user's guess
    int guessCount = 0;   // Counter for the number of guesses
    bool guessedCorrectly = false; // Flag to check if the user guessed correctly

    // Display a welcome message and instructions to the user.
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "  Welcome to the Guess the Number Game!   " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "I have picked a number between " << MIN_NUMBER
              << " and " << MAX_NUMBER << ". Try to guess it!" << std::endl;

    // Game loop: continues until the user guesses the correct number.
    while (!guessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> guess; // Read the user's input

        // Increment the guess counter.
        guessCount++;

        // Input validation: Check if the input was valid (e.g., not text).
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard invalid input from the buffer until a newline character is found.
            std::cin.ignore(10000, '\n');
            guessCount--; // Don't count invalid input as a guess
            continue;     // Skip to the next iteration of the loop
        }

        // Provide hints based on the user's guess.
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            std::cout << "Your guess is out of the valid range (" << MIN_NUMBER
                      << " - " << MAX_NUMBER << "). Try again!" << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            // The user guessed correctly!
            guessedCorrectly = true;
            std::cout << "\nCongratulations! You guessed the number " << secretNumber
                      << " in " << guessCount << " guesses!" << std::endl;
        }
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0; // Indicate successful program execution
}
