#include <iostream>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0){
            return 0;
        }
        bool isconflict=0;
        bool isbooked[1000005]={0};
        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            for(int j=a; j<b; j++){
                if(isbooked[j]==0){
                    isbooked[j]=1;
                }
                else{
                    isconflict=1;
                    break;
                }
            }
        }
        
            for(int i=0; i<m; i++){
                int a,b,c;
                cin>>a>>b>>c;
                int x=0;
                int round=0;
                while(x<=1000000){
                    
                    for(int j=a; j<b; j++){//你的寫法 j = a - 1，會把 [2..5] 標記在索引 1, 2, 3, 4；把 [5..6] 標記在索引 4, 5。
                                            //看出來了嗎？索引 4 重疊了！ 這樣原本合法的「首尾相接」就會被你誤判成 CONFLICT。
                        x=j;
                        x+=round*c;
                        if(x>1000000){//一定要先篩選有沒有大於100萬，不然會Time Limit Exceeded
                            break;
                        }
                        else if(isbooked[x]==0 && x<=1000000){
                            isbooked[x]=1;
                        }
                        else{
                            isconflict=1;
                            break;
                        }
                        
                    }
                    round++;
                }
            }
        
        if(isconflict==1){
            cout<<"CONFLICT"<<endl;
        }
        else{
            cout<<"NO CONFLICT"<<endl;
        }
    }
    return 0;
}