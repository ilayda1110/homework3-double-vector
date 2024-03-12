#include <iostream>
#include "Double_Vector.h"

using namespace std;

void addData(Double_vector& dataVector)
{
    double num;
    cout << "Enter numeric data (separate values by spaces):  ";
}

void calculateMean(const Double_vector& dataVector)
{
    double sum=0;
    for(int i=0; i < dataVector.size(); i++)
    {
        //sum += dataVector[i];
    }
    cout << "Mean: "<< sum/dataVector.size();
}

void calculateMedian(const Double_vector& dataVector)
{

}

void calculateStandardDeviation(const Double_vector& dataVector)
{

}

void displayData(const Double_vector& dataVector)
{
    for(int i=0; i < dataVector.size(); i++)
    {
        //cout << dataVector[i] << " ";
    }
}

void showMenu()
{
    std::cout << "=== Statistics Calculator ===\n"
              << "1. Add Data\n"
              << "2. Calculate Mean\n"
              << "3. Calculate Median\n"
              << "4. Calculate Standard Deviation\n"
              << "5. Display Data\n"
              << "6. Exit\n"
              << "Enter your choice: ";
}

void runStatisticsCalculator()
{
    Double_vector dataVector;
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addData(dataVector);
                break;
            case 2:
                calculateMean(dataVector);
                break;
            case 3:
                calculateMedian(dataVector);
                break;
            case 4:
                calculateStandardDeviation(dataVector);
                break;
            case 5:
                displayData(dataVector);
                break;
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main()
{
    runStatisticsCalculator();
    return 0;
}