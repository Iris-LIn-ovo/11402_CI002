#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	string blank;
	getline(cin, blank);
	for(int n=0; n<N; n++){
		int m;
		cin>>m;
		bool num[m]={0};
		int pair[100000][2];
		int pcount=0;
		for(int i=0; i<100001; i++){
			int a,b;
			cin>>a>>b;
			if(a==0 && b==0)break;
			if(a>=0 && a<=m && b>=m){
				int x;
				if(b>m){
					x=m-a;
				}
				else{
					x=b-a;
				}
				
				pair[pcount][0]=a;
				pair[pcount][1]=b;
				pcount++;
				
				if(x==0){
					num[m]==1;
					
				}
				else{
					for(int l=0; l<x; l++){
						num[l+a]==1;
					}
				}
			}
		}
		
		bool ok=1;
		for(int i=0; i<=m; i++){
			if(num[i]==0)ok=0;
		}
		if(ok==0){
			cout<<endl;
		}
		else{
			for(int i=0; i<pcount; i++){
				cout<<pair[i][0]<<" "<<pair[i][1]<<endl;
			}
		}
		cout<<endl;
	}
	
	return 0;
}