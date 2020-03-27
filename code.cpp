#include<iostream>
#include<vector>
using namespace std;
 class process{
	public:
	int num;
	int p_id;
	int arr_time;
	int burst_time;
	int priority;
	int fin_time;
	int rem_time;
	int wait_time;
	int start_time;
	int respo_time;
};
typedef process pd;
 
int main()
{
	int i,n;
	vector<pd> input;
	vector<pd> input_copy;
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
	cout<<"Enter the Total Number of Processes: \n";
	cin>>n; 
	cout<<"Sequence of Inputs \n";
	cout<<" 1. Enter the Process id: \t 2.Arrival time \t 3.Burst_time \t 4.Priority   \n";
	process p[n];
	for(i=1;i<=n;i++)
	{   
		cin>>p_id>>arr_time>>burst_time>>priority;
		p[i].p_id = p_id;
		p[i].arr_time = arr_time;
		p[i].burst_time = burst_time;
		p[i].priority =priority; 
	}
	for(i=1;i<=n;i++)
	{
		cout<<p[i].p_id<<"\t"<<p[i].arr_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].priority<<endl;
	}
}
