#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	vector<int> a;
	while(cin>>n){
		int x;
		x=n;
		a.push_back(x);
		sort(a.begin(), a.end());
		
//		for(int i=0; i<a.size(); i++)cout<<a[i]<<" ";
		
		int ans;
		if(a.size()%2==0){
			int y;
			y=a[a.size()/2-1] + a[a.size()/2];
			ans=y/2;
		}
		else if(a.size()%2==1 && a.size()!=1){
			ans=a[a.size()/2];
		}
		else if(a.size()==1)ans=n;
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}