#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int s=0; s<n; s++){
        int l;
        cin>>l;
        vector<int> train;
        for(int i=0; i<l; i++){
            int x;
            cin>>x;
            train.push_back(x);
        }
        
        //bobble sort
        int count=0;
        for(int i=0; i<l-1; i++){
            for(int j=0; j<l-i-1; j++){
                if(train[j]>train[j+1]){
                    swap(train[j], train[j+1]);
                    count++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }

    return 0;
}