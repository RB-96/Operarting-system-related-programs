#include<iostream>
#include<math.h>
using namespace std;
#define SIZE 200
int main()
{
	int arr[SIZE], n, r, cn, rn;
	
	cout<<"\nEnter the number of cylinders( < 200): ";
	cin >> n;
	
	cout << "\nEnter No. of requests: ";
	cin >> rn;
	int dist[rn];
	for(int i=0; i<rn; i++)
	{
		dist[i]=999;
	}
	cout << "\nEnter requests: ";
	
	for(int i=0;i<rn;i++)
	{
		cin >> r;
		if(r > 199)
		{
			cout << "\nEntry restricted.\n";
			--i;
			continue;
		}
		arr[i]=r;
	}
	cout <<"\nEnter current disk arm position: ";
	cin >> cn;
	int seek=0, k, min = 999, t;
	for(int i=0;i<rn;i++)
	{
		dist[i] = fabs(arr[i] - cn);
	}
	for(int i = 0; i<rn; i++)
	{
		for(int j=i+1; j<rn; j++)
		{
			if(dist[i]>dist[j])
			{
				int temp = dist[i];
				dist[i] = dist[j];
				dist[j] = temp;
				temp  = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
 			}
		}
	}
	
	for(int i=0; i<rn; i++)
	{
		seek += fabs(arr[i]-cn);
		cn = arr[i];
	}
	cout <<"\nTotal head movement = "<<seek;
	cout <<"\nAverage seek time : "<<(float)seek/rn;
	return 0;
}

