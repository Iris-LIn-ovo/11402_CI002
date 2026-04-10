#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int m,n;
	int count=1;
	while(cin>>m>>n && m!=0 && n!=0){
		
		cout<<"CASE# "<<count<<":"<<endl;
		
		vector<int> num;
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		sort(num.begin(), num.end());
		
		
		while(n--){
			int x;
			cin>>x;
			
			int ans=-1;
			int min=0,max=num.size()-1;
			bool isfound=0;
			
			while(min<=max){
				int mid=(min+max)/2;
				
				if(num[mid]<x){
					min=mid+1;
				}
				else if(num[mid]>x){
					max=mid-1;
				}
				else{
					ans=mid;
					max=mid-1;
				}
			}
			
			if(ans==-1){
				cout<<x<<" not found"<<endl;
			}
			else{
				cout<<x<<" found at "<<ans+1<<endl;
			}
		}
		
		
		count++;
	}
	
	return 0;
}