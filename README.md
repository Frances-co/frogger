Here is a `README.md` file for your game:

---

# Frogger Game

## Overview

This is a simple console-based **Frogger Game** implemented in C, where the player controls a character (represented by `*`) navigating through moving tiles (represented by `254`). The goal is to avoid crashing into the tiles as they shift left and right across the game board.

## Gameplay

- The player controls a frog (`*`) trying to reach the top of the game board.
- The frog can move in four directions using the arrow keys or `W`, `A`, `S`, `D` to move **up**, **left**, **down**, and **right**, respectively.
- The tiles on the game board move periodically, shifting left or right depending on the row.
- If the frog collides with a tile while moving, the game ends.
- The game gets progressively challenging as the tiles shift every few frames.

## Controls

- `W` or **Up Arrow**: Move up
- `A` or **Left Arrow**: Move left
- `S` or **Down Arrow**: Move down
- `D` or **Right Arrow**: Move right

## Features

- **Tile Movement**: The tiles on the board shift left or right after every few frames, simulating the movement of cars.
- **Player Movement**: The player can move the frog in four directions to avoid the tiles.
- **Collision Detection**: If the frog moves into a tile, the game ends.
- **Game Over**: After a collision, the game displays a "You Died!" message and waits for the player to press any key before exiting.

## How to Play

1. Clone or download the project.
2. Compile the source code using a C compiler (e.g., GCC, MinGW).
   ```bash
   gcc froggy_game.c -o froggy_game
   ```
3. Run the compiled game.
   ```bash
   ./froggy_game   # For Linux/macOS
   froggy_game.exe  # For Windows
   ```
4. Move the frog using the controls mentioned above to avoid hitting the tiles.
5. If you collide with a tile, the game will display the "You Died!" message, and you can exit by pressing any key.

## Code Structure

- **Board Representation**: The game board is a 2D array of integers, where each integer represents an ASCII code of the characters on the board. The frog is represented by `*` (ASCII code `42`), and the tiles are represented by `254`.
  
- **Main Functions**:
  - `shiftRight()`: Shifts the tiles to the right on specified rows.
  - `shiftLeft()`: Shifts the tiles to the left on specified rows.
  - `move()`: Handles the player's movement based on key presses.
  - `printBoard()`: Prints the current state of the game board.
  - `gameOver()`: Handles game over conditions and displays a message.

## How to Modify

- **Adjust Game Speed**: The `Sleep(150)` controls the delay between frames. You can modify this value to change the game speed.
- **Adjust Shift Interval**: The tiles shift every `5` frames by default. You can change the value of `shiftInterval` to make the tiles move slower or faster.
  
## Requirements

- C Compiler (GCC, MinGW, etc.)
- Windows (uses `<windows.h>` for `Sleep()` function) or modify the code for cross-platform use.

## Future Enhancements

- Add levels of difficulty.
- Include power-ups to help the player avoid collisions.
- Improve visual representation with colors or advanced graphics libraries.

## License

This project is open-source and free to modify and distribute.

---

This `README.md` provides details about the gameplay, how to compile and play the game, as well as a description of the code structure and potential modifications.
