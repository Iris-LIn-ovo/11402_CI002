#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0)break;
		vector<int> dragon;
		vector<int> knight;
		
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			dragon.push_back(x);
		}
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			knight.push_back(x);
		}
		
		sort(dragon.begin(), dragon.end());
		sort(knight.begin(), knight.end());
		int sum=0;
		bool allkill=1;
		//2 7
		//1 2 5 8
		for(int i=0; i<dragon.size(); i++){
			bool iskill=0;
			for(int j=0; j<knight.size(); j++){
				if(dragon[i]<=knight[j]){
					sum+=knight[j];
					knight[j]=-1;
					iskill=1;
					break;
				}
			}
		
			if(iskill==0){
				allkill=0;
			}
		}
		
		if(allkill==0){
			cout<<"Loowater is doomed!"<<endl;
		}
		else{
			cout<<sum<<endl;
		}
	}
	return 0;
}