#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void Fun1(int ,int);
void seek(int , int ,int);
int fun1(int diff[][2], int n)
{
	int index = -1;
	int minimum = 1e9;
	for(int i = 0; i < n; i++)
	{
		if (!diff[i][1] && minimum > diff[i][0])
		{
			minimum = diff[i][0];
			index = i;}}
	return index;
}
void seek(int request[],	int head, int n){
	if (n == 0)
	{
		return;
	}
	int diff[n][2] = { { 0, 0 } };
	int seekcount = 0;
	int seeksequence[n + 1] = {0};
	for(int i = 0; i < n; i++)
	{
		seeksequence[i] = head;
		for(int i = 0; i < n; i++)
	{
		diff[i][0] = abs(head - request[i]);
	}
		int index = fun1(diff, n);
		diff[index][1] = 1;
		seekcount += diff[index][0];
		head = request[index];
	}
	seeksequence[n] = head;
	cout << "Total number of seek operations = "<< seekcount << endl;
	cout << "Seek sequence is : " << "\n";
	for(int i = 0; i <= n; i++)
	{
		cout << seeksequence[i] << "\n";
	}
}
int main()
{
	int n,head ;
	cout<<"Enter Process Size";
	cin>>n;
	int request[n] ;
	cout<<"Enter Process Data-:";
	for(int i=0;i<n;i++){
		cin>>request[i];
	}
	cout<<"Enter Head Data-:";
	cin>>head;
	seek(request, head, n);
	return 0;
}
