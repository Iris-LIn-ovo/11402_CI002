#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

void solve( ){
    map<string, int> tree_map;
    string tree_name;
    int counttree=0;
    while(getline(cin, tree_name) && tree_name!=""){
        tree_map[tree_name]++;
        counttree++;
    }
    for(auto [name, times]:tree_map){
        double percent=((double)times/counttree)*100.0;
        cout<<name<<" ";
        cout<<fixed<<setprecision(4)<<percent<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    string tree;
    getline(cin, tree);
    getline(cin, tree);
    if(t==0)return 0;

    for(int s=0; s<t; s++){
        if(s>0)cout<<endl;// 修正 ：除了最後一組外，每組測資後要印一個空白行
        solve( );
    }
    

    return 0;
}