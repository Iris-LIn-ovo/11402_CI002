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
		
		long long ans=0;
		if(n==0 || n==1){
			cout<<"1";
		}
		else if(n==2){
			cout<<"3";
		}
		else{
			long long f[260];
			long long a=0,b=1,sum=0;
			for(int i=0; i<251; i++){
				if(a+b>0){
					sum=a+b;
					f[n]=sum;
					a=b;
					b=sum;
				}
			}
			
			
			if(n%2==0){
				long long brige=n/2;
				for(int i=0; i<brige; i++){
					long long x=1;
					for(int j=0; j<brige-i; j++){
						x*=2;
					}
					int y;
					y=x*(2*i+1);
					ans+=y;
				}
				cout<<ans;
			}
			else{
				long long brige=n/2;
				for(int i=0; i<brige; i++){
					long long x=1;
					for(int j=0; j<brige-i; j++){
						x*=2;
					}
					int y;
					y=x*(2*i+2);
					ans+=y;
				}
				cout<<ans;
			}
		}
		
		count++;
	}
	
	return 0;
}