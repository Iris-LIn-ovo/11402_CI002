#include <iostream>
#include <set>
using namespace std;

int main(){
    int day;
    while(cin>>day && day!=0){
        multiset<int> m;
        long long total=0;

        for(int d=0; d<day; d++){
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                int x;
                cin>>x;
                m.insert(x);
            }

            int min=*m.begin();
            int max=*(--m.end());
            total+=(max-min);
            
            m.erase(m.begin());
            if(m.empty()==0){
                m.erase(--m.end());
            }
        }
        cout<<total<<endl;
    }
    
    return 0;
}