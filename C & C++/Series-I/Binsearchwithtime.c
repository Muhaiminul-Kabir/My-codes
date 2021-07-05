#include <stdio.h>
#include<time.h>
int binarySearch(int array[], int x, int low, int high) {
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == x) return mid;
        else if (array[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(void) {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 7;
     clock_t t;
    t = clock();
    int result = binarySearch(array, x, 0, n - 1);
    t = clock()-t;
    double time_taken = (double)t/CLOCKS_PER_SEC ;
    printf(" Time taken - %lf s\n",time_taken);
   
    if (result == -1) printf("Not found");
    else printf("Element is found at index %d", result);
    return 0;
}
