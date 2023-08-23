#include <bits/stdc++.h>
using namespace std;
void FCFS(int arr[], int head,int size)
{
	int seek_count = 0;
	int distance, cur_track;
	for (int i = 0; i < size; i++) {
		cur_track = arr[i];
		distance = abs(cur_track - head);
		seek_count += distance;
		head = cur_track;
	}
	cout << "Total number of seek operations = "<< seek_count << endl;
	cout << "Seek Sequence is" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}
int main()
{
	int size;
	cout<<"Enter Size";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	int head ;
	cout<<"Enter Head";
	cin>>head;
	FCFS(arr, head,size);
	return 0;
}
