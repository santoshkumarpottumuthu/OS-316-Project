#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 class process{ ///displaying the input pattern.
	public:
	int num;		// Total number of Processes 
	int p_id; 		// enter process id's
	int arr_time; 	// arrival time of the process
	int burst_time; // burst_time 
	int priority; //priority
	int fin_time; //finish time of the project
	int rem_time; //time remaining for the process
	int wait_time; //waiting time
	int start_time; //start time of the process
	int respo_time; // starttym - arrival time.
};  
 struct processes{
	public:
	int num;		// Total number of Processes 
	int p_id; 		// enter process id's
	int arr_time; 	// arrival time of the process
	int burst_time; // burst_time 
	int priority; //priority
	int fin_time; //finish time of the project
	int rem_time; //time remaining for the process
	int wait_time; //waiting time
	int start_time; //start time of the process
	int respo_time; // starttym - arrival time.
};
typedef processes pd;
bool arrivalsort( const pd& x ,const pd& y)
{
	if(x.arr_time < y.arr_time)
		return true;
	else if(x.arr_time > y.arr_time)
		return false;
	if(x.priority < y.priority)
		return true;
	else if(x.priority > y.priority)
		return false;
	if(x.p_id < y.p_id)
		return true;

	return false;
}
void check_arrsort(vector <pd> asort)
{
	cout<<"p_id:"<<"\t arr_time \t"<<"burst_time \t"<<"priority"<<endl;
	for(unsigned int i=0 ;i<asort.size();i++ )
	{
		
		cout<<asort[i].p_id<<"\t"<<asort[i].arr_time<<"\t"<<asort[i].burst_time<<"\t"<<asort[i].priority<<endl;;
	}
}
int main()
{
	int i,n;
	std::vector<pd> input;
	vector<pd> input_copy;
	//queue <int> input;
	pd temp;
	int fpq_process =0;
	int rrq_process =0;
	int p_id;
	int arr_time;
	int burst_time;
	int priority;
	int fin_time;
	int rem_time;
	int wait_time;
	int start_time;
	int respo_time;
	int clock;
	cout<<"Enter the Total Number of Processes: \n";
	cin>>n; 
	cout<<"Sequence of Inputs \n";
	cout<<" 1. Enter the Process id: \t 2.Arrival time \t 3.Burst_time \t 4.Priority   \n";
	process p[n];
	for(i=1;i<=n;i++)
	{   
		cin>>p_id>>arr_time>>burst_time>>priority;
		temp.p_id = p_id;
		temp.arr_time = arr_time;
		temp.burst_time = burst_time;
		temp.priority =priority; 
		temp.rem_time = burst_time;
		input.push_back(temp);         
		p[i].p_id = p_id;
		p[i].arr_time = arr_time;
		p[i].burst_time = burst_time;
		p[i].priority =priority; 
		p[i].rem_time = burst_time;
	}

	for(i=1;i<=n;i++)
	{
			cout<<p[i].p_id<<"\t"<<p[i].arr_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].priority<<endl;   //here input is assigned to corresponding obj.
	}
	
   /* while(!input.empty())
    {
    	cout<<"\t "<<input.front();
    	input.pop();
	}*/
	int total_exec_time  =0;
	total_exec_time = total_exec_time + input[0].arr_time;
	for(i=0;i<n;i++)
	{
		if(total_exec_time >= total_exec_time + input[i].arr_time)
		{
			total_exec_time = total_exec_time + input[i].burst_time;
		}
		else
		{
			int dif = (input[i].arr_time - total_exec_time);
			total_exec_time = total_exec_time + dif + burst_time;
		}
	}
	input_copy = input;
	sort( input.begin(), input.end(), arrivalsort );  //sorting using inbuilt function.
	cout<<"arrivalsort : "<<endl;
    check_arrsort( input);
	
	int ghantt[total_exec_time] = {0};
	for(i=0;i<total_exec_time;i++)
	{
		ghantt[i] = -1; //at starting we're fixing -1 for all the slots in ghantt.
		
	}
	cout<<"total_exec_time : "<<total_exec_time<<endl;
	 
   
      
	
	
}
