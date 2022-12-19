#include <bits/stdc++.h>
using namespace std;



vector<pair<char,char>> g;


bool has_dup(vector<char> a){
	sort(a.begin(), a.end());
	auto it = std::unique(a.begin(), a.end());
	bool wasUnique = (it != a.end());
	return wasUnique;
}

void push_vec(stack<char>& x,vector<char>& y){
	for (int i = 0; i < y.size(); ++i)
	{
		x.push(y[i]);
	}
}

void get_edge(vector<char>& e,char x){
	cout<<"edges of "<<x<<endl;
	for(auto i: g){
		if(i.first == x){
			cout<<i.second<<" ";
			e.push_back(i.second);
		}
	}
}




int main(){

	int num_nd;
	cout<<"Enter number of nodes: "<<endl;
	cin>>num_nd;
	



	cout<<"Enter edges: "<<endl;

	for (int i = 0; i < num_nd; ++i)
	{
		char x,y;
		cin>>x;
		cin>>y;
		g.push_back({x,y});
	}

	stack<char> stk;
	vector<char> L;

	char src;
	cout<<"enter src: ";
	cin>>src;

	stk.push(src);
	
	while(!stk.empty()){
		char top = stk.top();
		cout<<"top ->"<<top<<endl;
		vector<char> ed;
		L.push_back(top);
		
		stk.pop();
		get_edge(ed,top);
		push_vec(stk,ed);

		if (has_dup(L))
		{
			cout<<endl;
			for(auto i : L){
				cout<<i<<" ";
			}
			cout<<"There is a deadlock;"<<endl;
			break;
		}		


	}	



}
