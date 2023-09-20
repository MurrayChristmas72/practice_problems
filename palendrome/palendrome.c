#include <stdio.h>  // printf() ; getline()
#include <string.h>  // strlen()
#include <stdbool.h>

int main(void)
{

    bool palendrome;

    // take string input from user
    char *input = NULL;
    size_t input_size_in_bytes = 0;
    printf("Enter the string: ");
    if (getline(&input, &input_size_in_bytes, stdin) == -1)  // returns -1 if fails to return input
    {
        printf("Error\n");
        return 1;
    }
    if (input == NULL)
    {
        printf("Error\n");
        return 1;
    }

    int input_length = strlen(input) - 1;  // don't count \n as a character
    int space_counter = 0;
    for (int i = 0; i < strlen(input) - 1; i++)
    {
        if (input[i] == ' ')
        {
            space_counter++;
        }
    }
    input_length = input_length - space_counter;

    // check for palendrome
    if (input_length % 2 == 0)  // even number
    {
        // each letter should have a double
        int counter[strlen(input) - 1];  // for each letter
        for (int i = 0; i < strlen(input) - 1; i++)
        {
            counter[i] = 0;
        }

        for (int i = 0; i < strlen(input) - 1; i++)
        {
            if ( (input[i] == ' ') )
            {
                continue;
            }
            counter[i]++;
            for (int j = 0; j < strlen(input) - 1; j++)
            {
                if ( (input[j] == ' ') )
                {
                    continue;
                }
                if (i == j)
                {
                    continue;
                }
                if (input[i] == input[j])
                {
                    counter[i]++;
                }
            }
        }

        // cycle thru counter[] array. if ther's a value other than 2 or 0, palendrome = false
        for (int i = 0; i < strlen(input) - 1; i++)
        {
            if ( (counter[i] != 2) && (counter[i] != 0) )
            {
                palendrome = false;
                return 0;
            }
            if (i == strlen(input) - 2)
            {
                palendrome = true;
            }
        }

    }

    else
    {
        // each letter should have a double
        int counter[strlen(input) - 1];  // for each letter
        for (int i = 0; i < strlen(input) - 1; i++)
        {
            counter[i] = 0;
        }

        for (int i = 0; i < strlen(input) - 1; i++)
        {
            if ( (input[i] == ' ') )
            {
                continue;
            }
            counter[i]++;
            for (int j = 0; j < strlen(input) - 1; j++)
            {
                if ( (input[j] == ' ') )
                {
                    continue;
                }
                if (i == j)
                {
                    continue;
                }
                if (input[i] == input[j])
                {
                    counter[i]++;
                }
            }
        }

        // cycle thru counter[] array. if ther's a value other than 2 or 0, palendrome = false
        int one_checker = 0;
        for (int i = 0; i < strlen(input) - 1; i++)
        {
            if (counter[i] == 1)
            {
                one_checker++;
            }
            if ( (counter[i] != 2) && (counter[i] != 1) && (counter[i] != 0))
            {
                palendrome = false;
                return 0;
            }
            if ( (i == strlen(input) - 2) && (one_checker == 1) )
            {
                palendrome = true;
            }
        }
    }
    
}