#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,s;
	while(cin>>n>>s){
		vector<int> num;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
		}

		int sum=num[0];
		int ans=1e9,a=0,b=0;
		while(a<n){
			if(sum<s && sum>=0){
				a++;
				if(a<n){
					sum+=num[a];
				}
			}
			else{
				if(ans>a-b+1){
					ans=a-b+1;
				}
				sum-=num[b];
				b++;
			}
		}
		if(ans==1e9){
			cout<<0<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}