#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        queue<int> q;
        // 把 1 到 n 放入佇列
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        cout << "Discarded cards:";
        bool first = true; // 用來控制逗號輸出

        // 只要還有 2 張以上就繼續
        while (q.size() >= 2) {
            if (!first) cout << ",";
            cout << " " << q.front();
            q.pop(); // 丟掉第一張
            
            // 把丟完後的下一張移到最後面
            int next_top = q.front();
            q.pop();
            q.push(next_top);
            
            first = false;
        }

        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}