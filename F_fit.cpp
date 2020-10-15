#include<iostream>
using namespace std;

int main()
{
	int block_size[50], pro_size[50], flag[50], fragment[50], allocation[50];
	
	for(int i=0;i<50;i++)
	{
		flag[i]=0;
		fragment[i]=0;
		allocation[i] = -1;
	}
	cout << "\nEnter the number of blocks: ";
	int nb;
	cin >> nb;
	cout << "\nEnter the block sizes: \n";
	for(int i=0;i<nb;i++)
	{
		cout<<"Block no."<<i<<":";
		cin >> block_size[i];
		
	}
	
	cout << "\nEnter the number of processes: ";
	int np;
	cin >> np;
	cout << "\nEnter the process sizes: \n";
	for(int i=0;i<np;i++)
	{
		cout<<"Process no. "<<i<<":";
		cin >> pro_size[i];
	}
	int temp;
	for(int i = 0; i < np; i++)
	{
		for(int j = 0; j < nb; j++)
		{
			if(flag[j]==0 && block_size[j] >= pro_size[i])
			{
				flag[j]=1;
				allocation[j]=i;
				fragment[j] = block_size[j] - pro_size[i];
				break;
			}
		}
	}
	
	//display allocation details
 	cout<<"\nPartition\tSize\tProcess\tSize\t\tFragment";
	for(int i=0;i < nb;i++)
	{
		cout<<"\n"<<i<<"\t\t"<<block_size[i]<<"\t";	
		if(flag[i])
		{
			cout<<allocation[i]<<"\t"<<pro_size[allocation[i]]<<"\t\t"<<fragment[i];
		}
		else
		{
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		}
		
	}
	
	return 0;
}
