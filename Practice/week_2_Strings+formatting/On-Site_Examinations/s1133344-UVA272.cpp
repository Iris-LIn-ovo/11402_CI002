#include <iostream>
#include <string>
using namespace std;

int main(){

	string a;
	bool count=0;
	while(getline(cin, a)){
		for(int i=0; i<a.size(); i++){
			if(a[i] == '"' && count == 0){//用單引號包雙引號，代表文字雙引號
				cout<<"``";
				count=1;
			}
			else if(a[i] == '"' && count == 1){
				cout<<"''";
				count=0;
			}
			else{
				cout<<a[i];
			}
		}
		cout<<endl;//一定要加！！！不然過不了
		
	}
	return 0;
}