#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		set<int> s;
		vector<int> v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			s.insert(x);
			v.push_back(x);
		}
		
		int total=0;
		for(int i=0; i<n-1; i++){
			int count=0;
			sort(v.begin(), v.end());
			
			count+=v[1];
			count+=v[0];
			v[0]=9999999;
			v[1]=9999999;
			
			total+=count;
			v.push_back(count);
		}
		cout<<total<<endl;
	}
	
	return 0;
}