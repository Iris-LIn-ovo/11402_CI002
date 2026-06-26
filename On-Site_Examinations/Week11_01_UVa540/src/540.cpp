#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n,case_num=1;
	int team_id[1000005];
	while(cin>>n && n!=0){
		cout<<"Scenario #"<<case_num<<endl;
		case_num++;
		
		for(int i=0; i<n; i++){
			int num;
			cin>>num;
			for(int j=0; j<num; j++){
				int x;
				cin>>x;
				team_id[x]=i;
			}
		}
		
		string step;
		queue<int> line;
		vector<queue<int> > teamline(n);
		
		while(cin>>step && step!="STOP"){
			if(step=="DEQUEUE"){
				int now=line.front();
				cout<<teamline[now].front()<<endl;
				teamline[now].pop();
				if(teamline[now].empty()){
					line.pop();
				}
			}
			else if(step=="ENQUEUE"){
				int x;
				cin>>x;
				int id=team_id[x];
				if(teamline[id].empty()){
					line.push(id);
				}
				teamline[id].push(x);
			}
		}
		cout<<endl;
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