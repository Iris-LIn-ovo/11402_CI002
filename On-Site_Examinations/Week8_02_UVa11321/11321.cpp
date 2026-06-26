#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
	int n,m
	while(cin>>n>>m && n!=0 && m!=0){
		cout<<n<<" "<<m<<endl;
		vector<int> num;
		vector<vector<int>> sortnum;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		
		for(int i=0; i<n; i++){
			int x;
			x=num[i]%m;
			sortnum[x].push_back(num[i]);
		}
		
		for(int i=0; i<m; i++){
			sort(sortnum.begin(), sortnum.end(), cmp)
		}
	}
	
	return 0;
}