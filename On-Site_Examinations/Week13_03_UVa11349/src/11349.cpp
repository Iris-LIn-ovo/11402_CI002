#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;
        vector<vector<long long>> a(n, vector<long long>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            for(int j = 0; j < n && ok; j++){
                if(a[i][j] < 0 ||
                   a[i][j] != a[n-1-i][n-1-j]){
                    ok = false;
                }
            }
        }
        cout << "Test #" << tc << ": "
             << (ok ? "Symmetric." : "Non-symmetric.") << "\n";
    }
    return 0;
}