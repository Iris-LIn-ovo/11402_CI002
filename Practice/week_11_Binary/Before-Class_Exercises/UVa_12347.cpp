#include <iostream>
#include <vector>
using namespace std;

int num[10005];

void bst(int l,int r){
    if(l>=r)return;

    int root=num[l];
    int mid=l+1;
    while(mid<r && num[mid]<root){
        mid++;
    }

    bst(l+1, mid);
    bst(mid, r);
    cout<<root<<endl;

}

int main(){
    int n=0,x;
    while(cin>>x){
        num[n]=x;
        n++;
    }

    bst(0, n);

    return 0;
}