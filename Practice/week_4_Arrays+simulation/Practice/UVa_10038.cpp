#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[3000];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool diff[3000] = {0}; 
        
        for (int i = 0; i < n - 1; i++) {
            int d = abs(a[i+1] - a[i]);
            if (d >= 1 && d <= n-1)
                diff[d] = true;
        }

        bool isjolly = true;
        for (int i = 1; i <= n-1; i++) {
            if (!diff[i]) {
                isjolly = false;
                break;
            }
        }

        if (isjolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}