#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    fp = fopen("output.txt", "a"); 
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    printf("Enter data to append to file: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data); 

    fclose(fp);
    printf("Data appended to file successfully\n");
    return 0;
}