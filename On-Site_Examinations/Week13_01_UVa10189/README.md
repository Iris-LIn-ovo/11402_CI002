UVa 10189 - Minesweeper

1. Problem Information

* Platform: UVa
* Problem ID: 10189
* Problem Title: Minesweeper
* Problem Link: https://onlinejudge.org/external/101/10189.html
* Source Code (Fail): ./src/minesweeper_fail.cpp
* Source Code (Correct/Accepted): ./src/minesweeper_accepted.cpp

⸻

2. Problem Description

給定一個 n × m 的掃雷盤面：

* * 表示地雷
* . 表示空格

你需要輸出每個空格周圍 8 個方向的地雷數量。

⸻

規則

對每個 .：

👉 計算周圍（上、下、左、右 + 四個對角）有多少 *

如果是 *：

👉 直接輸出 *

⸻

3. Solution Idea

核心想法

👉 grid traversal + 8-direction checking

⸻

方法

對每個格子：

* 如果是 * → 直接輸出 *
* 如果是 . → 掃描 8 個方向累加

⸻

方向向量

(-1,-1) (-1,0) (-1,1)
(0,-1)  self   (0,1)
(1,-1)  (1,0)  (1,1)

⸻

4. Pseudocode

START
field_num = 1
WHILE read n, m and not (0,0)
    read grid
    print "Field #x"
    FOR each cell (i, j)
        IF '*'
            print '*'
        ELSE
            count = 0
            FOR dr in [-1..1]
                FOR dc in [-1..1]
                    IF valid neighbor AND is '*'
                        count++
            print count
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, m, field_num = 1;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> field(n);
        for (int i = 0; i < n; i++) cin >> field[i];
        if (field_num > 1) cout << endl;
        cout << "Field #" << field_num++ << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    cout << '*';
                } else {
                    int count = 0;
                    for (int dr = -1; dr <= 1; dr++) {
                        for (int dc = -1; dc <= 1; dc++) {
                            int ni = i + dr;
                            int nj = j + dc;
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

⸻

6. Why it failed

這份其實：

👉 是 AC 等級解法（幾乎正確）

但有幾個「潛在問題 / 不穩定點」：

⸻

⚠️ 1. 沒排除自己格子（但剛好沒影響）

if (field[ni][nj] == '*')

* dr=0, dc=0 時也會檢查自己
* 但因為 self 不可能是 ‘*’（只有 ‘.’ 才進 else）
* 所以「剛好沒錯」，但邏輯不嚴謹

⸻

⚠️ 2. 題目格式依賴 print spacing

if (field_num > 1) cout << endl;

* 正確但容易 WA if misplaced

⸻

⚠️ 3. 其實沒有真正錯誤（這題是標準 brute force）

👉 這份 code 本質是 AC 解

⸻

7. Correct Code (Cleaner Version)

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    int fieldNum = 1;
    while(cin >> n >> m && (n || m)){
        vector<string> g(n);
        for(int i = 0; i < n; i++){
            cin >> g[i];
        }
        if(fieldNum > 1) cout << "\n";
        cout << "Field #" << fieldNum++ << ":\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '*'){
                    cout << '*';
                    continue;
                }
                int cnt = 0;
                for(int dr = -1; dr <= 1; dr++){
                    for(int dc = -1; dc <= 1; dc++){
                        if(dr == 0 && dc == 0) continue;
                        int ni = i + dr;
                        int nj = j + dc;
                        if(ni >= 0 && ni < n &&
                           nj >= 0 && nj < m &&
                           g[ni][nj] == '*'){
                            cnt++;
                        }
                    }
                }
                cout << cnt;
            }
            cout << "\n";
        }
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
self-check	implicit	explicit skip
readability	good	cleaner
safety	medium	high
logic clarity	ok	best practice

⸻

Reflection

* 這題核心：
    👉 grid + 8-direction brute force
* 重點不是難度，而是：
    * 邊界處理
    * direction traversal
* UVA 經典技巧：
    * 永遠寫 dr/dc 模板