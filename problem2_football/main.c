/*
    Author: Jack Bauer
    Creation date: 10/11/23
    Last edited: 10/15/23
    Purpose: To execute a program designed to solve problem statement 2 for EECS 348: Lab 5 
        by calculating all the possible score combinations for an NFL game when a user enters a score
*/

#include <stdio.h>

/* Calculate the sum of the point options */
int sum(int TD, int FG, int safety, int TDconversion, int TDfg)
{
    /* Return the sum of the score types.
    TD (touchdown) is worth 6 pts 
    FG (field goal) is worth 3 pts 
    Safety is worth 2 pts 
    TDconversion (touchdown + 2 pt conversion) is worth 8 pts
    TDfg (touchdown + 1 pt field goal) is worth 7 pts */
    return TD * 6 + FG * 3 + safety * 2 + TDconversion * 8 + TDfg * 7;
}

/* Calculate and display the score */
void calculateScore(int score)
{
    /* Create variables where we will store the total number of occurances of each type of score */
    int TD; /* 6 pts */
    int FG; /* 3 pts */
    int safety; /* 2 pts */
    int TDconversion; /* 8 pts - 2pts from conversion */
    int TDfg; /* 7 pts - 1 pt from field goal*/

    printf("\nPossible combinations of scoring plays:\n");

    /* Loop through and find all possible combinations by checking each possible combination of each score type
    up to and including the count of each alone multiplied to equal the score. If the combination works, it is printed to
    the terminal */

    for (TDconversion = 0; TDconversion * 8 <= score; TDconversion++)
    {
        for (TDfg = 0; TDfg * 7 <= score; TDfg++)
        {
            for (TD = 0; TD * 6 <= score; TD++)
            {
                for (FG = 0; FG * 3  <= score; FG++)
                {
                    for (safety = 0; safety * 2 <= score; safety++)
                    {
                        if (sum(TD, FG, safety, TDconversion, TDfg) == score)
                        {
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety\n", TDconversion, TDfg, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }

    printf("\n");

}

/* The main function that runs the program */
int main () 
{ 
    int running = 1; /* Set a "is the program continuing" variable so we can keep a program loop going but end it when we need to */

    /* In this loop, while the program is running, we will input an NFL game score from the user
    and calculate and display all possible combinations of scoring options that could have created
    that score. But, since a score less than 2 is impossible, if the user enters a value that is less than 2,
    the program will terminate. */

    while (running == 1) 
    {
        /* Display options and get the score */
        int score;
        printf("Enter 0 or 1 to STOP.\n");
        printf("Or, enter the NFL game score:\n");
        scanf("%i", &score);

        /* Check if the user wants to terminate the program */
        if (score <= 1) 
        {
            running = 0;
            break;
        }

        calculateScore(score); /* Calculate and display the score combinations that are possible */
        
    }

    return 0;
}