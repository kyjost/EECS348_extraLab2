/*
Ky Jost 
3070792
EECS 348 Lab 5 
12 October 2023
This program reads a file and returns various data on the sales numbers in it. 
*/
#include <stdio.h> 
#include <stdlib.h> 

void sixMonths(int startI, float list[]);

int main() {
    //This section gets user input to determine the file name 
    char fileName[300]; 
    printf("Enter the file name: "); 
    scanf("%s", fileName); 
    
    //This opens the file with the name given by the user 
    FILE *numbers; 
    numbers = fopen(fileName, "r"); 

    //This loads the numbers into a list of lists as a string 
    char strList[12][300]; 
    int i; 
    for(i=0; i < 12; i++) {
        fgets(strList[i], 300, numbers); 
    }

    //This takes the list of strings, converts it to float, and loads it into our final list 
    float list[12]; 
    for(i = 0; i < 12; i++) {
        list[i] = atof(strList[i]); 
    }

    //This section delivers the output 
    //This part is the list by month 
    char months[12][20] = {"January  ", "February ", "March    ", "April    ", "May      ", "June     ", "July     ", "August   ", "September", "October  ", "November ", "December "}; 
    printf("Monthly sales report for 2022: \n\nMonth          Sales\n\n");  

    for(i = 0; i < 12; i++) {
        printf("%s      $%.2f\n", months[i], list[i]);
    }

    //This part is the min/max/average summary 
    printf("\nSales summary: \n\n");

    float maxTest = 0.0; 
    int monthMax = 0; 
    for(i = 0; i < 12; i++) { 
        if (list[i] > maxTest) {
            maxTest = list[i]; 
            monthMax = 1; 
        }
    }

    float minTest = 100000000000000.0; 
    int monthMin = 0; 
    for(i = 0; i < 12; i++) { 
        if (list[i] < minTest) {
            minTest = list[i]; 
            monthMin = i; 
        }
    }

    float ave = 0; 
    for(i = 0; i < 12; i++) {
        ave = ave + list[i]; 
    }
    ave = ave/12; 

    printf("Minimum Sales:     $%.2f    (%s)\n", minTest, months[monthMin]); 
    printf("Maximum Sales:     $%.2f    (%s)\n", maxTest, months[monthMax]); 
    printf("Average Sales:     $%.2f\n", ave); 

    //This part gives the six month averages: 
    printf("\nSix-Month Moving Average Report: \n\n"); 

    sixMonths(0, list); 
    sixMonths(1, list); 
    sixMonths(2, list); 
    sixMonths(3, list); 
    sixMonths(4, list); 
    sixMonths(5, list); 
    sixMonths(6, list); 

    //This part gives the highest to lowest: 
    printf("\nSales Report (Highest to Lowest):\n\n");
    printf(" Month       Sales  \n\n"); 

    float findMax = 0.0; 
    float keepMax = 1000000000000000.0; 
    int keepI = 0; 
    for(int j = 0; j < 12; j++) {
        for(i = 0; i < 12; i++) {
            if (list[i] > findMax && list[i] < keepMax) {
                findMax = list[i]; 
                keepI = i; 
            }
        }
        keepMax = findMax;
        findMax = 0;  
        printf("%s  $%.2f\n", months[keepI], keepMax); 
    }
}

//This function gives the six month averages 
void sixMonths(int startI, float list[]) { 
    int i; 
    float ave = 0; 
    for(i = 0; i < 6; i++) {
        ave = ave + list[i + startI]; 
    }
    ave = ave/6; 
    char months[12][20] = {"January  ", "February ", "March    ", "April    ", "May      ", "June     ", "July     ", "August   ", "September", "October  ", "November ", "December "}; 
    printf("%s  -  %s  $%.2f\n", months[startI], months[startI+5], ave); 
}