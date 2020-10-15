#include<iostream>
using namespace std;

int frame[100];
int page[100];
int hit;
int f;
int pgfault=0;
int isHit(int x)
{
	
	for(int i=0;i<f;i++)
	{
		if(frame[i]==x)
		{
			hit=1;
			break;
		}
		else hit=0;
	}
	
	return hit;
}
void show_frame()
{
	for(int i = 0; i < f; i++)
	
        cout<<frame[i]<<" ";
}

void dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d",pgfault);
}

int main()
{
	cout << "Enter number of frames required: "<<endl;
	
	cin >> f;
	for(int k=0;k<f;k++)
	{
		frame[k]=-99;//stands for empty
	}
	cout<<"Enter the number of pages : ";
    int n;
    cin>>n;
    cout<<endl<<"Enter the page numbers : ";
    for(int i=0;i<n;i++)
    {
		cin>>page[i];
    }
	
	int near[50];
    for(int i=0; i<n; i++)
    {

        cout<< "\nFor "<<page[i]<<" : ";

        if(isHit(page[i])==0)
        {

            for(int j=0; j<f; j++)
            {
                int pg=frame[j];
                int found=0;
                for(int k=i+1; k<n; k++)
                {
                    if(pg==page[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(int j=0; j<f; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            frame[repindex]=page[i];
            pgfault++;

            show_frame();
        }
        else
            cout << "No page fault";
    }
    dispPgFaultCnt();
	return 0; 
}
