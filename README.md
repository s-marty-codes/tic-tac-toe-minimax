# Tic-Tac-Toe MINIMAX: from Stochastic to Optimal
A C++ Tic-Tac-Toe implementation demonstrating the transition from stochastic move selection to an optimal AI strategy implemented via recursive Minimax tree-search.

## Evolution
- **Legacy Version:** originally developed as a programming exercise for a C++ university course. It features basic game mechanics and a computer opponent that selects moves through a uniform random distribution.
- **Modern Version:** currently being refactored as a self-directed personal project to integrate newly learned concepts. I am implementing a Minimax algorithm to transform the game into rational AI agent.

## Cognitive Science Perspective
From a computational modeling standpoint, this project explores the shift between two different decision-making paradigms:
- **Stochastic Baseline:** models a "no-knowledge" agent where choices are made randomly without predictive model.
- **Minimax Rationality:** implements the principle of "Minimax" from Game Theory, simulating an agent with perfect information and infinite cognitive resources (within the limits of the game's state space).

## Technical Implementation
**Language:** C++
**Core Concepts:**
- Recursive Backtracking
- Game Tree Exploration
- Modular Architecture (separation of game rules and AI logic to allow for future code recycling)

## Structure of the current (stochastic) version:
- **`tris.h`**: The header file containing the core definitions. 
- **`tris.cpp`**: The implementation of the game logic.
- **`main.cpp`**: The entry point that initializes the random seed and starts the game loop via `iniziaGioco()`.

## Roadmap
[x] Initial C++ game framework (University project)

[ ] Integration of the Minimax Engine

[ ] Benchmarking: Random vs. Minimax win-rate comparison
