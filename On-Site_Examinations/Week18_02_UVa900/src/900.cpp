#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long n;
	int count=0;
	while(cin>>n){
		if(count!=0){
			cout<<endl;
		}
		
		if(n==0){
			return 0;
		}
		else if(n==1){
			cout<<"1";
		}
		else{
			long long a=0,b=1,sum=0;
			for(int i=0; i<n; i++){
				if(a+b>0){
					sum=a+b;
					a=b;
					b=sum;
				}
			}
			cout<<sum;
		}
		count++;
	}
	
	return 0;
}