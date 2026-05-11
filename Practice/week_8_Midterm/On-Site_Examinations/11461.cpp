#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int a,b;
	while(cin>>a>>b && a!=0 && b!=0){
		int count=0;
		for(int i=a; i<=b; i++){
			int x;
			x=sqrt(i);
			if(i==x*x)count++;
		}
		cout<<count<<endl;
	}
	
	return 0;
}