#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;

    int min=0, max=n-1;
    int ans;
    bool isfinded=0;
    while(min<=max){
        int mid=(min+max)/2;
        if(nums[mid]>target){
            max=mid-1;
        }
        else if(nums[mid]<target){
            min=mid+1;
        }
        else if(nums[mid]==target){
            ans=mid;
            isfinded=1;
            break;
        }
    }
    if(isfinded==0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }

    return 0;
}