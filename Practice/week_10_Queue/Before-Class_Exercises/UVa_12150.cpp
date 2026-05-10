#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin>>n && n!=0){

        int carnumber[n],race[n];
        for(int i=1; i<=n; i++){
            race[i-1]=i;
        }

        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            carnumber[i]=a;
            race[i]+=b;
        }

        bool iserror=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(race[i]==race[j])iserror=1;
            }
        }

        if(iserror==1) cout<<"-1";
        else{
            for(int i=1; i<=n; i++){
                for(int j=0; j<n; j++){
                    if(race[j]==i){
                        cout<<carnumber[j]<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }

    return 0;
}