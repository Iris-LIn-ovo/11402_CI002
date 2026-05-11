#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		//1.2.3...
		queue<int> q;
		for(int i=0; i<n; i++){
			q.push(i+1);
		}
		
		
		bool last=1;
		
		if(n==1){
			cout<<"Discarded cards:";
			cout<<endl;
		}
		else if(n==2){
			cout<<"Discarded cards: ";
			cout<<q.front()<<endl;
			q.pop();
		}
		else{
			cout<<"Discarded cards: ";
			for(int i=0; i<n-1; i++){
				if(last==1){
					cout<<q.front()<<", ";
					q.pop();
					q.push(q.front());
					q.pop();
						
					if(q.size()==2)last=0;
				}
				else{
					cout<<q.front()<<endl;
					q.pop();
				}
			}
		}
		
		cout<<"Remaining card: "<<q.front()<<endl;
	}
	
	return 0;
}
/*
queue<int> q;
q.push(x);
q.pop();
q.front();
q.back();
q.erase();
*/