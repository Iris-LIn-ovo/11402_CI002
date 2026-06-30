UVa 10170 - The Hotel with Infinite Rooms

1. Problem Information

* Platform: UVa
* Problem ID: 10170
* Problem Title: The Hotel with Infinite Rooms
* Problem Link: https://onlinejudge.org/external/101/10170.html
* Source Code (Fail): ./src/hotel_fail.cpp
* Source Code (Correct/Accepted): ./src/hotel_accepted.cpp

⸻

2. Problem Description

有一間無限房間的旅館，入住規則如下：

* 第 1 天入住 S 人
* 第 2 天入住 S+1 人
* 第 3 天入住 S+2 人
* …

目標是找出最小的天數 D，使得：

👉 從第 1 天累積到第 D 天的入住總人數 ≥ N

⸻

3. Solution Idea

核心觀察

* 每天入住人數形成等差數列：
    * S, S+1, S+2, …
* 問題變成：
    * 找最小 D，使前 D 項和 ≥ N

⸻

方法一（模擬）

* 每天累加入住人數
* 直到總和 ≥ N

⸻

方法二（最佳解）

* 使用等差數列公式：
    [
    sum = \frac{D}{2} (2S + D - 1)
    ]
* 用二分搜尋找最小 D

⸻

Edge Cases

* S 很大
* N 很大（需用 long long）
* D 很大時不能暴力

⸻

4. Pseudocode

START
WHILE input exists
    Read S, N
    set l = 0, r = large number
    WHILE l < r
        mid = (l + r) / 2
        compute sum = (2S + mid - 1) * mid / 2
        IF sum >= N
            r = mid
        ELSE
            l = mid + 1
    print l
END

⸻

5. Source Code

Fail Code

// 暴力逐天累加（TLE風險）

Why it failed:

* 每天模擬會變成 O(D)
* D 很大時會超時
* 沒有利用數學公式

⸻

Correct Code

#include <iostream>
using namespace std;
int main(){
    long long s, n;
    while (cin >> s >> n){
        long long l = 0, r = 1000000;
        while (l < r){
            long long mid = (l + r) / 2;
            long long sum = (2 * s + mid - 1) * mid / 2;
            if (sum >= n) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Approach	暴力模擬	數學 + 二分搜尋
Time Complexity	O(D)	O(log D)
Efficiency	可能 TLE	穩定 AC
Idea	一天一天加	等差數列公式

⸻

Reflection

* 這題關鍵不是寫程式，而是看出「等差數列」
* UVA 很常考「不能模擬，要數學優化」
* 二分搜尋適合「答案單調遞增」問題
* 之後遇到累加問題要先想公式