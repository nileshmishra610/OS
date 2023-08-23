#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < n ; i++) {
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, at);

    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time\n";
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        cout << "   " << i+1 << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << compl_time << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main() {
	cout<<"Enter Process size";
	int x;
	cin>>x;
    int processes[x];
    int burst_time[x] ;
    int arrival_time[x] ;
    for(int i=0;i<x;i++){
    	cout<<"Enter Process Id , Burst Time and Arrival Time ";
    	cin>>processes[i]>>burst_time[i]>>arrival_time[i];
	}
	

    findAvgTime(processes, x, burst_time, arrival_time);

    return 0;
}
