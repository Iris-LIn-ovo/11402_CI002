#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string a, b;
	while(getline(cin, a) && getline(cin, b)){
		set<string> s;
		s.insert(a);
		s.insert(b);
		vector<char> ans;
		for(int i=0; i<a.size(); i++){
			for(int j=0; j<b.size(); j++){
				if(b[j]==a[i]){
					ans.push_back(b[j]);
					break;
				}
			}
		}
		sort(ans.begin(), ans.end());
		
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}

