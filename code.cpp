#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct process_data
{
	int num;
	int p_id;
	int arr_time;
	int burst_time;
	int priority;
	int comp_time;
	int remain_time;
	int wait_time;
	int start_time;
	int respo_time;
};
struct process_data current;
typedef struct process_data p_d;

bool idsort(const p_d &x, const p_d &y)
{
	return x.p_id <y.p_id;
}

bool arrivalsort(const p_d &x , const p_d &y)
{
	if(x.arr_time > y.arr_time)
		return true;
	else if(x.arr_time < y.arr_time)
		return false;
	if(x.priority > y.priority)
		return true;
	else if(x.priority<y.priority)
		return false;
	if(x.p_id>y.p_id)
		return true;
	else
		return false;
}
bool numsort(const p_d &x, const p_d &y)
{
	
}
int main()
{
	int i;
	vector <p_d> input;
	vector <p_d> input_copy;
	p_d temp;
	int fpq_process =0;
	int rrq_process =0;
	int arr_time;
	int remain_time;
	int burst_time;
	int p_id;
	int priority;
	int n;
	int clock;
	int tat = 0;
	cout<<"Enter the Number of Process"<<"endl";
	cin>>n;
	cout<<"order is p_id \t arr_time \t burst_time \t priority"<<"endl";
	for(i=1;i<n+1;i++)
	{
		cin>>p_id>>arr_time>>burst_time>>priority;
		temp.num =i;
		temp.arr_time = arr_time;
		temp.burst_time = burst_time;
		temp.priority = priority;
		temp.p_id = p_id;
	  	temp.remain_time = remain_time;
	  	input.push_back(temp);
		
	}
	input_copy = input;
	sort(input.begin(),input.end());
	
	
}
