#include<iostream>
using namespace std;
int main()
{
    int pid[15];
    int bt[15];
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter process id of all the processes: ";
    for(int i=0;i<n;i++)
    {
        cin>>pid[i];
    }
    cout<<"Enter burst time of all the processes: ";
    for(int i=0;i<n;i++)
    {
        cin>>bt[i];
    }
 
    int i, wt[n];
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
 
    cout<<"Process ID     Burst Time     Waiting Time     TurnAround Time\n";
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        cout<<"\t"<<pid[i];
        cout<<"\t\t"<<bt[i];
        cout<<"\t\t"<<wt[i];

        cout<<"\t\t"<<bt[i]+wt[i];
        cout<<endl;

        twt += wt[i];
 
    tat += (wt[i]+bt[i]);
    }
    float att,awt;
 
    awt = twt/n;
 
    att = tat/n;
    cout<<"Avg. waiting time="<<awt<<endl;
    cout<<"Avg. turnaround time="<<att;
}
