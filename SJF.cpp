#include<iostream>
using namespace std;
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,totalT=0,pos,temp,at,u=0,v=0;;
    float avg_wt,avg_tat;
    cout<<"Enter number of process:";
	cin>>n ;
	cout<<"Enter All Process Arrival Time-:";
	cin>>at;
    cout<<"\nEnter Burst Time:\n";
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<":";
        cin>>bt[i];
        p[i]=i+1;
    }
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
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];   
    }
    avg_wt=(float)total/n;  
    cout<<"\nProcess \t Arrival Time \t Burst Time \t Stating Time \t Complete Time \t Waiting Time \t Turnaround Time";
    u=at;
    for(i=0;i<n;i++)
    {
    	v=u+bt[i];
        tat[i]=bt[i]+wt[i]; 
        totalT+=tat[i];      
        printf("\np%d\t\t %d\t\t %d\t\t\t%d\t\t%d\t\t%d\t\t%d",p[i],at,bt[i],u,v,wt[i],tat[i]);
         u=v;
    }
    avg_tat=(float)totalT/n;     
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}
