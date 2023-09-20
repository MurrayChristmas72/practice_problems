#include <stdio.h> // printf() ; getline()
#include <stdlib.h> // free()
#include <string.h> // strlen()
#include <stdbool.h> // bool function


bool isunique (char * input);


int main(void)
{
    char *input = NULL;
    size_t input_size_bytes = 0;

    printf("Enter a String: ");

    // take string input from user
    // check it for errors
    // store the input && input_size locally (as opposed to separate file)

    if (getline(&input, &input_size_bytes, stdin) != -1)  //getline() returns -1 if it fails to read an input
    {
        if (isunique(input) == true)
        {
            printf("Your string is unique\n");
            free(input);
            return 0;
        }
        else
        {
            printf("Your string is not unique\n");
            free(input);
            return 0;
        }
        
    }
    else
    {
        printf("Error reading input\n");
        return 1;
    }

    // fgets(input, 100, stdin);

return 0;
}


bool isunique (char * input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j < strlen(input); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (input[i] == input[j])
            {
                return false;
            }
        }
    }
    return true;
}