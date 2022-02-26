#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> obj;


int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));


	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (obj[i - 1].second <= w)
				K[i][w] = max(obj[i - 1].first + K[i - 1][w - obj[i - 1].second],	K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
	
	int n;
	int p,w;
	cin >> n;
	while(n--){
		cin >> p>>w;
		obj.push_back({p,w});


	}

	int max_w;
	cin >> max_w;

	
	cout << knapSack(max_w, obj.size());
	
	return 0;
}
