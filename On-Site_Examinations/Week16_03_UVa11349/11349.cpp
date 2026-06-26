#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int s=0; s<N; s++){
		char n1,n2;
		cin>>n1>>n2;
		int n;
		cin>>n;
		
		bool issym=1;
		long long a[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
				if(a[i][j]<0)issym=0;
			}
		}
		
		int mid=n/2;
		if(issym==1){
			if(n==1){
				if(a[0][0]<0)issym=0;
			}
			else{
				if(n%2==1){
					// if(a[mid][mid]!=0)issym=0;
					for(int i=0; i<mid; i++){
						for(int j=0; j<n; j++){
							if(a[i][j]!=a[n-1-i][n-1-j])issym=0;
						}
					}
					for(int j=0; j<mid; j++){
						if(a[mid][j]!=a[mid][n-1-j])issym=0;
					}
				}
				else{
					for(int i=0; i<n; i++){
						for(int j=0; j<n; j++){
							if(a[i][j]!=a[n-1-i][n-1-j])issym=0;
						}
					}
				}
				
			}
		}
		
		cout<<"Test #"<<s+1;
		if(issym==1){
			cout<<": Symmetric."<<endl;
		}
		else{
			cout<<": Non-symmetric."<<endl;
		}
		
		
	}
	
	
	
	/*
	for(int i=0; i<n; i++){
	}
	*/
	
	return 0;
}