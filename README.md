# 🎮 Number Guessing Game

A fun and interactive console-based number guessing game written in C++. Test your intuition and logical thinking by guessing a randomly generated number within a specified range!

## 📖 Description

This is a classic number guessing game where the computer generates a random number, and you have to guess it! The game provides intelligent hints ("too high", "too low", etc.) to guide you toward the correct answer. Features multiple difficulty levels, adaptive hint system, and robust input validation.

## ✨ Features

- **🎯 Multiple Difficulty Levels**
  - **Easy**: Numbers from 1-10 (perfect for beginners)
  - **Medium**: Numbers from 1-50 (good challenge)
  - **Hard**: Numbers from 1-100 (classic mode)
  - **Expert**: Numbers from 1-500 (for the brave!)
  - **Custom**: Set your own range (min and max values)

- **💡 Smart Hint System**
  - Adaptive hints that adjust based on range size
  - Three levels of feedback:
    - "Way too high/low" - when you're far off
    - "Too high/low" - when you're getting closer
    - "A bit too high/low" - when you're very close

- **📊 Performance Tracking**
  - Tracks your number of attempts
  - Provides encouraging feedback based on your performance:
    - 🏆 Perfect guess (1 attempt)
    - 👏 Excellent (2-3 attempts)
    - 👍 Good job (4-7 attempts)
    - 💪 Keep practicing (8+ attempts)

- **🔒 Input Validation**
  - Robust error handling for invalid inputs
  - Prevents crashes from non-numeric input
  - Validates range boundaries

- **🔄 Play Again Feature**
  - Option to play multiple rounds
  - Maintains difficulty level between games

- **⚙️ Professional Code Quality**
  - Object-oriented design with clean class structure
  - Uses modern C++17 features
  - Optimized with compiler flags (-O3)
  - Cross-platform compatible (Windows, Linux, macOS)

## 🛠️ Requirements

- **Compiler**: GCC (g++) 7.0+ or Clang 5.0+ with C++17 support
- **Operating System**: Windows, Linux, or macOS
- **No external dependencies** - uses only C++ Standard Library

## 📦 Compilation

### Windows (using MinGW/MSYS2 or Visual Studio)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O3 -o number-guessing-game.exe main.cpp
```

### Linux/macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O3 -o number-guessing-game main.cpp
```

### Using Clang (alternative)

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic -O3 -o number-guessing-game main.cpp
```

## 🚀 How to Run

### Windows
```bash
.\number-guessing-game.exe
```

### Linux/macOS
```bash
./number-guessing-game
```

## 🎮 How to Play

1. **Choose Difficulty**: When the game starts, select a difficulty level (1-5) or choose custom range
2. **Guess the Number**: Enter your guess when prompted
3. **Follow Hints**: Use the hints ("too high", "too low") to narrow down your guesses
4. **Win**: Keep guessing until you find the secret number!
5. **Play Again**: After winning, you can choose to play another round

### Example Gameplay

```
╔════════════════════════════════════════╗
║   Welcome to Number Guessing Game!    ║
╚════════════════════════════════════════╝

========================================
   Number Guessing Game - Difficulty
========================================
Choose your difficulty level:

1. Easy     (1 - 10)    - Perfect for beginners
2. Medium   (1 - 50)    - Good challenge
3. Hard     (1 - 100)   - Classic mode
4. Expert   (1 - 500)   - For the brave
5. Custom   - Choose your own range
========================================
Enter your choice (1-5): 3

✓ Selected: Hard Mode (1-100)

========================================
   Welcome to Number Guessing Game!
========================================
I'm thinking of a number between 1 and 100.
Can you guess it?

Enter your guess (1-100): 50
Too high!

Enter your guess (1-100): 25
A bit too low!

Enter your guess (1-100): 30

🎉 Congratulations! You guessed it! 🎉
The number was: 30
Total attempts: 3
Excellent work! 👏

Would you like to play again? (y/n): n
Thanks for playing! Goodbye! 👋
```

## 🏗️ Project Structure

```
number-guessing-game/
│
├── main.cpp          # Main source file containing game logic
├── README.md         # This file
└── number-guessing-game(.exe)  # Compiled executable (generated)
```

## 🔧 Technical Details

- **Language**: C++17
- **Paradigm**: Object-Oriented Programming
- **Random Generation**: Uses `std::mt19937` (Mersenne Twister) seeded with `std::random_device` for cryptographically secure randomness
- **Memory Management**: Automatic (RAII principles)
- **Compilation Flags**:
  - `-std=c++17`: C++17 standard
  - `-Wall -Wextra -pedantic`: Maximum compiler warnings
  - `-O3`: Maximum optimization

## 📝 Code Highlights

- **Clean Class Design**: Encapsulation with private member variables and public interface
- **Static Methods**: For utility functions that don't require instance data
- **Input Validation**: Comprehensive error handling for user input
- **Adaptive Algorithms**: Hint system scales with range size
- **Modern C++**: Uses structured bindings, auto keywords, and STL containers

## 🤝 Contributing

Feel free to fork this project and submit pull requests! Some ideas for improvements:
- Add a high score tracking system
- Implement different hint modes (numerical distance, percentage-based)
- Add a timer/race mode
- Create a GUI version
- Add multiplayer support

## 📄 License

This project is open source and available for educational purposes. Feel free to use, modify, and distribute as needed.

## 👨‍💻 Author

Created as a learning project to demonstrate C++ fundamentals, object-oriented programming, and game logic implementation.

## 🙏 Acknowledgments

- Built using C++ Standard Library
- Inspired by classic number guessing games

---

**Enjoy playing! Have fun guessing! 🎲**

