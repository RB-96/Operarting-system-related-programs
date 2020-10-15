#include<iostream>
using namespace std;

int at[20],rt[20],bt[20],tat[20], wt[20], t_quantum, n, t=0, total = 0;
float avg_wt, avg_tat;
void input()
{
	cout << "\nEnter the number of proceses: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout <<"\nEnter the burst time for process "<<i+1<<": ";
		cin>>bt[i];
		rt[i] = bt[i];
		at[i]=0;
	
	}
	cout << "\nEnter the time quantum: ";
	cin >> t_quantum;
}

void calculate()
{
	while(1)
	{
		bool done = true;
		for(int i=0;i<n;i++)
		{
			if(rt[i] > 0)
			{
				done = false;
				if(rt[i]>t_quantum)
				{
					t+=t_quantum;
					rt[i]-=t_quantum;
				}
				else
				{
					t+=rt[i];
					wt[i]=t-bt[i];
					rt[i]=0;
				}
			}
		}
		if(done == true)
		{
			break;
		}
	}
	//find waiting time
	
	for(int i=0; i<n; i++)
	{
		total = total + wt[i];
	}
	avg_wt = (total*1.0)/(float)n;
	//find turn around time
	total = 0;
	for(int i=0; i<n; i++)
	{
		tat[i] = wt[i]+bt[i];
		total+=tat[i];
	}
	
	avg_tat = (total*1.0)/(float)n;
}

void display()
{
	cout << "SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";  
    for(int i=0;i<n;i++)  
    {  
    	cout <<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];   
		cout << "\n";       
    }    
    cout << "Average Waiting Time: "<<avg_wt<<"\nAverage Turn Around Time: "<<avg_tat; 
}
int main()
{
	cout << "\t\tRound-Robin schedulling.\n";
	input();
	calculate();
	display();
	return 0;
}
