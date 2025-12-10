#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;
    int r = (int)floor(sqrt((double)n));
    for (int i = 3; i <= r; i += 2) if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    FILE *f = fopen("inputs/states.txt", "r");
    if (!f) {
        fprintf(stderr, "Error: inputs/states.txt not found\n");
        return 1;
    }

    int value;
    int done_count = 0;
    while (fscanf(f, "%d", &value) == 1) {
        if (is_prime(value)) {
            done_count++;
        } else if (value % 2 == 0) {
            done_count++;
        } else {
        }
    }
    fclose(f);
    printf("Clue 3 = %d\n", done_count);
    return 0;
}
