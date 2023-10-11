#include <stdio.h>

void monthlySalesReport(const float sales[12])
{
    printf("Monthly Sales Report for 2022:\n");
    printf("Month     Sales     \n");
    printf("January   $%-10.2f\n", sales[0]);
    printf("February  $%-10.2f\n", sales[1]);
    printf("March     $%-10.2f\n", sales[2]);
    printf("April     $%-10.2f\n", sales[3]);
    printf("May       $%-10.2f\n", sales[4]);
    printf("June      $%-10.2f\n", sales[5]);
    printf("July      $%-10.2f\n", sales[6]);
    printf("August    $%-10.2f\n", sales[7]);
    printf("September $%-10.2f\n", sales[8]);
    printf("October   $%-10.2f\n", sales[9]);
    printf("November  $%-10.2f\n", sales[10]);
    printf("December  $%-10.2f\n\n", sales[11]);
}

void minMaxAvg(const float sales[12])
{
    float min = sales[0];
    float max = sales[0];
    float avg = 0;
    for (int i = 0; i < 12; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
        }
        if (sales[i] > max)
        {
            max = sales[i];
        }
    }
    avg = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 2;
    printf("Sales summary:\n");
    printf("Minimum sales:  $%-10.2f\n", min);
    printf("Maxmimum sales: $%-10.2f\n", max);
    printf("Average sales:  $%-10.2f\n\n", avg); 
}

void sixMonthAvgs()
{
    printf ("Six-Month Moving Average Report:\n");\

    float avgs[7];
    for (int i = 0; i < 7; i++)
    {
        /* TODO Calculate averages here */
    }
    
    printf("January - June    $%-10.2f\n", avgs[0]);
    printf("February - July   $%-10.2f\n", avgs[1]);
    printf("March - August    $%-10.2f\n", avgs[2]);
    printf("April - September $%-10.2f\n", avgs[3]);
    printf("May - October     $%-10.2f\n", avgs[4]);
    printf("June - November   $%-10.2f\n", avgs[5]);
    printf("July - December   $%-10.2f\n\n", avgs[6]);
}

void highLowSalesReport()
{
    printf ("Monthly Sales Report\n");
}

int main ()
{
    float sales[12]; /* Create a buffer to hold our sales numbers */
    
    /* Input 12 values. TODO: Change to text file input later */
    for (int i = 0; i < 12; i++)
    {
        printf("Enter sales number %d:\n", i+1);
        scanf("%f", &sales[i]);
    }

    printf("\n"); /* Print seperator line */

    /* Output sales values */
    for (int i = 0; i < 12; i++) 
    {
        printf("%f\n", sales[i]);
    }

    monthlySalesReport(sales);
    minMaxAvg(sales);
    sixMonthAvgs();
    highLowSalesReport();

    return 0;
}