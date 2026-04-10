#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		int a=0,b=0;
		int ans=0;
		cin>>a>>b;
		
		for(int j=a ; j<=b ; j++){
			if(j%2 == 1){
				ans = ans+j;
			}
		}
		cout << "Case " << i+1 << ": " << ans << endl;
		
	}
	
	return 0;
}