#include<iostream>
 
using namespace std;
 
int main()
{
    int fragment[20],b_size[20],p_size[20],i,j,nb,np,temp,highest=0;
    static int flag[20],allocation[20];
   
   
    
    for(i=1;i<=20;i++)
    {
        flag[i]=0;
        allocation[i]=0;
    }
    
    cout<<"\nEnter the number of blocks:";
    cin>>nb;
    cout<<"\nEnter the size of the blocks:-\n";
    for(i=1;i<=nb;i++)
    {
        cout<<"Block no."<<i<<":";
        cin>>b_size[i];
    }
    
    cout<<"Enter the number of processes:";
    cin>>np;
    cout<<"\nEnter the size of the processes :-\n";
    for(i=1;i<=np;i++)
    {
        cout<<"Process no. "<<i<<":";
        cin>>p_size[i];
    }
    
    for(i=1;i<=np;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(flag[j]!=1)
            {
                temp=b_size[j]-p_size[i];
                if(temp>=0)
                    if(highest<temp)
                    {
                        allocation[i]=j;
                        highest=temp;
                    }
            }
        }
        
        fragment[i]=highest;
        flag[allocation[i]]=1;
        highest=0;
    }
    
    cout<<"\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
    for(i=1;i<=np && allocation[i]!=0;i++)
        cout<<"\n"<<i<<"\t\t"<<p_size[i]<<"\t\t"<<allocation[i]<<"\t\t"<<b_size[allocation[i]]<<"\t\t"<<fragment[i];
    
    return 0;
}
