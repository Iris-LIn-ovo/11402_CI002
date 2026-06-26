#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    // 讀取火車數量 n
    while (cin >> n && n != 0) {
        while (true) {
            int first;
            cin >> first;
            if (first == 0) {
                cout << endl; // 題目規定：每個區塊後補一行空行
                break;
            }

            // 讀取目標排列
            vector<int> target(n);
            target[0] = first;
            for (int i = 1; i < n; i++) cin >> target[i];

            stack<int> s;
            int A = 1; // 從 A 端開來的車廂編號
            bool possible = true;

            // 依序滿足目標排列中的每一個車廂
            for (int i = 0; i < n; i++) {
                int goal = target[i];

                // 如果車站頂端不是我們要的車廂，就一直從 A 把車廂推進來
                while (A <= n && (s.empty() || s.top() != goal)) {
                    s.push(A);
                    A++;
                }

                // 推完後，檢查車站頂端是否等於目標車廂
                if (!s.empty() && s.top() == goal) {
                    s.pop();
                } else {
                    // 如果 A 端車廂已經用完，且車站頂端依然不是 goal，則此序列無解
                    possible = false;
                    break;
                }
            }

            if (possible) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}