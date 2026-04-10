#include <iostream>
#include <string>
using namespace std;

int main(){
	string a;
	int count=1;
	while(cin>>a){
		if(a == "\"" && count%2 == 1){
			cout<<"``";
			count++;
		}
		else if(a == "\"" && count%2 == 0){
			cout<<"''";
			count++;
		}
		else{
			cout<<a<<" ";
		}	
			
	}
	return 0;
}