#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> a;
	string s;
	int max=0;
	
	for(int i=0 ; i<100 ; i++){
		getline(cin, s);
		a.push_back(s);
		if(s.length() > max){
			max = s.length() ;
		}
		
		for(int l=0 ; l<max ; l++){
			for(int j=a.size()-1 ; j>=0 ; j--){
				if(l < a[j].length()){
					cout<<a[j][i];
				}
				else{
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
	
	return 0;
}