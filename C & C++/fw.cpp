#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int edge_n = 0;
int node_n = 0;
bool yes = false;


void floyd_warsh(vector<vector<int>>& a){

	for (int k = 0; k < node_n; ++k)
	{
		for (int i = 0; i < node_n ; ++i)
		{
			for (int j = 0; j < node_n; ++j)
			{
				if (a[i][j] > (a[i][k] + a[k][j]) && (a[k][j] != INF   && a[i][k] != INF))     
				   a[i][j] = a[i][k] + a[k][j];
			}
		}
	}


}

int main(){
	int n,m;
	int v,e,w;

	cin >>n>>m;

	node_n = n;
	edge_n = m;

	vector<vector<int>> x(n);
	for (int i = 0; i < n; ++i)
	{

	
		x[i] = vector<int> (n,INF);
		x[i][i] = 0;
	}
	
	while(m > 0){
		
		cin >> v>>e>>w;

		x[v][e] = w;
		m--;
	}

	floyd_warsh(x);

	for(auto it : x){
		for (auto y : it)
		{
			cout << y<<" ";
		}
		cout<<endl;
	}


	int ptr = 0;

	for(auto it : x){
		for (auto y : it)
		{
			cout << y<<" ";
		}
		cout<<endl;
	}


}
