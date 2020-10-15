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
	cout <<"\nEnter cyl. no. where current disk arm is situated: ";
	cin >> cn;
	int seek=0;
	seek = fabs(arr[0]-cn);
	for(int i=0;i<rn-1;i++)
	{
		int diff = fabs(arr[i]-arr[i+1]);
		seek+=diff;
	}
	cout <<"\nTotal head movement = "<<seek;
	cout <<"\nAverage seek time : "<<(float)seek/rn;
	return 0;
}
