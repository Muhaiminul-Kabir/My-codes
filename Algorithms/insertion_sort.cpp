//algo practise
#include<bits/stdc++.h>
using namespace std;
 
int arr[] = {2,13,4,2,1,34,6,7,8,9,2};
 
 
void insert(int i , int j){
	int key = arr[i];
    
	for(int k = i; k>j ; k--){
		arr[k] = arr[k-1];
	}
	arr[j] = key;
}


int main(int argc, char const *argv[])
{
 	int size = sizeof(arr)/sizeof(arr[0]);;

 	for (int i = 1; i < size; ++i)
 	{
 		for(int j = 0;j<i ;j++){
 			if (arr[i] < arr[j])
 			{
 				insert(i,j);
 				break;
 			}
 		}
 	}





 	for (int i = 0; i < size; ++i)
 	{
 		cout<<arr[i]<<" ";
 	}

    
}


