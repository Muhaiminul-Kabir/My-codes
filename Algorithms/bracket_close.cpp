//algo practise
#include<bits/stdc++.h>
using namespace std;
 


int main(){

	char arr0[] = {'(','{','['};
	char arr1[] = {')','}',']'};

	int sig[] = {0,0,0};
	int init[] = {0,0,0};

	string str;

	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(str[i] == arr0[j]){
				sig[j]++; 
				init[j]++;

			}else if(str[i] == arr1[j]){
				if (init[j] != 0)
				{
					sig[j]--;
				}else{
					cout << "not closed";
					return 0;
				}
			}
		}
	}
	int sum=0;
	for (int i = 0; i < 3; ++i){
		sum+=sig[i];
	}
	if(sum > 0){
		cout<< "not closed";
		return 0;
	}
	cout << "closed";
 
}




