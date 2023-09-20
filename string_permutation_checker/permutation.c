#include <stdio.h> // printf() ; getline()
#include <stdlib.h> // free()
#include <string.h> // strlen()
#include <stdbool.h> // bool function


bool ispermutation (char * input_1, char * input_2);


int main(void)
{
    char *input_1 = NULL;
    char *input_2 = NULL;
    size_t input_1_size_bytes = 0;
    size_t input_2_size_bytes = 0;

    // take 2 tring inputs from user
    // check them for errors

    printf("Enter the first string: ");
    if (getline(&input_1, &input_1_size_bytes, stdin) == -1)   //getline() returns -1 if it fails to read an input
    {
        printf("Error reading input\n");
        return 1;
    }
    if (input_1 == NULL)
    {
        printf("Error: Null pointer\n");
        return 1;
    }

    printf("Enter the second string: ");
    if (getline(&input_2, &input_2_size_bytes, stdin) == -1)    //getline() returns -1 if it fails to read an input
    {
        printf("Error reading input\n");
        return 1;
    }
    if (input_2 == NULL)
    {
        printf("Error: Null pointer\n");
        return 1;
    }

    if (ispermutation(input_1, input_2) == true)
    {
        printf("Is a permutation\n");
        free(input_1);
        free(input_2);
        return 0;
    }
    else
    {
        printf("Not a permuation\n");
        free(input_1);
        free(input_2);
        return 0;
    }
        
return 0;
}


bool ispermutation (char * input_1, char * input_2)
{
    // check for constraints :
    // strings have to have the same length
    if (strlen(input_1) != strlen(input_2))
    {
        printf("Exiting program: String length mismatch\n");
        exit(0);
    }

    /*
    * strings cannot be the same word
    * because of the if statement on line 58, we can assume this will be checking 2 strings of equal length
    */
    for (int i  = 0; i < strlen(input_1); i++)
    {
        if (input_1[i] != input_2[i])
        {
            break; //words are not the same, move on
        }
        if (i == strlen(input_1) - 1)
        {
            printf("Exiting program: Words can't be the same\n");
            exit(0);
        }
    }

    // if constraints are passed , check for permutation :
    int tracker = 0;
    for (int i = 0; i < strlen(input_1); i++)
    {
        for (int j = 0; j < strlen(input_2); j++)
        {
            if (input_1[i] == input_2[j])
            {
                tracker++;
                continue;
            }
        }
        if (tracker == strlen(input_1))
        {
            return true;
        }
    }
    return false; //catch-all
}