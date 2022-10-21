//algo practise
#include<bits/stdc++.h>
using namespace std;
 
int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
 
int key;

void bin_srch(int ub,int hb){

	int mid = (ub+hb)/2;

	if (key < arr[mid])
	{
		cout<<'1';
		bin_srch(ub ,mid - 1);

	}else if(key > arr[mid]){
		cout<<'2';
		bin_srch(mid+1,hb);
	}else if(arr[mid] == key){
		cout<<'3';
		cout <<endl<<"found at : "<<mid;
	}else{
		cout <<endl<<"found at : Doesn't exist ";
	}


}
 


int main(int argc, char const *argv[])
{
 	int size = sizeof(arr)/sizeof(arr[0]);;
	cout << "Enter search key : ";
	cin >> key; 	

	int ub = 0;
	int hb = size - 1;

	bin_srch(ub,hb);








    
}

