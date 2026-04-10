#include <iostream>
#include <string>
using namespace std;

int main(){
	string line;
	
	while(getline(cin ,line)){
		int count[256]={0};
		
		for(int i=0; i<line.size(); i++){
			int x=line[i];
			count[x]++;
		}
		
		for(int freq=0; freq<1000; freq++){
			for(int ascii=256; ascii>0; ascii--){
				if(count[ascii]==freq && count[ascii]!=0){
					cout<<ascii<<" "<<count[ascii]<<endl;
				}
			}
		}
		cout<<endl;
	}
	
	return 0;
}