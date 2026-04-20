#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    for(int t=0; t<T; t++){
        int n;
        cin>>n;
        vector<int> stap;
        int pos=0;

        for(int i=0; i<n; i++){
            string s;
            cin>>s;                                                                
            if(s=="LEFT"){
                stap.push_back(-1);
                pos--;
            }
            else if(s=="RIGHT"){
                stap.push_back(1);
                pos++;
            }
            else{
                string as;
                int x;
                cin>>as>>x;
                stap.push_back(stap[x-1]);
            }
        }

    }

    return 0;
}