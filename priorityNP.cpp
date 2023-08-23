#include <iostream>
using namespace std;

int main()
{
    int n ; 
	cout<<"Enter Process Size-:";
    cin>>n;    
    int at[n];
    int bt[n] ;
    int priority[n] ;
    for(int i=0;i<n;i++){
    	cout<<"Enter AT , BT , Priority";
    	cin>>at[i]>>bt[i]>>priority[i];
    }
    int CPU = 0;     
    int allTime = 0; 

   
    int ATt[n];
    int NoP = n; 
    int PPt[n];
    int wt[n];
    int tat[n];
    int i = 0;

    for (i = 0; i < n; i++)
    {
        PPt[i] = priority[i];
        ATt[i] = at[i];
    }

    int LAT = 0; 
    for (i = 0; i < n; i++)
        if (at[i] > LAT)
            LAT = at[i];

    int MAX_P = 0; 
    for (i = 0; i < n; i++)
        if (PPt[i] > MAX_P)
            MAX_P = PPt[i];

    int ATi = 0;     
    int P1 = PPt[0]; 
    int P2 = PPt[0]; 

    int j = -1;
    while (NoP > 0 && CPU <= 1000)
    {
        for (i = 0; i < n; i++)
        {
            if ((ATt[i] <= CPU) && (ATt[i] != (LAT + 10)))
            {
                if (PPt[i] != (MAX_P + 1))
                {
                    P2 = PPt[i];
                    j = 1;

                    if (P2 < P1)
                    {
                        j = 1;
                        ATi = i;
                        P1 = PPt[i];
                        P2 = PPt[i];
                    }
                }
            }
        }

        if (j == -1)
        {
            CPU = CPU + 1;
            continue;
        }
        else
        {
            wt[ATi] = CPU - ATt[ATi];
            CPU = CPU + bt[ATi];
            tat[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT + 10;
            j = -1;
            PPt[ATi] = MAX_P + 1;
            ATi = 0;        
            P1 = MAX_P + 1;
            P2 = MAX_P + 1;
            NoP = NoP - 1;
        }
    }

    cout << "\nProcess_Number\tBurst_Time\tPriority\tArrival_Time\tWaiting_Time\tTurnaround_Time\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << bt[i] << "\t\t" << priority[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    float AvgWT = 0;  
    float AVGTaT = 0; 
    for (i = 0; i < n; i++)
    {
        AvgWT = wt[i] + AvgWT;
        AVGTaT = tat[i] + AVGTaT;
    }

    cout << "Average waiting time = " << AvgWT / n << endl;
    cout << "Average turnaround time = " << AVGTaT / n << endl;
}
