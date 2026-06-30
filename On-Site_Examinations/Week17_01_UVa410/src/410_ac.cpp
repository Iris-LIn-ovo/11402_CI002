#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int c, s;
    int tc = 1;

    while (cin >> c >> s) {

        vector<int> v(s);
        double sum = 0;

        for (int i = 0; i < s; i++) {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end());

        double avg = sum / c;

        vector<vector<int>> chamber(c);

        int l = 0, r = s - 1;

        for (int i = 0; i < c; i++) {

            if (l > r) break;

            if (l == r) {
                chamber[i].push_back(v[l]);
                l++;
            } 
            else {
                chamber[i].push_back(v[l]);
                chamber[i].push_back(v[r]);
                l++;
                r--;
            }
        }

        double imbalance = 0;

        cout << "Set #" << tc++ << endl;

        for (int i = 0; i < c; i++) {

            double sumc = 0;

            cout << " " << i << ":";

            for (int x : chamber[i]) {
                cout << " " << x;
                sumc += x;
            }

            cout << endl;

            imbalance += abs(sumc - avg);
        }

        cout << "IMBALANCE = " << fixed << setprecision(5)
             << imbalance << "\n\n";
    }

    return 0;
}