//✅
#include <iostream>
using namespace std;

int main(){
int n;
	while(cin>>n){
	    int count=n,empty=n;
	    int a,b;

	    while(empty>=3 && n<=200){
	        a = empty/3;
	        b = empty%3;
	        count += a;
	        empty = b + a;
	    }

	    if(empty == 2)cout<<count+1<<endl;//最多借一個瓶子
		else{cout<<count<<endl;}
	}
    
    return 0;
}
