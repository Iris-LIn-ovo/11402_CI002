#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int count=1;
	
	while(cin>>n){
		vector<int> num;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		
		vector<int> add;	
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				int x=num[i]+num[j];
				add.push_back(x);
			}
		}
		sort(add.begin(), add.end());
		
		bool isb2=1;
		for(int i=0; i<add.size()-1; i++){
			if(add[i]==add[i+1]){
				isb2=0;
			}
		}
		
		if(n<2 || n>100){
			cout<<"Case #"<<count<<": It is not a B2-Sequence."<<endl;
		}
		else if(n>=2 && n<=100 && isb2==0){
			cout<<"Case #"<<count<<": It is not a B2-Sequence."<<endl;
		}
		else{
			cout<<"Case #"<<count<<": Is a B2-Sequence."<<endl;
		}
		count++;
	}
	
	return 0;
}