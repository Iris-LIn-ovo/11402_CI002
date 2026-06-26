#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,b,h,w;
	while(cin>>n>>b>>h>>w){
		int maxb=b;
		bool havehotel=0;
		
		for(int i=0; i<h; i++){
			int hp;
			cin>>hp;
			int price=hp*n;
			int bednum;
			
			for(int j=0; j<w; j++){
				cin>>bednum;
				if(bednum>=n && price<=maxb){
					maxb=price;
					havehotel=1;
				}
			}
		}
		
		if(havehotel==0){
			cout<<"stay home"<<endl;
		}
		else{
			cout<<maxb<<endl;
		}
	}
	return 0;
}
/*
me
n people num
b budget
h hotle num
w week you can choose

H 
p price
w week has bed num

*/