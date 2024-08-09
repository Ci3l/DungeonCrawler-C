# Rogue-Like Dungeon Crawler in C

## Table of Contents
1. [Project Overview](#project-overview)
2. [Goals](#goals)
3. [Features](#features)
4. [Development Steps](#development-steps)
5. [Learning Log](#learning-log)
6. [Installation and Usage](#installation-and-usage)
7. [Future Improvements](#future-improvements)

---

## Project Overview
This project involves creating a text-based Rogue-Like Dungeon Crawler game in C. The objective is to navigate a procedurally generated dungeon, battle monsters, gather items, and escape. This project is designed to prepare me for a course in my second year of a Bachelor’s program in Mathematical and Computational Sciences (MIDO) at Paris-Dauphine. It serves as a practical exercise in C programming, encompassing key topics such as control structures, functions, pointers, dynamic memory management, and file handling.

## Goals
- **Preparation for Advanced C Programming**: This project is designed to cover all key concepts that will be explored in an upcoming university course. By completing this project, I aim to solidify my understanding of the C language and be well-prepared for the coursework.
- **Learning by Doing**: The project is structured to encourage hands-on learning, with each development step tied to specific programming concepts. I will document my learning progress at each stage.
- **Creating a Fun, Playable Game**: Beyond academic goals, I want to build a game that is both enjoyable and challenging to play, demonstrating how C programming can be used in creative and practical ways.

## Features
- **Random Dungeon Generation**: The dungeon layout is randomly generated with multiple rooms and connecting corridors, ensuring a unique experience each time the game is played.
- **Entity Management**: Players and monsters are represented by entities with attributes like health, attack power, and position.
- **Turn-Based Combat**: The game features a simple yet engaging turn-based combat system where the player can attack monsters, and monsters can retaliate.
- **Inventory System**: Players can collect and use items, such as potions and weapons, that affect gameplay.
- **Input/Output Handling**: A user-friendly, text-based interface allows players to control their character and interact with the game environment.
- **Save/Load Functionality**: Players can save their progress and load the game later, ensuring the experience can be paused and resumed.
- **Random Events and Traps**: The dungeon contains random events and traps, adding unpredictability and challenge to the game.
- **Memory Management**: Efficient memory management using pointers and dynamic allocation is implemented to handle game entities and data.

## Development Steps
1. **Dungeon Generation**: Implement the algorithm for creating a random dungeon layout with rooms and corridors.
2. **Entity Creation**: Define structures for player and monster entities, initializing their attributes and positions in the dungeon.
3. **Movement and Collision Detection**: Implement player movement, ensuring collisions with walls or other entities are handled properly.
4. **Combat Mechanics**: Develop the turn-based combat system, enabling the player to engage monsters in battle.
5. **Inventory Management**: Create an inventory system for collecting and using items found in the dungeon.
6. **Input Handling**: Design functions to capture and process player inputs, integrating movement, combat, and inventory management.
7. **Game Interface**: Build the text-based interface that displays the dungeon, player stats, and game messages.
8. **Saving and Loading**: Implement functionality to save and load the game state, allowing for persistent gameplay.
9. **Random Events**: Add random events and traps that trigger as the player explores the dungeon.
10. **Final Testing and Debugging**: Conduct comprehensive testing to ensure all features work correctly, optimizing the code as needed.

## Learning Log
I will use this section to document what I have learned at each stage of development, noting any challenges faced and how they were overcome.

### Dungeon Generation
- **Concepts Learned**: 
- **Challenges**: 

## Installation and Usage
### Prerequisites
- A C compiler (GCC recommended)
- Make

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Rogue-Like-Dungeon-Crawler.git
   ```
2. Navigate to the project directory and build the project:
   ```bash
   cd Rogue-Like-Dungeon-Crawler
   make
   ```

### Running the Game
```bash
./dungeon_crawler
```
Follow the on-screen instructions to play the game.

## Future Improvements
- **Graphics Upgrade**: Transition from ASCII art to a simple graphical interface using a library like SDL.
- **Expanded Combat System**: Introduce more complex combat mechanics, such as magic or ranged attacks.
- **Enhanced Dungeon Features**: Add more room types, secret areas, and puzzles to solve.
