#include <bits/stdc++.h>
using namespace std;


class Process{
public:
	int pid;
	int arrival_time;
	int burst_time;
	int comp_time;
	int turn_around_time;
	int waiting_time;
	int response_time;
	int cpu_flag;
	bool isCompleted;
	

};



string pipe = "";

int first_pr(Process p[],int num){
	for (int i = 0; i < num ; ++i)
	{
		if (p[i].arrival_time == 0)
		{
			
			return p[i].pid -1;
		}
	}
}

bool allDone(Process p[],int num){
	for (int i = 0; i < num ; ++i)
	{
		if (p[i].burst_time != 0)
		{
			return false;
		}
	}	
	return true;
}

void sort_pr(vector<Process>& vec){
	sort(vec.begin(), vec.end(), [](const Process& lhs, const Process& rhs) {
      return lhs.burst_time > rhs.burst_time;
   	});
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

		
		pr[i].cpu_flag = pr[i].burst_time;

	}

	std::vector<Process> sec_vec;
	
	sec_vec.push_back(pr[first_pr(pr,num_pr)]);
 	
 	cout<<"hola "<<sec_vec.back().pid<<endl;
	int timer = 0; 
	bool init = true;


	while(!allDone(pr,num_pr)){

		Process crnt =  sec_vec.back();
		int index = crnt.pid - 1;
		cout<<"current pr at : P"<<index+1<<endl;



		pr[index].burst_time --;

		cout<<"current process burst time"<<pr[index].burst_time<<endl;

		



		sec_vec.clear();
		cout<<"vector cleared..."<<endl;

		timer ++;
		pipe +="---P"+to_string(crnt.pid)+"---"; 
		
		if (pr[index].burst_time == 0)
		{
			pr[index].isCompleted = true;
			cout<<"calculating other properties..."<<endl;
			pr[index].comp_time = timer;
			pr[index].turn_around_time = pr[index].comp_time - pr[index].arrival_time;
			pr[index].waiting_time = pr[index].turn_around_time - pr[index].cpu_flag;
		}


		cout<<"timer at : "<<timer<<endl;



		for (int i = 0; i < num_pr; ++i)
		{
			if(!pr[i].isCompleted && pr[i].arrival_time <= timer){
				sec_vec.push_back(pr[i]);
				
				cout<<"timer at : "<<timer<<" process arrived at: "<<pr[i].arrival_time<<endl;

			}

		}


		
		
		
		sort_pr(sec_vec);
		
		cout<<"secondary sorted..."<<endl;
		

		cout<<"secondary vector :"<<endl;
		for(auto i : sec_vec){
			cout<<"P"<<i.pid<<" with cpu time -> "<<i.burst_time<<endl;
		}
		
		cout<<pipe;
		system("pause");

	}

	int sum_wt=0;
	int sum_tt = 0;

	for (int i = 0; i < num_pr; ++i)
	{
		cout<<"id \t"<<" "<<"Waiting time \t"<<"Turn around time\t"<<endl;
		cout<<"P"<<pr[i].pid<<" "<<pr[i].waiting_time<<"\t"<<pr[i].turn_around_time<<"\t"<<endl;
		sum_tt += pr[i].turn_around_time;
		sum_wt += pr[i].waiting_time;
	}	
	cout<<"Average waiting time: "<<(double)sum_wt/num_pr<<endl;
	cout<<"Average turn around time: "<<(double)sum_tt/num_pr;


	cout<<endl<<"Scheduling done successfully!"<<endl;
	system("pause");

	return 0;
}
