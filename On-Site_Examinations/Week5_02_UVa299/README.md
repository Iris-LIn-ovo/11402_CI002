
UVa 299 - Train Swapping

1. Problem Information

* Platform: UVa
* Problem ID: 299
* Problem Title: Train Swapping
* Problem Link: https://onlinejudge.org/external/2/299.html
* Source Code (Fail): ./src/train_swapping_fail.cpp
* Source Code (Correct/Accepted): ./src/train_swapping_accepted.cpp

⸻

2. Problem Description

給定多組測試資料，每組是一個 1 ~ L 的排列。

目標是將這個排列排序成：

1 2 3 ... L

但只能使用「交換相鄰元素」的方式。

⸻

任務

計算：

👉 最少需要多少次「相鄰交換」才能排序完成

⸻

3. Solution Idea

核心概念

這題其實就是：

👉 計算 inversion count（逆序數）

⸻

為什麼？

每一次「相鄰交換」都等同於消除一個逆序對。

因此：

答案 = array 中 inversion 的數量

⸻

方法

* 逐一掃描每個元素
* 比較後面所有元素
* 若前面 > 後面 → count++

⸻

Edge Cases

* L = 0 / 1 → 0 swaps
* 已排序 → 0
* 完全逆序 → 最大 swaps

⸻

4. Pseudocode

START
Read T
FOR each test case
    Read L
    Read array arr
    swaps = 0
    FOR i = 0 to L-1
        FOR j = i+1 to L-1
            IF arr[i] > arr[j]
                swaps++
    print "Optimal train swapping takes swaps swaps."
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 沒有正確計算 inversion / 或排序錯誤

Why it failed:

* 沒有正確統計逆序對
* 或只做排序卻沒計算交換次數
* 或忽略相鄰交換限制

⸻

Correct Code

#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int L;
        cin >> L;
        int arr[60];
        for(int i = 0; i < L; i++){
            cin >> arr[i];
        }
        int swaps = 0;
        for(int i = 0; i < L; i++){
            for(int j = i + 1; j < L; j++){
                if(arr[i] > arr[j]){
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Concept	可能直接排序	計算 inversion
Logic	不完整	正確統計 swap
Understanding	混淆問題	明確知道是逆序數
Output	可能錯格式	完整 sentence output

⸻

Reflection

* 這題本質是：
    * 逆序數 (Inversion Count)
* 每個 inversion = 一次 swap
* 重要觀念：
    * 不要真的去 swap
    * 直接計數即可
* 之後遇到排序 swap 題要想到：
    👉 inversion count