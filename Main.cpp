#include <iostream>
using namespace std; 
#include <ctime>

//run code three times and then average them in the table

/*
Name: Mallory Boehle
Date: 11/9/22
Assignment: testing different sort functions 
Class: CSC 225 Data Structures and Algorthims 
*/

struct Sort //structure to hold swaps and comapres 
{
    long long swaps; 
    long long compare; 
};

//function prototypes lines 19-26
void Insertion(int[], int, Sort&);
void Selection(int[], int, Sort&);
void Quick(int[],int, int, Sort&);
int Part(int[], int, int, Sort&); 
void insertionSortInterleaved(int[], int, int, int, Sort&); 
void Shell(int[], int, int[], int, Sort&);
void setToZero(Sort&);
void copyArry(int[], int[], int);

const int SORTED = 100000; //global variables
const int UNSORTED = 100000; 
const int GAP = 20; 

int main()
{
	int arry1[SORTED];
	int arry2[UNSORTED]; 
    int gapVal[GAP];
    int gapVal2[GAP];
	int numOfElements; 
    int divide = 0;
    int count = 0; 
    int count2 = 0; 
    int i = 0; 
    double elaspedTime; 
    double start; //start and end variables for all the timers
    double end; 
    double start2;
    double end2;
    double start3;
    double end3;
    double start4;
    double end4;
    double start5;
    double end5;
    double change1; //start and end variables for all the timers
    double idc1;
    double change2;
    double idc2;
    double change3;
    double idc3;
    double change4;
    double idc4;
    double change5;
    double idc5;
    Sort selectInfo; 
    Sort insertInfo;  // one for each sort 
    Sort quickInfo; 
    Sort shellInfo1; 
    Sort shellInfo2; 

    cout << "How many elements do you want to sort? "; 
	cin >> numOfElements; 
    cout << endl; 
    srand(time(0)); 

    while (numOfElements <= 0 || numOfElements > 100000) // data vailidating array size
    {
        cout << "Please eneter a valid array size to sort: " << endl; 
        cin >> numOfElements; 
    }
    
    setToZero(insertInfo); 
    setToZero(selectInfo); 
    setToZero(quickInfo);
    setToZero(shellInfo1); 
    setToZero(shellInfo2); 

    //cout << "Unsorted values: " << endl; 
	for (int i = 0; i < numOfElements; i++)
	{
        arry2[i] = rand(); 
       // cout << arry2[i] << " " << endl; 
	}

    divide = numOfElements / 2; 

    while (divide > 0 ) //divide by 2 loop
    {
        gapVal[count] = divide; 
        divide = divide / 2;
        count++;
    }

    cout << "Divide by 2 used " << count << " gaps" << endl;

    for (i = 0; i < count; i++)//divide by 2 loop print 
    {
        cout << gapVal[i] << " "; 
    }
    cout << endl;

    divide = 1; 
    while (divide < numOfElements) //the other shell loop 
    {
        gapVal2[count2] = divide -1;
        divide = divide * 2;
        count2++;
    }

    for (i = 0; i < count2/2; i++) //reverse for other shell 
    {
        int temp = gapVal2[count2-i-1]; 
        gapVal2[count2 -i -1] = gapVal2[i]; 
        gapVal2[i] = temp;   
    }

    cout << endl; 

    cout << "Shell 2 used " << count2 << " gaps" << endl; 

    for (i = 0; i < count; i++)// other shell print 
    {
        cout << gapVal2[i] << " ";
    }

    cout << endl; 

    copyArry(arry1, arry2, numOfElements); // copy the array 

    start = clock(); //start timer
    Insertion(arry1, numOfElements,insertInfo); //call function 
    end = clock(); // end timer 

    copyArry(arry1, arry2, numOfElements);

    start2 = clock(); //rise repeat first one byt change the function 
    Selection(arry1, numOfElements, selectInfo); 
    end2 = clock(); 

    copyArry(arry1, arry2, numOfElements);

    start3 = clock();
    Quick(arry1, 0, (numOfElements - 1),quickInfo); 
    end3 = clock();

    copyArry(arry1, arry2, numOfElements); 

    start4 = clock(); 
    Shell(arry1, numOfElements, gapVal, count, shellInfo1);
    end4 = clock(); 

    copyArry(arry1, arry2, numOfElements);

    start5 = clock(); 
    Shell(arry1, numOfElements, gapVal2, count2, shellInfo2); 
    end5 = clock(); 

    change1 = clock(); //start timer
    Insertion(arry1, numOfElements, insertInfo); //call function 
    idc1 = clock(); // end timer 

    copyArry(arry1, arry2, numOfElements);

    change2 = clock(); //rise repeat first one byt change the function 
    Selection(arry1, numOfElements, selectInfo);
    idc2 = clock();

    copyArry(arry1, arry2, numOfElements);

    change3 = clock();
    Quick(arry1, 0, (numOfElements - 1), quickInfo);
    idc3 = clock();

    copyArry(arry1, arry2, numOfElements);

    change4 = clock();
    Shell(arry1, numOfElements, gapVal, count, shellInfo1);
    idc4 = clock();

    copyArry(arry1, arry2, numOfElements);

    change5 = clock();
    Shell(arry1, numOfElements, gapVal2, count2, shellInfo2);
    idc5 = clock();

    cout << endl; 

    cout << "Number of swaps" << endl; 
    cout << "Insertion Sort: " << insertInfo.swaps << endl;
    cout << "Selection Sort: " << selectInfo.swaps << endl; 
    cout << "Quicksort: " << quickInfo.swaps << endl;
    cout << "Shell Sort (divide by 2): " << shellInfo1.swaps << endl; 
    cout << "Shell 2: " << shellInfo2.swaps << endl;

    cout << endl; // blank space between 

    cout << "Number of comparions" << endl; 
    cout << "Insertion Sort: " << insertInfo.compare << endl;
    cout << "Selection Sort: " << selectInfo.compare << endl; 
    cout << "Quicksort: " << quickInfo.compare << endl;
    cout << "Shell Sort (divide by 2): " << shellInfo1.compare << endl; 
    cout << "Shell 2: " << shellInfo2.compare << endl;

    /*cout << "Sorted values: " << endl;
     for (int i = 0; i < numOfElements; i++)
    {
        cout << arry2[i] << " " << endl; 
    } */
    cout << endl; 

    cout << "Time taken to sort " << endl;
    elaspedTime = (end - start) / CLOCKS_PER_SEC; //time for insertion 
    cout << "Insertion: " << elaspedTime << endl;
    elaspedTime = (end2 - start2) / CLOCKS_PER_SEC; //time for selection
    cout << "Selection: " << elaspedTime << endl;
    elaspedTime = (end3 - start3) / CLOCKS_PER_SEC; //time for quicksort
    cout << "Quicksort: " << elaspedTime << endl;
    elaspedTime = (end4 - start4) / CLOCKS_PER_SEC; //time for shell divide by two 
    cout << "Shell Sort (divide by 2): " << elaspedTime << endl;
    elaspedTime = (end5 - start5) / CLOCKS_PER_SEC; //time for shell 2 
    cout << "Shell 2: " << elaspedTime << endl;
	return 0; 
}


