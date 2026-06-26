#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, field_num = 1;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> field(n);
        for (int i = 0; i < n; i++) cin >> field[i];

        if (field_num > 1) cout << endl; // 題目要求各輸出間有空行
        cout << "Field #" << field_num++ << ":" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    cout << '*';
                } else {
                    int count = 0;
                    // 檢查 8 個鄰居
                    for (int dr = -1; dr <= 1; dr++) {
                        for (int dc = -1; dc <= 1; dc++) {
                            int ni = i + dr;
                            int nj = j + dc;
                            // 邊界檢查：確保鄰居在範圍內且不是自己
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == '*') {
                                count++;
                            }
                        }
                    }
                    cout << count;
                }
            }
            cout << endl;
        }
    }
    return 0;
}