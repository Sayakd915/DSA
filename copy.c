#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    int char_count = 0, word_count = 0, line_count = 0;

    fp = fopen("input.txt", "r"); 
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        char_count++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (ch == '\n') {
                line_count++; 
            }
            word_count++;
        }
    }

    fclose(fp);
    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);
    return 0;
}