#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int t,n;
	cin>>t;
	
	for(int j=0; j<t; j++){
		cin>>n;
		int max,min,a;
		min=1000;
		max=-1;
		
		for(int i=0; i<n; i++){
			cin>>a;
			
			if(a<min){
				min=a;
			}
			if(a>max){
				max=a;
			}
		}
		
		int ans;
		ans=(max-min)*2;
		
		cout<<ans<<endl;
			
	}
	
	
	return 0;
}
