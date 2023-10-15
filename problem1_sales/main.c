#include <stdio.h>

const char* getMonth (int month)
{
    switch (month) 
    {
        case 0:
            return "January   \0";
        case 1:
            return "February  \0";
        case 2:
            return "March     \0";
        case 3:
            return "April     \0";
        case 4:
            return "May       \0";
        case 5:
            return "June      \0";
        case 6:
            return "July      \0";
        case 7:
            return "August    \0";
        case 8:
            return "September \0";
        case 9:
            return "October   \0";
        case 10:
            return "November  \0";
        case 11:
            return "December  \0";
    }
}

void monthlySalesReport(const float sales[12], const int months[12])
{
    printf("Monthly Sales Report for 2022:\n\n");
    printf("Month      Sales     \n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s $%-10.2f\n", getMonth(months[i]), sales[i]);
    }
    printf("\n");
}

void minMaxAvg(const float sales[12], const int months[12])
{
    float min = sales[0];
    int minMonth = months[0];
    float max = sales[0];
    int maxMonth = months[0];
    float avg = 0;
    for (int i = 0; i < 12; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
            minMonth = months[i];
        }
        if (sales[i] > max)
        {
            max = sales[i];
            maxMonth = months[i];
        }
    }
    avg = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 12;
    printf("Sales summary:\n");
    printf("Minimum sales: $%-10.2f - %s\n", min, getMonth(months[minMonth]));
    printf("Maximum sales: $%-10.2f - %s\n", max, getMonth(months[maxMonth]));
    printf("Average sales:  $%-10.2f\n", avg); 

    printf("\n");
}

void sixMonthAvgs(const float sales[12], const int months[12])
{
    printf ("Six-Month Moving Average Report:\n");\

    float avgs[7];
    for (int i = 0; i < 7; i++)
    {
        /*  Calculate averages here */
        avgs[i] = (sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5]) / 6;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%s - %s $%-10.2f\n", getMonth(months[i]), getMonth(months[i+5]), avgs[i]); 
    }
    printf("\n");
}

void highLowSalesReport(float sales[12], int months[12])
{
    printf ("Monthly Sales Report (Highest to Lowest)\n");
    for (int i = 0; i < 12; i++)
    {
        /* Sort the array highest to lowest - Note: this will change the original array*/
        for (int j = 0; j < 12; j++)
        {
            if (sales[i] > sales[j])
            {
                float temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
                int monthTemp = months[i];
                months[i] = months[j];
                months[j] = monthTemp;
            }
        }
    }
    /* Print the array */
    printf("Month      Sales     \n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s $%-10.2f\n", getMonth(months[i]), sales[i]);
    }
    
    printf("\n"); /* Print seperator line */
}

int main ()
{
    float sales[12]; /* Create a buffer to hold our sales numbers */
    int months[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    char filename[80];
    
    printf("Enter an input filename: ");
    scanf("%s", filename);

    FILE* inputFilePtr = fopen(filename, "r");

    if (inputFilePtr == NULL)
    {
        printf("Invalid filename\n");
        return 0;
    }

    /* Note: This assumes the file is 12 lines long with a number on each line and only that */

    for (int i = 0; i < 12; i++)
    {
        fscanf(inputFilePtr, "%f", &sales[i]);
    }

    fclose(inputFilePtr);
        
    printf("\n"); /* Print seperator line */

    monthlySalesReport(sales, months);
    minMaxAvg(sales, months);
    sixMonthAvgs(sales, months);
    highLowSalesReport(sales, months);

    return 0;
}