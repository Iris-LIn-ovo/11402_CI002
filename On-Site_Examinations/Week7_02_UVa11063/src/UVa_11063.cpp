#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int count=1;
	
	while(cin>>n){
		bool isb2=1;
		vector<int> num;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
			if (x<=0)isb2=0;//小於等於0為非，原本只寫小於
			else if(i>0 && x<num[i-1])isb2=0;//非嚴格遞增也為非
		}
		
		vector<int> add;	
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				int x=num[i]+num[j];
				add.push_back(x);
			}
		}
		sort(add.begin(), add.end());
		
		
		for(int i=0; i<add.size()-1; i++){
			if(add[i]==add[i+1]){
				isb2=0;
			}
		}
		//if(n<2 || n>100)題目會保證範圍，不用自己判斷
		if(isb2==0){
			cout<<"Case #"<<count<<": It is not a B2-Sequence."<<endl;
		}
		else{
			cout<<"Case #"<<count<<": It is a B2-Sequence."<<endl;
		}
		count++;
		cout<<endl;//一定要換行
	}
	
	return 0;
}