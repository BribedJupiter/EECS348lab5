/*
    Author: Jack Bauer
    Creation date: 10/11/23
    Last edited: 10/15/23
    Purpose: To execute a program designed to solve problem statement 1 for EECS 348: Lab 5 
        by generating a sales report and related information from a textfile of 12 decimal numbers
*/

#include <stdio.h>

/* Return a char array consiting of 11 digit months based upon an integer value provided */
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

/* Print out a monthly sales report in tabular form with two columns, one for the month and one for total sales */
void monthlySalesReport(const float sales[12], const int months[12])
{
    printf("Monthly Sales Report for 2022:\n\n");
    printf("Month      Sales     \n");
    /* Iterate through the months and print the month and sales */
    for (int i = 0; i < 12; i++)
    {
        printf("%s $%-10.2f\n", getMonth(months[i]), sales[i]);
    }
    printf("\n");
}

/* Print out the minimum sale month and amount, maximum sale month and amount, and the average sales per month */
void minMaxAvg(const float sales[12], const int months[12])
{
    /* Initialize variables */
    float min = sales[0];
    int minMonth = months[0];
    float max = sales[0];
    int maxMonth = months[0];
    float avg = 0;

    /* Iterate through and find the min and the max by starting 
    at the first value and checking all the rest of the values for
    if they are larger or smaller than the current value, and switching
    them if they are */
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

    /* Calculate the average */
    avg = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 12;
    
    /* Print our summary */
    printf("Sales summary:\n");
    printf("Minimum sales: $%-10.2f - %s\n", min, getMonth(months[minMonth]));
    printf("Maximum sales: $%-10.2f - %s\n", max, getMonth(months[maxMonth]));
    printf("Average sales:  $%-10.2f\n", avg); 

    printf("\n");
}

/* Print out the six month moving average for the year */
void sixMonthAvgs(const float sales[12], const int months[12])
{
    printf ("Six-Month Moving Average Report:\n");\

    /* We know there will be 7 six-month floating averages by counting */
    float avgs[7]; /* Initiate an array to hold these averages */
    /* Iterate through and calculate the moving average */
    for (int i = 0; i < 7; i++)
    {
        /*  Calculate averages here */
        avgs[i] = (sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5]) / 6;
    }
    /* Print all the averages */
    for (int i = 0; i < 7; i++)
    {
        printf("%s - %s $%-10.2f\n", getMonth(months[i]), getMonth(months[i+5]), avgs[i]); 
    }
    printf("\n");
}

/* Print out the monthly sales report in tabular (month sales) format from highest to lowest */
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
    /* Print the report */
    printf("Month      Sales     \n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s $%-10.2f\n", getMonth(months[i]), sales[i]);
    }
    
    printf("\n"); /* Print seperator line */
}

/* Our main function, responsible for controlling the entire program */
int main ()
{
    float sales[12]; /* Create a buffer to hold our sales numbers */
    int months[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; /* There are 12 months in a year, but we will index from 0 to match the sales data */

    char filename[80]; /* Create a buffer for our filename*/
    
    /* Get a file name from the user to read in the sales data */
    printf("Enter an input filename: ");
    scanf("%s", filename);

    /* Open the file and get a pointer to it */
    FILE* inputFilePtr = fopen(filename, "r");

    /* Make sure it was a valid file */
    if (inputFilePtr == NULL)
    {
        printf("Invalid filename\n");
        return 0;
    }

    /* Note: This assumes the file is 12 lines long with a number on each line and only that */
    /* Read in the file and store the data in the sales array */
    for (int i = 0; i < 12; i++)
    {
        fscanf(inputFilePtr, "%f", &sales[i]);
    }
    
    /* Close the file because we are now done with it */
    fclose(inputFilePtr);
        
    printf("\n"); /* Print seperator line */

    /* Print our reports */
    monthlySalesReport(sales, months);
    minMaxAvg(sales, months);
    sixMonthAvgs(sales, months);
    highLowSalesReport(sales, months);

    return 0;
}