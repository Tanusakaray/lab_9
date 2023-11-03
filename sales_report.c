#include <stdio.h>

int main() {
    // Open the input file for reading
    FILE *inputFile = fopen("C:\\Users\\Tanu\\OneDrive\\Desktop\\368\\lab_5\\sales_data.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    double sales[12];
    char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    // Read the monthly sales data
    for (int i = 0; i < 12; i++) {
        if (fscanf(inputFile, "%lf", &sales[i]) != 1) {
            printf("Error: Invalid data in input file.\n");
            fclose(inputFile);
            return 1;
        }
    }
    fclose(inputFile);

    // Generate the sales report
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }

    // Calculate and display the sales summary
    double minSales = sales[0], maxSales = sales[0], avgSales = 0;
    for (int i = 0; i < 12; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
        avgSales += sales[i];
    }
    avgSales /= 12;

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[11]);
    printf("Average sales: $%.2f\n", avgSales);

    // Generate the six-month moving average report
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        double movingAvg = 0;
        for (int j = i; j < i + 6; j++) {
            movingAvg += sales[j];
        }
        movingAvg /= 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], movingAvg);
    }

    // Generate the sales report sorted from highest to lowest
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 11; i >= 0; i--) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }

    return 0;
}
