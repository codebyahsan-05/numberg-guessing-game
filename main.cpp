#include <iostream>
#include <random>
#include <limits>
#include <string>
#include <utility>

class NumberGuessingGame {
private:
    int secretNumber;
    int minRange;
    int maxRange;
    int attempts;
    std::mt19937 rng;

    void initializeRandom() {
        std::random_device rd;
        rng.seed(rd());
    }

    void generateSecretNumber() {
        std::uniform_int_distribution<int> dist(minRange, maxRange);
        secretNumber = dist(rng);
    }

    bool isValidInput(int guess) const {
        return guess >= minRange && guess <= maxRange;
    }

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int getUserGuess() {
        int guess;
        while (true) {
            std::cout << "Enter your guess (" << minRange << "-" << maxRange << "): ";
            
            if (std::cin >> guess) {
                if (isValidInput(guess)) {
                    return guess;
                } else {
                    std::cout << "Invalid input! Please enter a number between " 
                              << minRange << " and " << maxRange << ".\n";
                }
            } else {
                std::cout << "Invalid input! Please enter a valid number.\n";
                clearInputBuffer();
            }
        }
    }

    void displayHint(int guess) const {
        int difference = std::abs(guess - secretNumber);
        int rangeSize = maxRange - minRange;
        
        int largeThreshold = rangeSize / 10; 
        int mediumThreshold = rangeSize / 20;
        
        if (difference > largeThreshold) {
            std::cout << (guess > secretNumber ? "Way too high!" : "Way too low!") << "\n";
        } else if (difference > mediumThreshold) {
            std::cout << (guess > secretNumber ? "Too high!" : "Too low!") << "\n";
        } else {
            std::cout << (guess > secretNumber ? "A bit too high!" : "A bit too low!") << "\n";
        }
    }

    void displayWelcome() const {
        std::cout << "\n========================================\n";
        std::cout << "   Welcome to Number Guessing Game!\n";
        std::cout << "========================================\n";
        std::cout << "I'm thinking of a number between " 
                  << minRange << " and " << maxRange << ".\n";
        std::cout << "Can you guess it?\n\n";
    }

    void displayWinMessage() const {
        std::cout << "\n🎉 Congratulations! You guessed it! 🎉\n";
        std::cout << "The number was: " << secretNumber << "\n";
        std::cout << "Total attempts: " << attempts << "\n";
        
        if (attempts == 1) {
            std::cout << "Perfect guess! You're amazing! 🏆\n";
        } else if (attempts <= 3) {
            std::cout << "Excellent work! 👏\n";
        } else if (attempts <= 7) {
            std::cout << "Good job! 👍\n";
        } else {
            std::cout << "Nice try! Keep practicing! 💪\n";
        }
        std::cout << "\n";
    }

    bool playAgain() {
        char choice;
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> choice;
        clearInputBuffer();
        return (choice == 'y' || choice == 'Y');
    }

    void setRange(int min, int max) {
        if (min < max) {
            minRange = min;
            maxRange = max;
        }
    }

public:
    static void displayGameMenu() {
        std::cout << "\n========================================\n";
        std::cout << "   Number Guessing Game - Difficulty\n";
        std::cout << "========================================\n";
        std::cout << "Choose your difficulty level:\n\n";
        std::cout << "1. Easy     (1 - 10)    - Perfect for beginners\n";
        std::cout << "2. Medium   (1 - 50)    - Good challenge\n";
        std::cout << "3. Hard     (1 - 100)   - Classic mode\n";
        std::cout << "4. Expert   (1 - 500)   - For the brave\n";
        std::cout << "5. Custom   - Choose your own range\n";
        std::cout << "========================================\n";
        std::cout << "Enter your choice (1-5): ";
    }

    static int getValidInt(const std::string& prompt, int minValue = std::numeric_limits<int>::min(), 
                          int maxValue = std::numeric_limits<int>::max()) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                if (value >= minValue && value <= maxValue) {
                    return value;
                } else {
                    std::cout << "Invalid input! Please enter a number between " 
                              << minValue << " and " << maxValue << ".\n";
                }
            } else {
                std::cout << "Invalid input! Please enter a valid number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    static std::pair<int, int> selectDifficulty() {
        int choice;
        int min = 1, max = 100;
        
        displayGameMenu();
        choice = getValidInt("", 1, 5);
        
        switch (choice) {
            case 1:
                min = 1; max = 10;
                std::cout << "\n✓ Selected: Easy Mode (1-10)\n";
                break;
            case 2:
                min = 1; max = 50;
                std::cout << "\n✓ Selected: Medium Mode (1-50)\n";
                break;
            case 3:
                min = 1; max = 100;
                std::cout << "\n✓ Selected: Hard Mode (1-100)\n";
                break;
            case 4:
                min = 1; max = 500;
                std::cout << "\n✓ Selected: Expert Mode (1-500)\n";
                break;
            case 5: {
                std::cout << "\n--- Custom Range ---\n";
                min = getValidInt("Enter minimum number: ", 1, 999999);
                max = getValidInt("Enter maximum number: ", min + 1, 1000000);
                std::cout << "\n✓ Selected: Custom Range (" << min << "-" << max << ")\n";
                break;
            }
        }
        
        return {min, max};
    }

    NumberGuessingGame(int min = 1, int max = 100) 
        : minRange(min), maxRange(max), attempts(0) {
        initializeRandom();
    }

    void play() {
        do {
            generateSecretNumber();
            attempts = 0;
            displayWelcome();

            int guess;
            bool gameWon = false;

            while (!gameWon) {
                guess = getUserGuess();
                ++attempts;

                if (guess == secretNumber) {
                    gameWon = true;
                    displayWinMessage();
                } else {
                    displayHint(guess);
                }
            }
        } while (playAgain());

        std::cout << "Thanks for playing! Goodbye! 👋\n";
    }
};

int main() {
    std::cout << "\n";
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║   Welcome to Number Guessing Game!    ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n";
    
    auto [minRange, maxRange] = NumberGuessingGame::selectDifficulty();
    
    NumberGuessingGame game(minRange, maxRange);
    game.play();
    
    return 0;
}

