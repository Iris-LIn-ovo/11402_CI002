#include <iostream>
using namespace std;

int main(){
int n;
	while(cin>>n){
	    int count=n,empty=n+2;
	    int a,b;
//	    if(n%3 == 2){
//	    	empty--;
//		}
	    while(empty>=3 && n<=200){
	    	
	        a = empty/3;
	        b = empty%3;
	        count += a;
	        empty = b + a;
	    }
	    
	    if(n%3 == 1)cout<<count+1<<endl;
	    if(n%3 == 0)cout<<count-1<<endl;
	    if(n%3 == 2)cout<<count<<endl;
	}
    
    return 0;
}
