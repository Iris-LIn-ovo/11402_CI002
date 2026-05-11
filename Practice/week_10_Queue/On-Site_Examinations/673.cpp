
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int s=0; s<n; s++){
		bool iscorrect=1;
		vector<string> a;
		string x;
		cin>>x;
		a.push_back(x);
		vector<string> c;
		
		for(int i=0; i<a.size(); i++){
			if(a[i]=="(" || a[i]=="["){
				c.push_back(a[i]);
			}
			else if(a[i]==")"){
				if(c[c.size()]=="("){
					c.pop_back();
				}
				else{
					iscorrect=0;
				}
			}
			else if(a[i]=="]"){
				if(c[c.size()]=="["){
					c.pop_back();
				}
				else{
					iscorrect=0;
				}
			}
			
		}
		
		if(iscorrect==0){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}	
		
	}
	
	return 0;
}