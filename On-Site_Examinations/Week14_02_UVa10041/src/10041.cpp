#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int s=0; s<N; s++){
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0; i<n;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int mid=v.size()/2;
		
		int total=0;
		if(n%2==1){
			for(int i=0; i<v.size()-1; i++){
				if(i!=mid){
					int count=v[i]-v[mid];
					if(count<0){
						total-=count;
					}
					else{
						total+=count;
					}
				}
			}
		}
		else{
			int count1=0, count2=0;
			for(int i=0; i<v.size()-1; i++){
				if(i!=mid){
					int count=v[i]-v[mid];
					if(count<0){
						count1-=count;
					}
					else{
						count1+=count;
					}
				}
			}
			for(int i=0; i<v.size(); i++){
				if(i!=mid-1){
					int count=v[i]-v[mid-1];
					if(count<0){
						count2-=count;
					}
					else{
						count2+=count;
					}
				}
			}
			if(count1<count2){
				total+=count1;
			}
			else{
				total+=count2;
			}
		}
		cout<<total<<endl;
	}
	return 0;
}