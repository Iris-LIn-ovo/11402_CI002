#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		vector<int> num;
		int a=n;
		while(a>2){
			int x;
			x=a%2;
			num.push_back(x);
			int y=a/2;
			a=y;
		}
		if(a==2){
			num.push_back(0);
			num.push_back(1);
		}
		else if(a==1){
			num.push_back(1);
		}
		
		
		int count=0;
		for(int i=num.size(); i>0; i--){
			if(num[i-1]==1)count++;
		}
		
		cout<<"The parity of ";
		for(int i=num.size(); i>0; i--){
			cout<<num[i-1];
		}
		cout<<" is "<<count<<" (mod 2)."<<endl;
	}
	
	
	return 0;
}