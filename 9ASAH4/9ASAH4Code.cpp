#include <iostream>
#include <fstream>
#include <iomanip>   //fix, setw
#include <stdlib.h> //srand, rand
#include <chrono>
#include <time.h>    //clock, clock_t
#include <vector>
#include <cmath>

using namespace std;



/* https://www.geeksforgeeks.org/insertion-sort/ */
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* https://www.geeksforgeeks.org/selection-sort/ */
/* functions for selection sort*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}


int main() {

  using Clock = chrono::high_resolution_clock;

  clock_t start, stop;

  long long Selectionelapsedtime;
  long long Insertionelapsedtime;
  int arrx[] = {10, 6, 9, 2, 4, 7, 3, 1, 8, 5};
  int nx = sizeof(arrx)/sizeof(arrx[0]);
  
  start = Clock::now().time_since_epoch().count();

  selectionSort(arrx, nx);

  stop = Clock::now().time_since_epoch().count();
  Selectionelapsedtime = (long long)(stop - start);

  start = Clock::now().time_since_epoch().count();

  insertionSort(arrx, nx);

  stop = Clock::now().time_since_epoch().count();
  Insertionelapsedtime = (long long)(stop - start);

  cout << "Selectiontime in nanoseconds rand: " << Selectionelapsedtime << '\n';
  cout << "Insertiontime in nanoseconds rand: " << Insertionelapsedtime << '\n';

  int arry[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ny = sizeof(arry)/sizeof(arry[0]);
  
  start = Clock::now().time_since_epoch().count();

  selectionSort(arry, ny);

  stop = Clock::now().time_since_epoch().count();
  Selectionelapsedtime = (long long)(stop - start);

  start = Clock::now().time_since_epoch().count();

  insertionSort(arry, ny);

  stop = Clock::now().time_since_epoch().count();
  Insertionelapsedtime = (long long)(stop - start);

  cout << "Selectiontime in nanoseconds des: " << Selectionelapsedtime << '\n';
  cout << "Insertiontime in nanoseconds des: " << Insertionelapsedtime << '\n';

  int arrz[] = {10, 9, 8, 7, 6, 5, 4, 3,2, 1};
  int nz = sizeof(arrz)/sizeof(arrz[0]);
  
  start = Clock::now().time_since_epoch().count();

  selectionSort(arrz, nz);

  stop = Clock::now().time_since_epoch().count();
  Selectionelapsedtime = (long long)(stop - start);

  start = Clock::now().time_since_epoch().count();

  insertionSort(arrz, nz);

  stop = Clock::now().time_since_epoch().count();
  Insertionelapsedtime = (long long)(stop - start);

  cout << "Selectiontime in nanoseconds asc: " << Selectionelapsedtime << '\n';
  cout << "Insertiontime in nanoseconds asc: " << Insertionelapsedtime << '\n';

  return 0;
} 
