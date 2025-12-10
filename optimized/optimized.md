Optimization Explanation — Problem 1

The original code rotated each row using manual character-by-character loops.
Example:
    for (int j = n-1; j > 0; j--)
        grid[i][j] = grid[i][j-1];

This works but is slower and harder to maintain.
Optimized Method

The optimized version uses memmove(), which copies blocks of memory efficiently.
Right rotation:
    char last = grid[i][n-1];
    memmove(grid[i] + 1, grid[i], n - 1);
    grid[i][0] = last;

Left rotation:
    char first = grid[i][0];
    memmove(grid[i], grid[i] + 1, n - 1);
    grid[i][n-1] = first;

Why This Is Better?

 memmove() is faster because it uses optimized low-level instructions.
 Code becomes shorter and easier to read.
 Produces the same correct result:
      Clue 1 = 385

