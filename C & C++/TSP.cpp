#include <bits/stdc++.h>
#include <windows.h>

using namespace std;


const int N = 1e5 + 3;
const int INF = 1e9;
const int src = 0;

int col_n = 0;
int row_n = 0;
int row_red = 0;
int col_red = 0;
int pcst = 0;
int cst = 0;
int s = 0;
int minp = 0;
int ncst = 0;

bool init = true;
bool inf = false;


vector<int> temp_row;
vector<int> temp_col;
vector<int> path;

vector<vector<int>> g,temp;
vector<vector<vector<int>>> pack;
vector<pair<int,int>> node_cost;

vector<bool> vis;

bool compare(std::pair<int, int> p1, std::pair<int,int> p2) {
    return p1.second<p2.second;
}



bool isVis(){
	for (auto i : vis)
	{
		if(i != 1){
			return false;
		}
	}
	return true;
}
 
bool chk_inf(vector<vector<int>> c){
	for(auto it : c){
		if (it[1] == INF)
		{
			
			continue;
		}
		else{
			
			return false;
		}
	}
	cout<< "all infinity"<<endl;
	return true;
}


int path_cst(int src,int des){
	for(auto i : g){
		if(i[0] == src && i[1] == des){
			return i[2];
		}
	}
}


void row(int start, vector<vector<int>>& x){
	
	int min ;
	int ptr = 0;

	for(auto it : x){
		if(it[0] == start){
			temp_row.push_back(it[2]);
		}
		
	}

	cout<<"temp_row"<<endl;
	for(auto i:temp_row){
		cout<<i<<" ";
	}
	cout<<endl;
	
    min = *min_element(temp_row.begin(), temp_row.end());
    if(min == INF){
    	cout<<"problem"<<endl;
    	return;
    }
    cout<<"minimum here "<<min<<endl;

	for(auto it : x){
		if(it[0] == start && it[2] != INF){
			x[ptr][2] -= min;
			

		}
		ptr++;
		
	}


	row_red += min;
	temp_row.clear();
	
}

void col(int start, vector<vector<int>>& x){

	int min ;
	int ptr = 0;

	for(auto it : x){
		if(it[1] == start){
			temp_col.push_back(it[2]);
		}

		
	}
	cout<<"temp_col"<<endl;
	for(auto i:temp_col){
		cout<<i<<" ";
	}
	cout<<endl;
	

    min = *min_element(temp_col.begin(), temp_col.end());
    if(min == INF){
    	cout<<"problem"<<endl;
    	return;
    }

	cout<<"minimum here "<<min<<endl;

	for(auto it : x){

		if(min != INF && it[1] == start && it[2] != INF){
			x[ptr][2] -= min;

		}
		ptr++;		
	}

	col_red += min;
	temp_col.clear();
	cout<<"NN"<<temp_col.size();
	
}

void proc(vector<vector<int>> g1,int src,int des){
	if(!init) {
		pcst = path_cst(src,des);

	}

	row_red = col_red = 0;

	if(!init){
		int ptr = 0;
		
		for(auto i : g1){
			if(i[0] == src || i[1] == des){
				g1[ptr][2] = INF;
			}
			ptr++;
			
		}
	}
	//row red
	for (int i = 0; i < row_n; ++i)
	{
		row(i,g1);
	}
	//co; red
	for (int i = 0; i < col_n; ++i)
	{

		col(i,g1);
	}

	cout<<"paths in proc"<<endl;
	for(auto i : g1){
			
			cout<<i[0]<<" "<<i[1]<<" ";
			if(i[2] == INF)cout<<"INF"<<endl;
			else cout<<i[2]<<endl;
		}
	cout<<"node cost = "<<ncst<<endl;
	
	cst = pcst + ncst + row_red + col_red;
	if(init){
		temp = g1;
	}

	if(!init){
		node_cost.push_back({des,cst});
		pack.push_back(g1);
	}
	cout<<"pcst = "<<pcst<<endl;
	cout<<"row_red = "<<row_red<<endl;
	cout<<"col_red = "<<col_red<<endl;
	cout<<"cost = "<<cst<<endl;
	


	//
}


void TSP(){

		proc(g,0,0);
		//node_cost.push_back(cst);
		ncst = cst;
	
		init = true;

		path.push_back(0);		
 		
 		while(!isVis()){
 			cout << isVis()<<endl;
 			

 			if(!init) {
 				const auto p = min_element(node_cost.begin(), node_cost.end(), compare);
				s = p->first;
				ncst = p->second;
				cout<<"s node cst "<< ncst<<endl;
				minp = std::min_element(node_cost.begin(),node_cost.end(),compare) - node_cost.begin();
				temp = pack[minp];
 				
				cout<<"min index "<<minp<<endl;
				cout<<"pack size "<<pack.size();
 				path.push_back(s);
 			}
 			vis[0] = 1;
 			if(vis[0] == 1){
 				cout<<"false"<<endl;
 				init = false;
 			}
		    cout <<"src "<< s<<endl;
			

			
			

			node_cost.clear();


			if(!init){
				pack.clear();
				for(auto it : g){
					vis[s] = 1;
					if(it[0] == s && vis[it[1]] == 0){

						cout<<"s status "<<vis[s]<<endl;
						cout<<"visiting proc() -> "<<s<<","<<it[1]<<endl;
						proc(temp,s,it[1]);
						cout<<"out proc "<<node_cost.back().second<<endl;
						
						system("pause");
						
					}
				}

			}
			


			Sleep(4000);




 		}
 		cout<<endl;

 		cout<<"last source "<<s<<endl;
 		cst += path_cst(s,0);
		cout<<endl<<endl;
		cout<<"total cost "<<cst<<endl;




		//cout << s <<endl;
	  //  proc(src);

	
}




int main(int argc, char const *argv[])
{
	//node_cost.push_back({1});
	
	int n,m;
	int s,d,c;
	cin >> n >> m;
	row_n = col_n = n;
	
	//vis = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		vis.push_back(0);
	}

	for (int i = 0; i < n; ++i){
		g.push_back({i,i,INF});
		
	}


	for (int i = 0; i < m; ++i)
	{
		cin >> s>>d>>c;

		g.push_back({s,d,c});
	}
	//row();

	 
	//print vector
	for(auto i: g){
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
 

	TSP();
	cout << "done"<<endl;



	for(auto i : path){
		cout << i<<"--";
	}
	cout<<src<<endl;



	return 0;
}
