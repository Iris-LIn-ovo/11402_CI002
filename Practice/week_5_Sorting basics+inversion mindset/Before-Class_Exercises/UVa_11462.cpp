#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    int n;
    while(cin>>n && n!=0){
        vector<int> age;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            age.push_back(x);
        }
        sort(age.begin(), age.end());
        for(int i=0; i<age.size()-1; i++){
            cout<<age[i]<<" ";
        }
        cout<<age.back()<<endl;
    }

    return 0;
}