#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    while(cin>>m>>n && m!=0 && n!=0){
        vector<vector<int> > matrix(m, vector<int>(n));
        vector<vector<int> > up(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int x;
                cin>>x;
                matrix[i][j]=x;

                if(x==1){
                    up[i][j]=0;
                }
                else if(i==0 && x==0){
                    up[i][j]=1;
                }
                else{
                    up[i][j]=up[i-1][j]+1;
                }
            }
        }

        int max=-1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int min=up[i][j];
                if(up[i][j]<=up[i][j+1]){
                    int count=2*up[i][j];
                    for(int l=j+1; l<n-1; l++){
                        if(up[i][j]<=up[i][l]){
                            count+=up[i][j];
                        }
                        else{
                            break;
                        }
                    }
                    if(count>max){
                        max=count;
                    }
                }
                else{
                    int count=up[i][j];
                    if(count>max){
                        max=count;
                    }
                    continue;
                }

            }
        }

        cout<<max<<endl;
    }

    return 0;
}