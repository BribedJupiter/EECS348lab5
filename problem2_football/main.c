#include <stdio.h>

int sum(int TD, int FG, int safety, int TDconversion, int TDfg)
{
    return TD * 6 + FG * 3 + safety * 2 + TDconversion * 8 + TDfg * 7;
}

void calculateScore(int score)
{
    int TD; /* 6 pts */
    int FG; /* 3 pts */
    int safety; /* 2 pts */
    int TDconversion; /* 8 pts - 2pts from conversion */
    int TDfg; /* 7 pts - 1 pt from field goal*/

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
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety --> Total: %i\n", TDconversion, TDfg, TD, FG, safety, sum(TD, FG, safety, TDconversion, TDfg));
                        }
                    }
                }
            }
        }
    }

}

int main () 
{ 
    int running = 1;

    while (running == 1)
    {
        int score;
        printf("Enter 0 or 1 to stop.\n");
        printf("Or, enter the NFL game score:\n");
        scanf("%i", &score);

        if (score <= 1)
        {
            running = 0;
            break;
        }

        calculateScore(score);
        
    }

    return 0;
}