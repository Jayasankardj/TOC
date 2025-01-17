#include <stdio.h>
#include <stdbool.h>

bool isValidString(const char *str) {
    enum State { q0, q1, q2 };
    enum State currentState = q0;
    int i;
    for ( i = 0; str[i] != '\0'; i++) {
        switch (currentState) {
            case q0:
                if (str[i] == '0') {
                    currentState = q1;
                } else {
                    
                    return false;
                }
                break;
            case q1:
                if (str[i] == '0') {
                    currentState = q2;
                } else if (str[i] == '1') {
                    currentState = q1;
                } else {
                    
                    return false;
                }
                break;
            case q2:
                if (str[i] == '0') {
                    currentState = q2;
                } else if (str[i] == '1') {
                    currentState = q1;
                } else {
                    
                    return false;
                }
                break;
        }
    }
    
    return (currentState == q2);
}

int main() {
    char str[100];
    
    printf("Enter a binary string: ");
    scanf("%s", str);
    
    if (isValidString(str)) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is rejected.\n");
    }
    
    return 0;
}
