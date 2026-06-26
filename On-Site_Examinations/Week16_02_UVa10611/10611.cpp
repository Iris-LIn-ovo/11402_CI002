#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int girln,boyn;
	cin>>girln;
	int g[girln];
	for(int i=0; i<girln; i++){
		cin>>g[i];
	}
	cin>>boyn;
	for(int i=0; i<boyn; i++){
		int b;
		cin>>b;
		if(b<g[0]){
			cout<<"X "<<g[0]<<endl;
		}
		else if(b>g[girln-1]){
			cout<<g[girln-1]<<" X"<<endl;
		}
		else if(b==g[0]){
			bool findbig=0;
			for(int j=0; j<girln; j++){
				if(g[j]>b){
					cout<<"X "<<g[j]<<endl;
					findbig=1;
					break;
				}
			}
			if(findbig==0)cout<<"X X"<<endl;
		}
		else if(b==g[girln-1]){
			bool findsmall=0;
			for(int j=0; j<girln; j++){
				if(g[girln-1-j]<b){
					cout<<g[j]<<" X"<<endl;
					findsmall=1;
					break;
				}
			}
			if(findsmall==0)cout<<"X X"<<endl;
		}
		else{
			int min=-1,max=g[girln-1];
			for(int j=0; j<girln; j++){
				if(b>g[j] && g[j]>min){
					min=g[j];
				}
				if(b<g[j] && g[j]<max){
					max=g[j];
				}
			}	
			cout<<min<<" "<<max<<endl;
		}
		
		
	}
	/*
	for(int i=0;i<n; i++){
	}
	*/
	
	return 0;
}