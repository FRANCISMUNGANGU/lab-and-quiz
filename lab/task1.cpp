#include <iostream>

using namespace std;

void Summation(int Number_array[], int arraySize)
{
    int i, sum;
    i = 0;
    sum = 0;
    while(i != arraySize){
        sum += Number_array[i];
        i++;
    }
    cout << "The sum is " << sum << "\n";
}

void Maximum(int Number_array[], int arraySize)
{
    int largest, x;
    largest = Number_array[0];
    for(x = 0; x < arraySize; x++){
        if(largest < Number_array[x]){
            largest = Number_array[x];
        }
    }
    cout << "This is the largest " << largest;

}

int main()
{

    int arraySize, arrayItems,Number_array[arraySize];
    cout << "Enter how many numbers you want to input: ";
    cin >> arraySize;
    int x = 0;
    while(x != arraySize){

        cout << "Enter the numbers: ";
        cin >> arrayItems;
        Number_array[x] = {arrayItems};
        x++;
        if (x > arraySize){
            break;
        }

    }

    Summation(Number_array, arraySize);
    Maximum(Number_array, arraySize);
    return 0;
}

