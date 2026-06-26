#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int main(){
	string a,b;
	vector<vector<int> > v(100000); 
	int count=0
	while(cin>>a>>b){
		v[count].push_back(a);
		v[count].push_back(b);
		count++;
		for(int i=0; i<count; i++){
			if(a====v[i][1]){
				cout<<v[i][0]<<endl;
				break;
			}
		}
	}
	
	while(1){
		string ans;
		cin>>ans;
		for(int i=0; i<count; i++){
			if(ans==v[i][1]){
				cout<<v[i][0]<<endl;
			}
			else{
				cout<<"eh"<<endl;
			}
		}
	}
	
	
	return 0;
}