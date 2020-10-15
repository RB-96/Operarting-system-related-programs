#include<iostream>
using namespace std;
int bt[20],process[20],wt[20],tat[20], at[20],i,j,n,total=0,pos,temp;
float wait_avg,TAT_avg;

void input()
{
	cout << "Enter Number of processes: ";  
	cin >> n;  
    cout << "\n";  
    for(int i=0;i<n;i++)  
    {  
        cout << "Enter Burst Time of process " << i+1 << ": ";
        cin >> bt[i];       
		  
        process[i] = i+1;
		at[i]=0;
		cout << endl;         
	}
}

void calculate()
{
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    wt[0]=0;           
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
     //Calculating Average waiting time 
    wait_avg=(float)total/n;
    total=0;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; //Calculating Turnaround Time     
        total+=tat[i];
	}
	TAT_avg=(float)total/n;
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
