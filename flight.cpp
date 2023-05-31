#include<iostream>
using namespace std;
int adj_m[10][10];

void traverse(int i, int n,bool visited[]){
	visited[i] = true;
	for (int j=0; j<n;j++){
		if(adj_m[i][j] !=0){
			if(!visited[j]){
				traverse(j,n,visited);
			}
		}
	}
}

bool isconnected(int n){
	bool visited[10];
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			visited[j] = false;
			traverse(i, n, visited);
			for(int k=0;k<n;k++){
				if(!visited[k]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int n;
	char ch;
	cout<<"Enter no of cities: ";
	cin>>n;
	
	char arr[n][20];
	for (int i=0;i<n;i++){
		cout<<"Enter "<<i+1<<" city name: ";
		cin>>arr[i];
	}
	
	for (int i = 0;i<n;i++){
		for(int j=0; j<n; j++){
			cout<<"IS city "<<arr[i]<<" is connected to city "<<arr[j]<<"(y/n): ";
			cin>>ch;
			
			if(ch == 'y'){
				cout<<"Enter fuel required to reach city "<<arr[j]<<": ";
				cin>>adj_m[i][j];
			}
			else{
				adj_m[i][j] = 0;
			}
		}
		cout<<"--------------------------------------------------------------------------\n";
	}
	
	cout<<"ADJ Matrix\n\n";
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj_m[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	if(isconnected(n)){
		cout<<"Graph is connected";
	}
	else{
		cout<<"Graph is not connected";
	}
	return 0;
}
