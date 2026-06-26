#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;
	cin.ignore();
	for(int s=0; s<n; s++){
		bool iscorrect=1;
		string x;
		getline(cin, x);
		stack<char> c;
		
		for(int i=0; i<x.size(); i++){
			char ch=x[i];
			if(ch=='(' || ch=='['){
				c.push(ch);
			}
			else if(ch==')'){
				if(c.empty()==0 && c.top()=='('){
					c.pop();
				}
				else{
					iscorrect=0;
				}
			}
			else if(ch==']'){
				if(c.empty()==0 && c.top()=='[' ){
					c.pop();
				}
				else{
					iscorrect=0;
				}
			}
			
		}
		
		if(iscorrect==0){
			cout<<"No"<<endl;
		}
		else if(c.empty()==0){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}	
		
	}
	
	return 0;
}