#include <iostream>
using namespace std;
int main()
{
    int n ; 
    cout<<"Enter Process Size-:";
    cin>>n;
    int arrivalTime[n];
    int burstTime[n] ;
    int priority[n + 1] ;
    int x[n];
    for(int i=0;i<n;i++){
    	cout<<"Enter AT , BT , Priority";
    	cin>>arrivalTime[i]>>burstTime[i]>>priority[i];
    }

    int waitingTime[n], turnaroundTime[n], completionTime[n];
    int i, j, smallest, count = 0, time; 
    double avg = 0, tt = 0, end;


    for (i = 0; i < n; i++)
        x[i] = burstTime[i];


    priority[n] = 10000;


    for (time = 0; count != n; time++)
    {
        smallest = n;
        for (i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= time && priority[i] > priority[smallest] && burstTime[i] > 0)
                smallest = i;
        }
        burstTime[smallest]--;
        if (burstTime[smallest] == 0)
        {
            count++;
            end = time + 1;
            completionTime[smallest] = end;
            waitingTime[smallest] = end - arrivalTime[smallest] - x[smallest];
            turnaroundTime[smallest] = end - arrivalTime[smallest];
        }
    }
    cout << "Process"
        << "\t  "
        << "burst-time"
        << "\t "
        << "arrival-time"
        << "\t "
        << "waiting-time"
        << "\t"
        << "turnaround-time"
        << "\t "
        << "completion-time"
        << "\t"
        << "Priority" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << arrivalTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" << completionTime[i] << "\t\t" << priority[i] << endl;
        avg = avg + waitingTime[i];
        tt = tt + turnaroundTime[i];
    }
    cout << "\n\nAverage waiting time time = " << avg / n;
    cout << "  Average turnaround time time = " << tt / n << endl;
}
