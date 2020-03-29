#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 class process{ ///displaying the p_data pattern.
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
	int t_a_time; //turn around time
	int avg_tat;
	int avg_wait_time;
	int total_t_a_time;
	int total_wait_time;
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
	int t_a_time; //turn around time
	int avg_tat;
	int avg_wait_time;
	int total_t_a_time;
	int total_wait_time;
};
struct processes curr;
typedef struct processes pd;
bool pidsort(const pd &a , const pd &b)
{
	return a.p_id < b.p_id;
}
const arrsort(const pd&a ,const pd&b)
{
	if(a.arr_time < b.arr_time)
		return a.arr_time;
	else if(a.arr_time > b.arr_time)
		return b.arr_time;
	if(a.priority < b.priority)
		return a.priority;
	else if(a.priority > b.priority)
		return b.priority;
	if(a.p_id < b.p_id)
		return a.p_id;

	return b.p_id;
}
void arrsortcheck(vector <pd> asort)
{cout<<"p_id:"<<"\t arr_time \t"<<"burst_time \t"<<"priority"<<endl;
	for(unsigned int m=0 ;m<asort.size();m++ )
	{
		
		cout<<asort[m].p_id<<"\t"<<asort[m].arr_time<<"\t\t"<<asort[m].burst_time<<"\t\t"<<asort[m].priority<<endl;;
	}
}
struct compare
{
	bool operator()(const pd& a ,const pd&b)
	{
		if( a.priority > b.priority )
			return true;
		else if( a.priority < b.priority )
			return false;
		if(a.p_id > b.p_id )
			return true;

		return false;
		
	}
	
};
bool num__sort( const pd&a ,const pd& b)
{
	return a.num < b.num;
}
bool p_idsort(const pd&a , const pd&b)
{
	return a.p_id < b.p_id;
}
int main()
{
	int m,n,time;
	vector <pd> p_data;
	pd temp;
	int fpq_process =0;
	int rrq_process =0;
	int p_id;
	int arr_time;
	int burst_time;
	int priority;
	int total_exec_time =0;
	int total_t_a_time;
	int total_wait_time;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\tEnter the Total Number of Processes. \n";
	
	cin>>n;
	cout<<"The Sequence of Inputs is: \n";
	cout<<" 1. Enter the Process id: \t 2.Arrival time \t 3.Burst_time \t 4.Priority   \n";
	cout<<"Enter all the details of one Process then only go with the next process \n";
	process p[n];
	
	for(m=0;m<n;m++)
	{
		cin>>p_id>>arr_time>>burst_time>>priority;
		temp.num = m+1;
		temp.arr_time = arr_time;
		temp.burst_time = burst_time;
		temp.rem_time = burst_time;
		temp.p_id = p_id;
		temp.priority = priority;
		p_data.push_back(temp);
		p[m].p_id = p_id;
		p[m].arr_time = arr_time;
		p[m].burst_time = burst_time;
		p[m].priority =priority; 
		p[m].rem_time = burst_time;
	}
	sort(p_data.begin(),p_data.end(),arrsort);
	cout<<"Enter Time Quantum Value : should be Multiple of 2 . \n";
	int timequant;
	cin>>timequant;
	cout<<"Given Inputs:"<<endl;
	cout<<"p_id"<<"\t"<<"arr_time"<<"\t"<<"burst_time"<<"\t"<<"priority"<<endl;
	for(m=0;m<n;m++)
	{
			cout<<p[m].p_id<<"\t"<<p[m].arr_time<<"\t\t"<<p[m].burst_time<<"\t\t"<<p[m].priority<<endl;   //here p_data is assigned to corresponding obj.
	}
	
	cout<<"After Arrival Sort:"<<endl;
	arrsortcheck(p_data);
	total_exec_time = total_exec_time + p_data[0].arr_time;
	 for( m= 0 ;m< n; m++ )
    {
    	if( total_exec_time >= p_data[m].arr_time )
    	{
    		total_exec_time = total_exec_time +p_data[m].burst_time;
    	}
    	else
    	{
    		int dif = (p_data[m].arr_time - total_exec_time);
    		total_exec_time = total_exec_time + dif + burst_time;

    	}
    }
    int ghantt[total_exec_time] = {0};
    for( m= 0; m< total_exec_time; m++ )
	{
		ghantt[m]=-1;
	}
	priority_queue < pd ,vector<processes> ,compare> fpq;
	queue< pd > rrq;
	int cpu__state =0;
	curr.p_id = -3;
	curr.priority = 99999;
	int time_quant =timequant;
	for ( time = 0; time< total_exec_time; time++ )
	{
		/**Insert the process with same Arrival time in Priority Queue**/
		for( int j = 0; j< n ; j++ )
		{
			if(time == p_data[j].arr_time)
			{
				fpq.push(p_data[j]);
			}
		}
		

		if(cpu__state == 0) //If CPU idle
		{
			if(!fpq.empty())
			{
				curr = fpq.top();
				cpu__state = 1;
				fpq_process = 1;
				fpq.pop();
				time_quant = timequant; 
			}
			else if(!rrq.empty())
			{
				curr = rrq.front();
				cpu__state = 1;
				rrq_process = 1;
				rrq.pop();
				time_quant = timequant;
			}
		}
		else if(cpu__state == 1) //If cpu has any procss
		{
			if(fpq_process == 1 && (!fpq.empty()))
			{
				if(fpq.top().priority < curr.priority ) //If new process has high priority
				{
					rrq.push(curr); //push curr in RQ
					curr = fpq.top();
					fpq.pop();
					time_quant = timequant; 
				}
			}
			else if(rrq_process == 1 && (!fpq.empty())) //If process is from RQ and new process come  in PQ
			{
				rrq.push(curr);
				curr = fpq.top();
				fpq.pop();
				rrq_process = 0;
				fpq_process = 1;
				time_quant = timequant ;
			}
			

		}


		if(curr.p_id != -3) // Process Execution
		{
			curr.rem_time--;
			time_quant--;
			ghantt[time] = curr.p_id;
			if(curr.rem_time == 0) //If process Finish
			{
				cpu__state = 0 ;
				time_quant = 4 ;
				curr.p_id = -3;
				curr.priority = 99999;
				rrq_process = 0;
				fpq_process = 0;
			}
			else if(time_quant == 0 ) //If time Qunatum of a curr running process Finish
			{
				rrq.push(curr);
				curr.p_id = -3;
				curr.priority = 99999;
				rrq_process = 0;
				fpq_process = 0;
				cpu__state=0;

			}

		}
		
	}
	sort( p_data.begin(), p_data.end(), p_idsort );//sort according to p_id
	for(int m=0;m<n;m++)//assigning finish time
	{
		for(int t=total_exec_time;t>=0;t--)
		{
			if(ghantt[t]==m+1)
			{
				p_data[m].fin_time=t+1;
				break;

			}
		}
	}
	for(int m=0;m<n;m++) //now assigning start time to each process 
	{
		for(int t=0;t<total_exec_time;t++)
		{

			if(ghantt[t]==m+1)
			{
				p_data[m].start_time=t;
				break;
			}
		}
	}
	
	sort( p_data.begin(), p_data.end(), num__sort ); //again sorting on the basis of number which is defined at the start
	for(int m=0;m<n;m++)
	{	
		p_data[m].respo_time=p_data[m].start_time-p_data[m].arr_time;
		//p_data[m].wait_time=(p_data[m].fin_time-p_data[m].arr_time)-p_data[m].burst_time;
		p_data[m].t_a_time = p_data[m].fin_time - p_data[m].arr_time;
		p_data[m].wait_time = p_data[m].t_a_time - p_data[m].burst_time;
		total_t_a_time += p_data[m].t_a_time;
		total_wait_time += p_data[m].wait_time;
		
	}
	cout<<"Note : \n Turn around time = finish_time - arrival_time"<<endl;
   	cout<<" wait time = Turn around time - finish_time"<<endl;
	float avg_t_a_time = total_t_a_time/n;
	float avg_wait_time = total_wait_time /n;
	cout<<"------------------------------------------------------------------------------------"<<endl;
	cout<<"-------------------------------Final Output-----------------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------------------"<<endl;
	
	cout<<"p_id\t"<<"arr_time\t"<<"burst_time\t"<<"priority\t"<<"fin_time\t"<<"respo_time\t"<<"turnaroundt\t"<<"wait_time"<<endl;
	
	for(int m=0;m<n;m++)
	{
		cout<<"P"<<p_data[m].p_id<<"\t"<<p_data[m].arr_time<<"\t\t"<<p_data[m].burst_time<<"\t\t"<<p_data[m].priority<<"\t\t"<<p_data[m].fin_time<<"\t\t"<<p_data[m].respo_time<<"\t\t"<<p_data[m].t_a_time<<"\t\t"<<p_data[m].wait_time<<endl;
		
}
//calculating the avg_t_a_time and avg_wait_time
		cout<<"---------------------------------------------------------------------------------"<<endl;
		cout<<"----------------------------------------------------------------------------------"<<endl;
		cout<<"avg_t_a_time = "<<setprecision(3)<<avg_t_a_time<<endl;
		cout<<"avg_wait_time ="<<setprecision(3)<<avg_wait_time<<endl;
return 0;
}








