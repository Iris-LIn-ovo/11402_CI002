UVa 11349 - Symmetric Matrix

1. Problem Information

* Platform: UVa
* Problem ID: 11349
* Problem Title: Symmetric Matrix
* Problem Link: https://onlinejudge.org/external/113/11349.html
* Source Code (Fail): ./src/symmetric_matrix_fail.cpp
* Source Code (Correct/Accepted): ./src/symmetric_matrix_accepted.cpp

⸻

2. Problem Description

給定一個 n × n 的矩陣 M，需要判斷它是否符合「鏡像對稱」。

⸻

判斷條件

矩陣必須同時滿足：

1. 所有元素皆為 非負數
2. 對所有 i, j：

M[i][j] == M[n-1-i][n-1-j]

👉 也就是「以中心點為對稱」的對稱，而不是一般 transpose 對稱。

⸻

注意

* 這題不是 M[i][j] == M[j][i]
* 而是 中心對稱（180度旋轉對稱）

⸻

3. Solution Idea

核心想法

👉 比較「對角線對面的位置」

(i, j) ↔ (n-1-i, n-1-j)

⸻

判斷流程

* 如果任何一對不相等 → Non-symmetric
* 如果任何值 < 0 → Non-symmetric
* 否則 → Symmetric

⸻

4. Pseudocode

FOR each test case
    read n
    read matrix
    ok = true
    FOR i in [0..n-1]
        FOR j in [0..n-1]
            IF a[i][j] < 0 OR a[i][j] != a[n-1-i][n-1-j]
                ok = false
    output result
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        vector<vector<long long>> a(n, vector<long long>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] != a[j][i]) ok = false;   // ❌ wrong condition
                if(a[i][j] < 0) ok = false;
            }
        }
        cout << "Test #" << t << ": "
             << (ok ? "Symmetric." : "Non-symmetric.") << endl;
    }
    return 0;
}

⸻

6. Why it failed

這份 code 的問題是：

⸻

❌ 1. 對稱條件寫錯

錯誤寫法：

a[i][j] != a[j][i]

👉 這是「轉置對稱」，不是本題要求。

⸻

❌ 正確應該是：

a[i][j] != a[n-1-i][n-1-j]

⸻

❌ 2. 概念混淆

類型	定義
transpose symmetry	a[i][j] == a[j][i]
center symmetry	a[i][j] == a[n-1-i][n-1-j]

⸻

7. Correct Code

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

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
symmetry type	transpose	center symmetry
condition	a[i][j]==a[j][i]	a[i][j]==a[n-1-i][n-1-j]
correctness	wrong problem model	correct
concept	mixed	precise

⸻

Reflection

* 這題核心不是 coding，而是：
    👉 分清楚 symmetry 類型
* UVa 常見陷阱：
    * 看起來像對稱，但其實是「旋轉對稱」
* 解題關鍵：
    👉 先確認「對稱定義」再寫 code