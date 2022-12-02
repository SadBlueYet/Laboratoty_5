#include <iostream>
#include <fstream>
void isUniqueNumbers(int* array, int arrayLength)
{
    int counter;
    int count = 0;
    for(int i = 0; i < arrayLength; i++)
    {
        counter = 0;
        for (int j = 0; j < arrayLength; j++)
        {
            if (i == j) continue;
            if (array[i] == array[j]) counter++;
                   
        }
        if (counter == 0) count++;
    }
    std::cout << "The number of unique elements in the array: " << count;
    return;
}
void maxAndMin(int array[5][5], int length, double& max, double& min)
{
    min = array[1][4];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i > length - 1 - j && ((i == 0 && j == 0) || array[i][j] > max)) max = array[i][j];
            if (i > length - 1 - j && ((i == 0 && j == 0) || array[i][j] < min)) min = array[i][j];
        }
    }
}
void task1()
{
    int number = 5;
    const int arrayLength = 10;
    int arrayOfNumbers[arrayLength];
    for (int i = 0; i < arrayLength; i++){
        std::cout << "Enter an array element(" << i + 1 << "): ";
        std::cin >> arrayOfNumbers[i];
    }
    int numberOne = arrayOfNumbers[0];
    int numberTwo = arrayOfNumbers[1];
    int maxDifferent = abs((numberOne - numberTwo) - number);

    for (int i = 0; i < arrayLength; i++) {
        for (int j = 0; j < arrayLength; j++) 
        {
            if (i == j) continue;
            if (maxDifferent < abs((arrayOfNumbers[i] - arrayOfNumbers[j]) - number))
            {
                maxDifferent = abs((arrayOfNumbers[i] - arrayOfNumbers[j]) - number);
                numberOne = arrayOfNumbers[i];
                numberTwo = arrayOfNumbers[j];
            }
        }
    }
    if (numberOne >= numberTwo) std::cout << "Array elements whose difference is greatest from(" <<
        number << ')' << numberTwo << ' ' << numberOne;
    else std::cout << "Array elements whose difference is greatest from(" <<
        number << ')' << numberOne << ' ' << numberTwo;
    return;
}
void task2()
{
    const int arrayLength = 10;
    int arrayOfNumbers[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        std::cout << "Enter an array element(" << i + 1 << "): ";
        std::cin >> arrayOfNumbers[i];
    }
    isUniqueNumbers(arrayOfNumbers, arrayLength);
    return;
}
void task3() {
    const int length = 5;
    double max = 0;
    double min = 0;
    int array[length][length];
    std::ifstream theMatrix;
    theMatrix.open("array.txt", std::ios_base::in);
    if (!theMatrix.is_open()) return;
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            theMatrix >> array[i][j];
            std::cout << array[i][j] << '\t' << ' ';
        }
        std::cout << '\n';
    }
    maxAndMin(array, length, max, min);
    std::cout << max << '\n' << min << '\n';
    theMatrix.close();
    
}
int main()
{
    task3();
    return 0;
}

