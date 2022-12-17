#include <bits/stdc++.h>
using namespace std;

const int time_q = 3;

class Process{
public:
	int pid;
	int arrival_time;
	int burst_time;
	int comp_time;
	int turn_around_time;
	int response_time;
	bool isPushed;

};

int first_pr(Process p[],int num){
	for (int i = 0; i < num ; ++i)
	{
		if (p[i].arrival_time == 0)
		{
			p[i].isPushed = true;
			return p[i].pid -1;
		}
	}
}


void sort_pr(vector<Process>& vec){
	sort(vec.begin(), vec.end(), [](const Process& lhs, const Process& rhs) {
      return lhs.arrival_time < rhs.arrival_time;
   	});
}

void showq(queue<Process> gq)
{
    queue<Process> g = gq;
    cout<<"printing..."<<endl;
    while (!g.empty()) {
    	Process flag = g.front();
        cout << '\t' << flag.pid;
        g.pop();
    }
    cout << '\n';
}

int time_quantum(int burst_time){
	if (burst_time < time_q)
	{
		return burst_time;
	}
	return time_q;
}


int main()
{
	cout<<"Enter number of processes: "<<endl;
	int num_pr;
	cin>>num_pr;

	Process pr[num_pr];

	for (int i = 0; i < num_pr; ++i)
	{
		cout<<"enter process id: "<<endl;
		cin >> pr[i].pid;

		cout<<"enter process arrival time: "<<endl;
		cin>>pr[i].arrival_time;

		cout<<"enter process burst time: "<<endl;
		cin>>pr[i].burst_time;

		pr[i].isPushed = false;

	}


	queue<Process> ready;
	std::vector<int> incmplt;
	std::vector<Process> sec_vec;
	
	ready.push(pr[first_pr(pr,num_pr)]);
 	
 	cout<<"hola "<<ready.front().pid<<endl;
	int timer = 0; 
	bool init = true;


	while(!ready.empty()){

		Process crnt =  ready.front();
		int index = crnt.pid - 1;
		cout<<"current pr at : P"<<index+1<<endl;



		pr[index].burst_time -= time_quantum(pr[index].burst_time);

		cout<<"current process burst time"<<pr[index].burst_time<<endl;

		if(pr[index].burst_time != 0){
			cout<<"current pr is incomplete..."<<endl;
			incmplt.push_back(pr[index].pid);
		}

		ready.pop();
		cout<<"pr popped..."<<endl;

		timer += time_quantum(crnt.burst_time);
		cout<<"timer at : "<<timer<<endl;



		for (int i = 0;i!=index i < num_pr; ++i)
		{
			if(!pr[i].isPushed && pr[i].arrival_time <= timer){
				sec_vec.push_back(pr[i]);
				pr[i].isPushed = true;
				cout<<"timer at : "<<timer<<" process arrived at: "<<pr[i].arrival_time<<endl;

			}

		}


		cout<<"secondary vector :"<<endl;
		for(auto i : sec_vec){
			cout<<"P"<<i.pid<<endl;
		}
		cout<<"incomplete :"<<endl;
		for(auto i : incmplt){
			cout<<"P"<<i<<endl;
		}
		
		
		sort_pr(sec_vec);
		for(int i = 0; i < sec_vec.size(); i++){
    		ready.push(sec_vec[i]);
		}
		sec_vec.clear();
		cout<<"secondary vector pushed & cleared..."<<endl;
		

		if(!incmplt.empty()) ready.push(pr[incmplt.back() - 1]);
		incmplt.clear();
		showq(ready);
		system("pause");

	}

	cout<<endl<<"Scheduling done successfully!"<<endl;
	system("pause");

	return 0;
}
