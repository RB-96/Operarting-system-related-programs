#include<iostream>
using namespace std;
int bt[20],p[20],at[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
float avg_wt,avg_tat;

void input()
{
	cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nBurst time for Process "<< i+1 << ": ";
        
        cin>>bt[i];
        cout<<"Priority for Process " << i+1 << ": ";
        cin>>pr[i];
        at[i]=0;
        p[i]=i+1;           //contains process number
        
    }
}

void calculate()
{
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
    
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
	}
	
	avg_tat=total/n;     //average turnaround time
}

void display()
{
	cout << "SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";  
    for(int i=0;i<n;i++)  
    {  
    	cout <<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];   
		cout << "\n";       
    }    
    cout << "Average Waiting Time: "<<avg_wt<<"\nAverage Turn Around Time: "<<avg_tat; 
}
int main()
{
	cout << "\t\tPriority Schedulling <Preemptive> algorithm.\n";
	input();
	calculate();
	display();
    return 0;
}
