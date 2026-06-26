//✅
#include <iostream>
using namespace std;

int main(){
	long long s,d;
	while (cin>>s>>d){
		long long sum=0,ans;
		while(sum<d){
			ans=s;
			sum+=s;
			s++;//忘記要加一
		}
		cout<<ans<<endl;
	}
	return 0;
}
