UVa 10008 - What’s Cryptanalysis?

1. Problem Information

* Platform: UVa
* Problem ID: 10008
* Problem Title: What’s Cryptanalysis?
* Problem Link: https://onlinejudge.org/external/100/10008.html
* Source Code (Fail): ./src/cryptanalysis_fail.cpp
* Source Code (Correct/Accepted): ./src/cryptanalysis_accepted.cpp

⸻

2. Problem Description

給定多行文字，需要做字母統計分析：

* 統計每個英文字母（A-Z / a-z）
* 忽略大小寫（視為同一個字母）
* 忽略非英文字母（數字、符號、空白都不算）
* 輸出每個字母出現次數

⸻

輸出規則

* 依照「出現次數由大到小排序」
* 若次數相同：
    * 按字母順序（A → Z）
* 不輸出沒出現過的字母
* 輸出格式：

LETTER COUNT

⸻

3. Solution Idea

核心想法

* 用大小為 26 的陣列統計 A-Z 出現次數
* 將所有字元轉成大寫或小寫統一處理
* 過濾非英文字母
* 最後排序輸出

⸻

流程

1. 讀取 n 行輸入
2. 對每個字元：
    * 如果是字母 → count++
3. 建立 (letter, count) pair list
4. 依規則排序：
    * count 遞減
    * letter 遞增
5. 輸出結果

⸻

Edge Cases

* 全部都是符號
* 大小寫混合
* 某些字母完全沒出現
* 多行輸入包含空白

⸻

4. Pseudocode

START
Read n
Create array cnt[26] = 0
FOR each line
    FOR each character
        IF letter
            convert to uppercase
            cnt[ch - 'A']++
Create list (char, count)
Sort by:
    1. count descending
    2. char ascending
FOR each item in list
    IF count > 0
        print char and count
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 沒有忽略非字母 / 或排序錯誤

Why it failed:

* 沒有統一大小寫
* 沒有過濾非字母
* 沒有正確排序規則
* 或輸出包含 0 次字母

⸻

Correct Code

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    int cnt[26] = {0};
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        for(char c : s){
            if(isalpha(c)){
                c = toupper(c);
                cnt[c - 'A']++;
            }
        }
    }
    vector<pair<char,int>> v;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            v.push_back({char('A' + i), cnt[i]});
        }
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    for(auto &p : v){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Counting	不完整或錯誤	正確統計 A-Z
Case Handling	未處理	全部轉大寫
Filtering	包含非字母	只算 isalpha
Sorting	無或錯誤	正確雙條件排序

⸻

Reflection

* 這題核心是「字元統計 + 排序」
* UVA 常見技巧：
    * 用固定大小陣列（26）
    * 不要用 map 反而更慢
* 容易錯的地方：
    * 忘記 ignore 換行
    * 沒處理大小寫
    * 排序條件寫錯