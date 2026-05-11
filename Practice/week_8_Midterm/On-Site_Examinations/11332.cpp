#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	
	while(cin>>n && n!=0){
		int a,ans=0,sum=100;
		a=n;
		
		while(sum>=10){
			ans=0;
			while(a>0){
				int x;
				x=a%10;
				ans+=x;
				a/=10;
			}
			sum=ans;
			a=ans;
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}