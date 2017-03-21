#include<stdio.h>
#include<string.h>

int main(void) {
    // UTF-8 is 3 byte long.
    int W = 3;
    // Input
    char str[256];
    scanf("%s", str);
    int len = strlen(str);
    // Output
    for (int i = len - W; i >= 0; i -= W) {
        for (int j = 0; j < W; j++) {
            printf("%c", str[i+j]);
        }
    }
    printf("\n");
    return 0;
}
