//✅
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> line;
	string s;

	while(getline(cin, s)){
		line.push_back(s);
	}

	int maxlen=0;
	for(int i=0; i<line.size(); i++){
		if(line[i].size() > maxlen){
			maxlen=line[i].size();
		}
	}
	
	for(int i=0; i<maxlen; i++){
		for(int j=line.size()-1; j>=0; j--){
			if(i>line[j].size()-1){//如果那一個array不夠長，補空格，我原本沒有補上
				cout<<" ";
			}
			else{
				cout<<line[j][i];
			}
		}
		cout<<endl;
	}
	
	return 0;
}