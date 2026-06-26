#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string a;
	int count=1;
	
	while(cin>>a && a!="#"){
		cout<<"Case "<<count<<": ";
		if(a=="HELLO"){
			cout<<"ENGLISH";
		}
		else if(a=="HOLA"){
			cout<<"SPANISH";
		}
		else if(a=="HALLO"){
			cout<<"GERMAN";
		}	
		else if(a=="CIAO"){
			cout<<"ITALIAN";
		}
		else if(a=="BONJOUR"){
			cout<<"FRENCH";
		}
		else if(a=="ZDRAVSTVUJTE"){
			cout<<"RUSSIAN";
		}
		else{	
			cout<<"UNKNOWN";	
		}
		cout<<endl;
		count++;
	}
	
	return 0;
}