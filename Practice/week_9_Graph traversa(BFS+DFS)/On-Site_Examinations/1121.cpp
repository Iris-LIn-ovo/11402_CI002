#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
		sort(num.begin(),num.end());
		int sum=0,count;
		for(int i=num.size()-1; i>=0; i--){
			
		}
	}
	
	return 0;
}