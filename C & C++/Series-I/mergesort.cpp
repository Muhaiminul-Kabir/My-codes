#include <iostream>
#include <stdio.h>
using namespace std;

int a[] = { 2, 3, 1, 5, 4, 6, 7 };
const int size = sizeof(a) / sizeof(a[0]);


//a,lb,mid,ub
void merge(int arr[], int p, int q, int r)
{
		int n1 = q - p + 1;
		int n2 = r - q;

		int L[n1], M[n2];

		for (int i = 0; i < n1; i++)
			L[i] = arr[p + i];
		for (int j = 0; j < n2; j++)
			M[j] = arr[q + 1 + j];

		int i, j, k;
		i = 0;
		j = 0;
		k = p;
		while (i < n1 && j < n2) {
			if (L[i] <= M[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = M[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = M[j];
			j++;
			k++;
		}
	

}

void mergeSort(int *a, int lb, int ub){
	if (lb < ub){
		int mid = (lb + ub) / 2;

		mergeSort(a, lb, mid);
		mergeSort(a, mid + 1, ub);
		merge(a, lb, mid, ub);
	}
}



int main()
{
	
    mergeSort(a, 0, size - 1);

	for (int i = 0; i < size; i++){
		cout << " "<< a[i];
	}
	cout << endl;
	system("pause");
	return 0;
}

