#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int count=0;
    while(cin>>n){
        int secret[n],guess[n],scount[10]={0};
        for(int i=0; i<n; i++){
            cin>>secret[i];
        }
        for(int i=0; i<n; i++){
            scount[secret[i]]++;
        }
        if(n==0) break;
        
        count++;
        cout<<"Game "<<count<<":"<<endl;
        while(true){
            
            int a=0,b=0;
            for(int i=0; i<n; i++){
                cin>>guess[i];
            }

            bool allzero = true;
            for(int i=0;i<n;i++){
                if(guess[i] != 0)allzero = false;
            }
            if(allzero) break;

            int gcount[10]={0};
            for(int i=0; i<n; i++){
                if(secret[i]==guess[i]){
                    a++;
                    continue;
                }
                gcount[guess[i]]++;
            }
            for(int i=1;i<9; i++){//i<n 會錯,因為數字範圍是 1~9
                b += min(scount[i],gcount[i]);
            }
            cout<<"("<<a<<","<<b<<")"<<endl;
            
        }
    }

    return 0;
}