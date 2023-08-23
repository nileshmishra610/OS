#include <bits/stdc++.h>
using namespace std;
int m[100][6];
void swap(int *x, int *y)
{
    int var = *x;
    *x = *y;
    *y = var;
}
void sortbyarrival(int noofprocess, int m[][6])
{
    for( int i=0;i<noofprocess;i++)
    {
        for(int j=0;j<noofprocess-i-1;j++)
        {
            if(m[j][1]>m[j+1][1])
            {
                for(int k=0;k<5;k++)
                {
                swap(m[j][k],m[j+1][k]);
                }
            }
        }
    }
}
void timeofcompletion(int noofprocess, int m[][6])
{
    int var, ctr;
    m[0][3] = m[0][1] + m[0][2];
    m[0][5] = m[0][3] - m[0][1];
    m[0][4] = m[0][5] - m[0][2];
    for(int i=1;i<noofprocess;i++)
    {
        var=m[i-1][3];
        int lower=m[i][2];
        for(int j=i;j<noofprocess;j++)
        {
            if(var>= m[j][1]&&lower>=m[j][2])
            {
                lower=m[j][2];
                ctr=j;
            }
        }
        m[ctr][3] = var+m[ctr][2];
        m[ctr][5] = m[ctr][3] - m[ctr][1];
        m[ctr][4] = m[ctr][5] - m[ctr][2];
        for(int k=0;k<6;k++)
        {
            swap(m[ctr][k],m[i][k]);
        }
    }
}
int main()
{
    int s,u=0,v=0;
    float x=0,t=0;
    cout<<"Enter Process Size-: ";
    cin>>s;
    for(int i=0;i<s;i++){
    	cout<<"Enter Process Id , Arrival Time , Burst Time-: ";
    	cin>>m[i][0]>>m[i][1]>>m[i][2];
	}
    sortbyarrival(s, m);
    timeofcompletion(s, m);
    cout<<"Process ID   Arrival Time   Burst Time   Starting Time   Complete Time   Turnaround Time   Waiting Time"<<endl;
     	u=m[0][1];
    for(int i=0; i<s; i++)
    {
    		v=u+m[i][2];
   
        cout<<m[i][0]<<"\t\t"<<m[i][1]<<"\t\t"<<m[i][2]<<"\t\t"<<u<<"\t\t"<<v<<"\t\t"<<m[i][5]<<"\t\t"<<m[i][4]<<endl;
        u=v;
    
        x=x+m[i][4];
        t=t+m[i][5];
    }
    cout<<"\nAverage Turnaround Time-:"<<t/s;
    cout<<"\nAverage Wating Time-:"<<x/s;
}
