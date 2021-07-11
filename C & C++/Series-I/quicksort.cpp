#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition(int * a, int lb, int ub){
	int start = lb;
	int end = ub;

	int piv = a[lb];
	while (start < end){
		while (a[start] <= piv){
			start++;
		}
		
		while (a[end] > piv){
			end--;
		}
		
		if (start < end){
			swap(&a[start], &a[end]);
		}
	}
	swap(&a[lb], &a[end]);
	
	return end;
}

void quickSort(int *a, int lb, int ub){
	if (lb < ub){
		int loc = partition(a, lb, ub);
		quickSort(a, lb, loc - 1);
		quickSort(a, loc + 1, ub);
	}
}



int main()
{
	int a[] = { 2, 3, 1, 5, 4, 6, 7 };
	int size = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, size - 1);

	for (int i = 0; i < size; i++){
		cout << " "<< a[i];
	}
	cout << endl;
	system("pause");
	return 0;
}

