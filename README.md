This folder contains C solutions for the three problems and the final key.

## Files
- `problem1.c` — Grid Rotation → computes Clue 1.
  - Reads `inputs/grid.txt` and `inputs/directions.txt`.
  - Rotates each row one step (L or R).
  - Selects the middle row (index floor(n/2)).
  - Sums ASCII integer values of characters in the middle row.
  - Output: `Clue 1 = 385` (hex: `181`).

- `problem2.c` — Multi-pass String Process → computes Clue 2.
  - Reads `inputs/input2.txt`.
  - Steps: Reverse → remove every 3rd char → shift ASCII +2 → count vowels.
  - Output: `Clue 2 = 4`.

- `problem3.c` — State Machine → computes Clue 3.
  - Reads `inputs/states.txt`.
  - Interpretation used:
    - Prime numbers: direct transition to DONE.
    - Even numbers: advance and eventually reach DONE.
    - Odd composite numbers: do not advance to DONE.
  - Output: `Clue 3 = 7`.

- `final_key.txt`
  - Contains the final key in the required format:
    181-4444444

