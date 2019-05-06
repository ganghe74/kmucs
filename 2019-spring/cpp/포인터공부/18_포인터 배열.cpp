#include <stdio.h>
int main() {
    char *arps[] = {"cat", "dog", "gorilla", "pig", "worm"};
    int i;

    for (i=0;i<5;++i) {
        printf("%s\n", arps[i]);
    }
}