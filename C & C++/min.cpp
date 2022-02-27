#include<bits/stdc++.h>
using namespace std;

int total_min = 0;
int minV = 0;
vector<int> pack;
int node = 0;

int minT(vector<int> pack){
      int in = INT_MAX;
      for(int i =0 ;i<pack.size();i++ ){
            if(pack[i] < in){
                  in = pack[i];
            }
      }
      return in;
}



void getMin(vector< vector<int> >& a,int row,int col){

      for(int i = 0; i<node;i++){
            pack.push_back(a[row][i]);
       }
       for(int j = 0; j<node;j++){
            pack.push_back(a[j][col]);

       }
       for(int i =0 ; i<pack.size();i++){
            cout<<pack[i]<<' ';
       }

       minV = minT(pack);
       cout <<"vec "<< minV<<endl;
       total_min += minV;
       pack.clear();



}



int main(){

      int n;
      int in;
      cin >> n;
      node = n;

      vector< vector<int> > x(n);


      cout << "enter mat"<<endl;
	for (int i = 0; i < n; ++i)
	{
            x[i] = vector<int> (n);


	}

	for (int i = 0; i < n; ++i)
	{
            for(int j = 0; j< n;j++)
                  cin>>x[i][j];


	}
	int k = n - 1;

      for(int i = 0; i<n;i++){
            if(k < 0){
                  break;
            }
            getMin(x,i,k);
            k--;
      }
      cout <<"Total min"<<total_min<<endl;







}

