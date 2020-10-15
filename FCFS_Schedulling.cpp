#include <iostream> 
using namespace std; 

 
int wt[10],bt[10],at[10],tat[10],n;  
float awt,atat;  
void input()
{  
	cout << "Enter Number of processes: ";  
	cin >> n;  
      
    for(int i=0;i<n;i++)  
    {  
        cout << "Enter Burst Time of process " << i+1 << ": ";
        cin >> bt[i];       
		  
        cout << "Enter Arrival Time of process " << i+1 << ": "; 
        cin >> at[i];
		
		cout << endl;         
	}
}  
void calculate()
{  
    wt[0]=0;  
    atat=tat[0]=bt[0];  
    int btt=bt[0];//to store total burst time sum  
      
    for(int i=1;i<n;i++)
	{  
      	wt[i]=btt-at[i];  
      	btt+=bt[i];        
      	awt+=wt[i];     
      	tat[i]= wt[i]+bt[i];   
      	atat+=tat[i];    
    }  
    atat/=n;  
    awt/=n;       
 }  
void display()
{   
    cout << "SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";  
    for(int i=0;i<n;i++)  
    {  
    	cout <<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];   
		cout << "\n";       
    }    
    cout << "Average Waiting Time: "<<awt<<"\nAverage Turn Around Time: "<<atat;  
 }    
int main()
{
    cout<< "FCFS CPU Scheduling Algorithm\n";  
    input();  
    calculate();  
    display();   
    return 0;     
}  
