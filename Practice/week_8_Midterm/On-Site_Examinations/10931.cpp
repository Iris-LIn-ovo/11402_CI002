#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		int a;
		a=n;
		vector<int> num;
		int count=0;
		
		while(a>=2){
			int x;
			x=a%2;
			num.push_back(x);
			
			a=a/2;
		}
		num.push_back(1);
		
		for(int i=0; i<num.size(); i++){
			if(num[i]==1)count++;
		}
		
		cout<<"The parity of ";
		
		for(int i=num.size()-1; i>=0; i--){
			cout<<num[i];
		}
		cout<<" is "<<count<<" (mod 2)."<<endl;
	}
	return 0;
} 