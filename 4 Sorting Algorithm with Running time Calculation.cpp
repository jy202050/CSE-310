// Title: Sorting Algorithm(Insertion, Selection, Quick, Merge)
// Desc: Develop four C++ methods that implement the given samples of
//       insertion sort, selection sort, quick sort, and merge sort. Record the running    
//       time by running the four sorting algorithms implemented in part (a) above for 
//       arrays of the following sizes
// Author: JIAYUAN YU
// Date: 05/25/2023




#include <iostream>
#include <vector>
#include <chrono>  // Chrono library is used to deal with date and time(timers or clock)
#include <limits>
#include <cstdlib> // Declares a set of general-purpose function and mathematical functions
#include <ctime>   // converts the given time since epoch to a calendar local time
                   // and then to a character representation. A call to ctime (time) is a
                   // combination of asctime () and localtime () functions, as asctime (localtime (time)).

using namespace std;
using namespace std::chrono;


// Prototypes
void insertionSort(double array[], int n);
void selectionSort(double array[], int n);
int partition(double array[], int p, int r);
void quickSort(double array[], int p, int r);
void mergeSortSubArray(vector<double>& array, int p, int q, int r);
void mergeSort(vector<double>& array, int p, int r);


/*

INSERTION-SORT(A)
    for j = 2 to A.length // A.length = n
        key = A[j]
                // Insert A[j] into sorted sequence
    A[1 … j-1]
        i = j – 1
        while i > 0 and A[i] > key
            A[i+1] = A[i]
            i = i – 1
        A[i+1] = key

*/


