#include<iostream>
#include<climits>
using namespace std;
int bt[20],process[20],wt[20],tat[20], at[20],rt[20],i,j,n,total=0,pos,temp;
float wait_avg,TAT_avg;

void input()
{
	cout << "Enter Number of processes: ";  
	cin >> n;  
    cout << "\n";  
    for(int i=0;i<n;i++)  
    {  
        cout << "Enter Burst Time of P" << i+1 << " : ";
        cin >> bt[i];       
		rt[i] = bt[i];
		cout <<"\nEnter the arrival time of P"<<i+1<<" : ";
		cin >> at[i];
        process[i] = i+1;
		cout << endl;         
	}
}

void calculate()
{
	int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    
    while(complete != n)
    {
    	for (int j = 0; j < n; j++) 
		{
            if ((at[j] <= t) && (rt[j] < minm) && (rt[j] > 0) )
			{
                minm = rt[j];
                shortest = j;
                check = true;
            }
		}
	
	
		if (check == false) 
		{
        	t++;
        	continue;
    	}
 
        // Reduce remaining time by one
		rt[shortest]--;
 
        // Update minimum
    	minm = rt[shortest];
    	if (minm == 0)
    	    minm = INT_MAX;
    	if (rt[shortest] == 0) {
 
            // Increment complete
            complete++;
 
            // Find finish time of current
            // process
            finish_time = t + 1;
 
            // Calculate waiting time
            wt[shortest] = finish_time -
                        bt[shortest] -
                        at[shortest];
 
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        // Increment time
        t++;
	}
	
	for(int i=0; i<n;i++)
	{
		total = total + wt[i];
	}
	wait_avg = (float)total*1.0/n;
	total = 0;
	for(int i=0; i<n; i++)
	{
		tat[i] = bt[i]+wt[i];
		total = total + tat[i];
	}
	TAT_avg = (float)total*1.0/n;
}

void display()
{
	cout << "SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";  
    for(int i=0;i<n;i++)  
    {  
    	cout <<process[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];   
		cout << "\n";       
    }    
    cout << "Average Waiting Time: "<<wait_avg<<"\nAverage Turn Around Time: "<<TAT_avg; 
}
int main()
{
	cout << "\t\tSJF Schedulling Algorithm.\n";
	input();
	calculate();
	display();
	return 0;
	

}
