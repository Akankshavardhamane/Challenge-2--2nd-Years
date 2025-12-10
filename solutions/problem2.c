#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUF 4096

static void strip_crlf(char *s) {
    int n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) { s[--n] = '\0'; }
}
static int is_vowel(char ch) {
    char c = (char)ch;
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
        || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}
int main(void) {
    FILE *f = fopen("inputs/input2.txt", "r");
    if (!f) {
        fprintf(stderr, "Error: inputs/input2.txt not found\n");
        return 1;
    }
    char buf[BUF];
    if (!fgets(buf, sizeof(buf), f)) {
        fprintf(stderr, "Error: cannot read inputs/input2.txt or file empty\n");
        fclose(f);
        return 1;
    }
    fclose(f);
    strip_crlf(buf);
    int n = (int)strlen(buf);
    char *rev = malloc(n + 1);
    if (!rev) { perror("malloc"); return 1; }
    for (int i = 0; i < n; ++i) rev[i] = buf[n-1-i];
    rev[n] = '\0';
    int k = 3;
    char *removed = malloc(n + 1);
    if (!removed) { free(rev); perror("malloc"); return 1; }
    int ri = 0;
    for (int i = 0; i < n; ++i) {
        int pos1 = i + 1;
        if (pos1 % k == 0) continue;
        removed[ri++] = rev[i];
    }
    removed[ri] = '\0';
    for (int i = 0; i < ri; ++i) {
        unsigned char ch = (unsigned char)removed[i];
        removed[i] = (char)(ch + 2);
    }
    int vowel_count = 0;
    for (int i = 0; i < ri; ++i) {
        if (is_vowel(removed[i])) ++vowel_count;
    }
    printf("Clue 2 = %d\n", vowel_count);
    free(rev);
    free(removed);
    return 0;
}
