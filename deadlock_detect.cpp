#include<iostream>
using namespace std;
int adj[50][50];
int p,r;
int cycle;

void detect()
{
	cycle=0;
	int i,j,k=0,k1=0,n,n1,flag,a[20][20],dfs[20][2],s[20],top=-1,start,flag4=0,flag5=0,flag6=0;	   

		n=(p+r);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=adj[i][j];	
					
		}
		dfs[i][0]=0;
		dfs[i][1]=0;
	}
	
	start=1;
	k++;
		dfs[start][0]=k;	/*updating the dfs number of start vertex*/
		top++;
		s[top]=start;		/*pushing the start vertex into stack*/
		
	
		while(top>-1)
		{
			i=start;
			flag=0;
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)	/*if there ia an edge*/
				{
					if(dfs[j][0]==0)	/*if the vertex is unvisited*/
					{
						flag=1;		/*we found an edge from vertex i*/
						
				
						k++;
						dfs[j][0]=k;	/*updating dfs number of vertex j*/
						top++;
						s[top]=j;		/*inserting it into stack*/
						//printf("{%d,%d}",start,j);		/*printing the tree edge*/
						a[i][j]=0;
						start=j;
						break;
					}
				}
			}
			if(flag==0)		/*no egdes found to be traversed form vertex i*/
			{
				k1++;
				dfs[start][1]=k1;	/*updating dfs completion number of vertex*/
				top=top-1;
				start=s[top];
			}
		}
	//forward edges
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				if(a[i][j]==1)
				{
					if((dfs[i][0]<dfs[j][0])&&(dfs[i][1]>dfs[j][1]))
					 {
						
						a[i][j]=0;
						flag4=1;
					 }
				}
		}
	}

	//backward edges
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			  if(a[i][j]==1)
				{
					if((dfs[i][0]>dfs[j][0])&&(dfs[i][1]<dfs[j][1]))
					{
					
                  		a[i][j]=0;
						flag5=1;
					}
				}
		}
	}

	if(flag5==1) 	//if backward edge exist,there is a cycle
	{
		cycle=1;
	}
	
	
	
			


}
int main()
{
	
	int avail[50];
	cout<<"Enter the number of processes : ";
	
	cin>>p;
	cout<<"Enter the number of resources : ";
	
	cin>>r;
	for(int i=1;i<=r;i++)
		avail[i]=1;
	for(int i=1;i<=(p+r);i++)
	{
		for(int j=1;j<=(p+r);j++)
		{
			adj[i][j]=0;
		}
	}
	while(true)
	{
		cout<<"Which process do you want to allocate resouces : ";
		int pr;
		cin>>pr;
		int temp=0,temp1=0;
		cout<<"\nWhich resource do you need ? : ";
		int rr;
		cin>>rr;
		
		if(avail[rr]==1)
		{
			adj[p+rr][pr]=1;	//The resource is allocated to the process
			temp=1;
			avail[rr]--;;
		}
		else
		{
			adj[pr][p+rr]=1;	//the process is waiting for the resource
			temp1=1;
		}
		detect();
		if(cycle==1)
		{
			cout<<"\n\nThe allocation will create deadlock and it is not allowed.";
			if(temp==1)
			{
				adj[p+rr][pr]=0;	//reversing the change
				avail[rr]++;
			}
			else if(temp1==1)
				adj[pr][p+rr]=0;
				
			
		}
		else
		{
			cout<<"\n\nAllocation is successful.\n";
			
			//showing the matrix
			cout<<" \t";
			for(int i=1;i<=(p+r);i++)
			{
				if(i<=p)
					cout<<"P"<<i<<" ";
				else
					cout<<"R"<<(i-p)<<" ";
			}
			cout<<"\n-----------------------------------\n";
			for(int i=1;i<=(p+r);i++)
			{
				if(i<=p)
					cout<<"P"<<i<<"\t";
				else
					cout<<"R"<<(i-p)<<"\t";
				for(int j=1;j<=(p+r);j++)
				{
					cout<<adj[i][j]<<"  ";
				}
				cout<<endl;
			}
		}
		cout<<"\n\nDo you want to continue ? (y/n) : ";
		char c;
		cin>>c;
		if(c=='y')
			continue;
		else
			break;
		
	}
}
