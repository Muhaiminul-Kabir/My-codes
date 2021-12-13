/*
	merge with vector

*/
#include<bits/stdc++.h>
using namespace std;


vector<int> mx;

void merge(std::vector<char> a,std::vector<char> b){

	int i = 0;
	int j = 0;
	int ap = 0;
	int bp = 0;


	while(i < a.size() && j < b.size()){

		if (a[i] > b[j])
		{
			mx.push_back(b[j]);
			bp++;
			j++;
		}
		else{
			mx.push_back(a[i]);
			ap++;
			i++;	
		}


	}

		if (bp < b.size())
		{
			for (int i = bp; i < (b.size() - bp); ++i)
			{
				mx.push_back(b[i]);
			}
		}

		if (ap < b.size())
		{
			for (int i = ap; i < (a.size() - ap); ++i)
			{
				mx.push_back(a[i]);
			}
		}


}


int main(int argc, char const *argv[])
{
	std::vector<char> a{1,2,3};
	std::vector<char> b{0,1,55};
	merge(a,b);
	for (int i = 0; i < mx.size(); ++i)
	{
	  cout << mx[i]<<" ";
	}	
	return 0;
}