// Insertion Sort (C++)
void insertionSort(double array[], int n) {   // Takes array arr and length of the array n as parameters
    for(int j = 1; j < n; j++) {              // Initializes a loop starting from second element of the array, continue until the end of array n
        double key = array[j];                // Assign the second element of the array as key, key will compare and inserted into its correct position
        int i = j - 1;                        // Initializes a variable i to the index preceding the current element j
        while (i >= 0 && array[i] > key) {    // Check if the first element i is greater than 0 and compare to the second element j from the array
            array[i + 1] = array[i];          // If condition is satisfied, shift the current(first) element position to the right(second)
            i--;                              // Decremented to continue comparing the key element with the other elements
        }
        array[i + 1] = key;                   // Once the key element found the correct position, it is inserted into the array by assigning arr[i+1]
    }
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


/*

SELECTION-SORT(A) {

    for i=1 to A.length -1
         min <- i
        for j <- i+1 to A.length
            if A[i] < A[min]
            min <- j
        swap (A[min], A[i])
}

*/


// Selection Sort (C++)
void selectionSort(double array[], int n) {
    for (int i = 0; i < n - 1; i++) {              // Use for loop that iterates through the array to select the minimum element, start from first element (i = 0) to last element n -1
        int minNumber = i;                         // Assign i as minimum element
        for (int j = i + 1; j < n; j++) {          // Iterates through the remaining unsorted array, start from i+1(second element) until the last element n
            if (array[j] < array[minNumber])       // check if the current element j is less than the minimum number i
                minNumber = j;                     // if current element j less than minimum number, then assign the current j element as minimum number
        }
        swap(array[minNumber], array[i]);   // use swap function to swap the position of minimum element with the first or previous element
    }
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


/*
Quick Sort:

    PARTITION(array A, int p, int r)
    1 x <- A[r]             // Choose pivot
    2 i <- p - 1
    3 for j <- p to r -1
    4     do if (A[j] <= x)
    5          then i <- i+1
    6              exchange A[i] <-> A[j]
    7 exchange A[i+1] <-> A[r]
    8 return i + 1

    QUICKSORT(array A, int p, int r)
    1 if (p < r)
    2    then q <- PARTITION(A,p,r)
    3        QUICKSORT(A, p, q-1)
    4        QUICKSORT(A, q+1, r)

*/

// Quick Sort (C++)
// Function to partition the array and reutrn the index of the pivot element
int partition(double array[], int p, int r) {       // p is starting point and r is end point
    int x = array[r];                               // Choose the pivot point(element)
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (array[j] <= x) {                        // Compare the current element with pivot point
            i++;                                    // Move the boundary of the smaller elements
            swap(array[i], array[j]);        // Swap the smaller element with the element in index i
        }
    }
    swap(array[i+1], array[r]);              // Swap the pivot element to its correct position
    return i + 1;                                   // Return the index of the pivot element
}

//Function to recursively perform quick sort on the array
void quickSort(double array[], int p, int r) {
    if(p < r) {
        int q = partition(array, p, r);             // Partition the array and get the pivot point(index)
        quickSort(array, p, q-1);                // Recursive call to sort the left subarray
        quickSort(array, q+1, r);                // Recursive call to sort the right subarray
    }
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


/*
MERGE SORT:

    MERGE-SORT(A, p, r)
    1 if p < r
    2 q = [(p + r) / 2]
    3 MERGE-SORT (A, p, q)
    4 MERGE-SORT (A, q + 1, r)
    5 MERGE(A, p, q, r)


    MERGE(A, p, q, r)
    1 n1 = q - p + 1
    2 n2 = r - q
    3 Let L[1..n1 + 1] and R[1..n2 + 1] be new arrays
    4 for i = 1 to n1
    5     L[i] = A[p + i - 1]
    6 for j = 1 to n2
    7     R[j] = A[q +j]
    8 L[n1 + 1] = infinity
    9 R[n2 + 1] = infinity
    10 i = 1
    11 j = 1
    12 for k = p to r
    13     if L[i] <= R[j]
    14         A[k] = L[i]
    15         i = i +1
    16     else A[k] = R[j]
    17         j = j + 1

*/

// Merge Sort (C++)
// Merge function to merge two sorted subarrays
void mergeSortSubArray(vector<double>& array, int p, int q, int r){
    int n1 = q - p + 1;                            // Calculate the size of the left subarray
    int n2 = r - q;                                // Calculate the size of the right subarray

    // Create new temporary arrays for left and right subarrays
    vector<double> Left(n1+1);
    vector<double> Right(n2+1);

    // Copy data from the orginal array to temporary arrays
    for (int i = 0; i < n1; i++)
        Left[i] = array[p + i ];                  // Copy elements from index p to q into left array
    for (int j = 0; j < n2; j++)
        Right[j] = array[q + 1 + j];              // Copy elements from index (q + 1) to r into right array

    // Add sentinel values at the end of the arrays to mark the end
    Left[n1] = numeric_limits<double> :: infinity();   // Set the last element of left to infinity
    Right[n2] = numeric_limits<double> :: infinity();  // Set the last element of right to infinity
    int i = 0;                                    // Initialize the index for the left subarray
    int j = 0;                                    // Initialize the index for the right subarray

    // Merge the two sub arrays in sorted order
    for (int k = p; k <= r; k++) {
        if (Left[i] <= Right[j]) {
            array[k] = Left[i];                   // Place the smaller element from left into the original array
            i++;                                  // Move to the next element in left
        }
        else {
             array[k] = Right[j];                 // Place the smaller element from right into the original array
             j++;                                 // Move to the next element in right
        }
    }
}

// Merge Sort Function
void mergeSort(vector<double>& array, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(array, p, q);       // Sort the left subarray
        mergeSort(array, p+1, q);  // Sort the right subarray
        mergeSortSubArray(array, p, q, r);       // Merge the sorted subarray
    }
}




int main() {
    vector<int> arraySizes = {10000, 25000, 50000, 100000, 150000, 200000};   // Define an array of sizes for the datasets

    for (int size : arraySizes) {
        vector<double> data(size);                                            // Generate or load the dataset with random double values
        for (int i = 0; i < size; ++i) {
            data[i] = (rand() % 90001 ) / 100.00 + 100.00;                    // Generates random values between 100.00 and 1000.00 and store them in the data vector
                                                                              // rand() % 90001 which gives a random number between 0 and 90000
                                                                              // It then divides the resulting value by 100.0 to obtain a double value between 0.00 and 900.00
                                                                              // Finally, it adds 100.0 to shift the range from 0.00 to 900.00 to 100.00 to 1000.00
        }

        // Measure the running time for each sorting algorithm
        high_resolution_clock::time_point startTime, endTime;                
        duration<double, std::milli> duration;

        // Insertion Sort
        startTime = high_resolution_clock::now();                             // Record the start time of insertion sort
        insertionSort(data.data(), size);                                     // Perform insertion sort on the data array
        endTime = high_resolution_clock::now();                               // Record the end time of insertion sort
        duration = endTime - startTime;                                       // Calculate the duration for the insertion sorting process
        cout << "Insertion Sort - Array Size: " << size << " - Running Time: " << duration.count() << " ms" << endl;

        // Selection Sort
        startTime = high_resolution_clock::now();                             // Record the start time of selection sort
        selectionSort(data.data(), size);                                     // Perform selection sort on the data array
        endTime = high_resolution_clock::now();                               // Record the end time of selection sort
        duration = endTime - startTime;                                       // Calculate the duration for the selection sorting process
        cout << "Selection Sort - Array Size: " << size << " - Running Time: " << duration.count() << " ms" << endl;

        // Quick Sort
        startTime = high_resolution_clock::now();                             // Record the start time of quick sort
        quickSort(data.data(), 0, size - 1);                                  // Perform quick sort on the data array
        endTime = high_resolution_clock::now();                               // Record the end time of quick sort
        duration = endTime - startTime;                                       // Calculate the duration for the quick sorting process
        cout << "Quick Sort - Array Size: " << size << " - Running Time: " << duration.count() << " ms" << endl;

        // Merge Sort
        startTime = high_resolution_clock::now();                             // Record the start time of merge sort
        mergeSort(data, 0, size - 1);                                         // Perform merge sort on the data array
        endTime = high_resolution_clock::now();                               // Record the end time of merge sort
        duration = endTime - startTime;                                       // Calculate the duration for the merge sorting process
        cout << "Merge Sort - Array Size: " << size << " - Running Time: " << duration.count() << " ms" << endl;

  
        cout << endl;                                                         // Print a new line to separate the results for different array sizes
    }

    return 0;
}
