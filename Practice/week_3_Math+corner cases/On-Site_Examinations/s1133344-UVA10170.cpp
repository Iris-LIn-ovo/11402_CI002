#include <iostream>
using namespace std;

int main(){
	for(int l=0 ; l<100000 ; l++){
		int s,d,ans;
		int n=0;
		cin>>s>>d;
		int count=0;
		
		for(int i=s ; i<=d ; i++){
			n+=i;
			if(n>=d){
				ans=i;
				break;
			}	
		}
		cout<<ans<<endl;	
	}
	return 0;
}
