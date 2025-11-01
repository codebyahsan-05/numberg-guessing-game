echo "Building statically linked executable..."
echo

if ! command -v g++ &> /dev/null; then
    echo "ERROR: g++ not found! Please install GCC."
    exit 1
fi

g++ -std=c++17 -Wall -Wextra -pedantic -O3 -static-libgcc -static-libstdc++ -o number-guessing-game-static main.cpp

if [ $? -eq 0 ]; then
    echo
    echo "========================================"
    echo "Build successful!"
    echo "========================================"
    echo
    echo "Created: number-guessing-game-static"
    echo
    echo "This executable should work on machines with compatible glibc versions."
    echo "For maximum portability, consider building on an older Linux distribution."
    echo
else
    echo
    echo "========================================"
    echo "Build failed!"
    echo "========================================"
    echo
    exit 1
fi

