#include <stdio.h>
#include <string.h>

int isAccepted(char *str) 
{
    int state = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) 
    {
        char c = str[i];

        switch (state) 
        {
            case 0: 
                if (c == '0') state = 1;
                else return 0; 
                break;
            case 1: 
                if (c == '1') state = 2;
                else state = 2;
                break;
            case 2: 
                if (c == '1') state = 2;
                else state = 2;
                break;
            default:
                return 0; 
        }
    }

    return state == 2;
}

int main() 
{
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input)) 
    {
        printf("The string is accepted by the DFA.\n");
    } 
    else 
    {
        printf("The string is rejected by the DFA.\n");
    }

    return 0;
}