void copyArry(int arry1[],int arry2[], int numOfElements)
{
    for (int i = 0; i < numOfElements; i++) //copy the array
    {
        arry1[i] = arry2[i];
    }
}

void Insertion(int arry[], int ArrySize, Sort& stats)
{
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap 

    for (i = 1; i < ArrySize; ++i) {
        j = i; 
        stats.compare++; //increments the compares
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && arry[j] < arry[j - 1]) {
            stats.compare++; //increments the compares
            // Swap numbers[j] and numbers[j - 1]
            temp = arry[j];
            arry[j] = arry[j - 1];
            arry[j - 1] = temp;
            --j;
            stats.swaps++; //increments the swaps
        }
    }
}

void Selection(int arry[], int ArrySize, Sort& stats)
{
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    int temp = 0; // Temporary variable for swap

    for (i = 0; i < ArrySize - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < ArrySize; ++j) {
            stats.compare++;
            if (arry[j] < arry[indexSmallest]) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        temp = arry[i];
        arry[i] = arry[indexSmallest];
        arry[indexSmallest] = temp;
        stats.swaps++;
    }
}

void setToZero(Sort& stats)
{
    stats.swaps = 0;  // sets everything to zero
    stats.compare = 0; 

}
int Part(int numbers[], int lowIndex, int highIndex, Sort& stats) { //short for partition 
    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = numbers[midpoint];

    int done = false;
    while (!done) {
        stats.compare++;
        // Increment lowIndex while numbers[lowIndex] < pivot
        while (numbers[lowIndex] < pivot) {
            lowIndex += 1;
            stats.compare++;
        }
        stats.compare++;
        // Decrement highIndex while pivot < numbers[highIndex]
        while (pivot < numbers[highIndex]) {
            highIndex -= 1;
            stats.compare++; //do i need one or two?
        }

        // If zero or one elements remain, then all numbers are 
        // partitioned. Return highIndex.
        if (lowIndex >= highIndex) {
            done = true;
        }
        else {
            // Swap numbers[lowIndex] and numbers[highIndex]
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;
            stats.swaps++;

            // Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }

    return highIndex;
} 

void Quick(int numbers[], int lowIndex, int highIndex, Sort& stats) {
    // Base case: If the partition size is 1 or zero 
    // elements, then the partition is already sorted
    if (lowIndex >= highIndex) {
        return;
    }

    // Partition the data within the array. Value lowEndIndex 
    // returned from partitioning is the index of the low 
    // partition's last element.
    int lowEndIndex = Part(numbers, lowIndex, highIndex, stats);

    // Recursively sort low partition (lowIndex to lowEndIndex) 
    // and high partition (lowEndIndex + 1 to highIndex)
    Quick(numbers, lowIndex, lowEndIndex, stats);
    Quick(numbers, lowEndIndex + 1, highIndex, stats);
}

void insertionSortInterleaved(int numbers[], int numbersSize, int startIndex, int gap, Sort& stats) {
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap

    for (i = startIndex + gap; i < numbersSize; i = i + gap) {
        j = i;
        stats.compare++; 
        while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
            temp = numbers[j];
            numbers[j] = numbers[j - gap];
            numbers[j - gap] = temp;
            j = j - gap;
            stats.swaps++;
        }
    }
}


void Shell(int numbers[], int numbersSize, int gapValues[], int numGapValues, Sort& stats) {
    int gapValue;

    int i = 0;
    for (int g = 0; g < numGapValues; g++) {
        gapValue = gapValues[g];
        for (i = 0; i < gapValue; i++) {
            insertionSortInterleaved(numbers, numbersSize, i, gapValue, stats);
        }
    }
}