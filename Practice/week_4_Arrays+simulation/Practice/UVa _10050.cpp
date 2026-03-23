#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int s=0; s<n; s++){
        int count,day;
        cin>>day>>count;
        int p[count];
        for(int i=0; i<count; i++){
            cin>>p[i];
        }
        bool isworkout[3651]={0};//這是 VLA（變長陣列），標準 C++ 不保證支援;建議直接bool isworkout[3651]
        for(int i=0; i<day; i++){
            for(int j=0; j<count; j++){
                if((i+1)%p[j]==0){//題目天數是從1開始
                    isworkout[i]=1;
                }
            }
            if((i+1)%7==6 || (i+1)%7==0)isworkout[i]=0;
        }
        int ans=0;
        for(int i=0; i<day; i++){
            if(isworkout[i]==1)ans++; 
        }
        cout<<ans<<endl;
    }

    return 0;
}