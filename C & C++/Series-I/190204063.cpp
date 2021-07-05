// online.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int i = 0, j = 0;
int c = 0;


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

bool isSort(int x[], int size) {
	for (j = 0; j < size - 1; j++) {
		if (x[j] > x[j + 1]) {
			return false;
		}
	}
	return true;
}
void sortArr(int x[], int size) {
	
	for (; i < size; i++) {
		if (!isSort(x, size)) {
			for (int step = 0; step < size - 1; step++) {
				int min_idx = step;
				for (int i = step + 1; i < size; i++) {
					if (x[i] < x[min_idx])
						min_idx = i;
				}

				
				swap(&x[min_idx], &x[step]);
			}
		}
		else break;
	}
}
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

int _tmain(int argc, _TCHAR* argv[])
{
	
	int x[] = { 50, 30, 20, 11, 17, 56, 89, 89, 54, 26, 35, 78, 14, 23, 24, 25, 26, 47, 85, 1, 4, 56, 87, 8, 2, 1, 45, 65, 47 };
	clock_t t;
	int tdt = 89;
	int size = sizeof(x) / sizeof(x[0]);
	t = clock();
	sortArr(x, size);
	int result = binarySearch(x, tdt, 0, size);
	t = clock() - t;
	double time_taken = (double)t / CLOCKS_PER_SEC;
	printf(" Time taken - %lf s\n", time_taken);

	
	for (i = 0; i < size; i++) {
		printf("%d ",x[i]);
	}
	if (result == -1) printf("\n Not found");
	else printf("\n Element is found at index %d", result);
	printf("\n");
	printf("Program executed in %lf s",time);
    system("pause");
	return 0;
}

