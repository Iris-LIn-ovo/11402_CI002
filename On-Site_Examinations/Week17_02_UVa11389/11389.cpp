#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,d,r;
	int count=0;
	while(cin>>n>>d>>r){
		if(count!=0){
			cout<<endl;
		}
		count++;
		if(n==0 && d==0 & r==0){
			break;
		}
		vector<int> m;
		vector<int> a;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			m.push_back(x);
		}
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		
		sort(m.begin(), m.end());
		sort(a.begin(), a.end());
		
		int sum;
		int overtime=0;
		for(int i=0; i<n; i++){
			sum=m[i]+a[n-1-i];
			int over=sum-d;
			if(over<0)over=0;
			overtime+=over;
		}
		
		int pay=r*overtime;
		cout<<pay;
	}
	
	return 0;
}