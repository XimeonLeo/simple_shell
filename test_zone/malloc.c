#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "Testing";
    char str2[] = "single";
    char str3[] = "freeing";
    char *dup1 = NULL, *dup2 = NULL, *dup3 = NULL;

    dup1 = malloc(sizeof(char) * (strlen(str) + 1));
    dup2 = malloc(sizeof(char) * (strlen(str2) + 1));
    dup3 = malloc(sizeof(char) * (strlen(str3) + 1));

    strcpy(dup1, str);
    strcpy(dup2, str2);
    strcpy(dup3, str3);

    printf("%s\n", dup1);
    printf("%s\n", dup2);
    printf("%s\n", dup3);

    free(dup1), free(dup2), free(dup3);

    return 0;
}

