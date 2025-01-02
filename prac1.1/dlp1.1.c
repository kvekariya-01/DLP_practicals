#include <stdio.h>
#include <string.h>

// Function to validate the pattern a*bb
int validatePattern(const char *str) {
    if (str == NULL) {
        return 0;
    }

    int len = strlen(str);
    if (len < 2) {
        return 0;
    }

    if (str[len - 2] != 'b' || str[len - 1] != 'b') {
        return 0;
    }

    for (int i = 0; i < len - 2; i++) {
        if (str[i] != 'a') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];

    printf("D23DCS164\n");
    printf("Enter a string: ");
    scanf("%s", input);

    if (validatePattern(input)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
