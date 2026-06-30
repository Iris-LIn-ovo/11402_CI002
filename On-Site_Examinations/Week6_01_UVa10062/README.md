UVa 10062 - Tell me the frequencies!

1. Problem Information

* Platform: UVa
* Problem ID: 10062
* Problem Title: Tell me the frequencies!
* Problem Link: https://onlinejudge.org/external/100/10062.html
* Source Code (Fail): ./src/frequencies_fail.cpp
* Source Code (Correct/Accepted): ./src/frequencies_accepted.cpp

⸻

2. Problem Description

給定多行輸入（直到 EOF），需要統計每個字元出現的次數。

⸻

輸出規則

對每一行：

* 計算所有字元（ASCII）
* 輸出「出現次數 + 字元 ASCII」
* 依照以下規則排序：
    1. 出現次數 由小到大
    2. 若次數相同，ASCII 由大到小
* 每個 test case 輸出後要空一行

⸻

3. Solution Idea

核心概念

* 用 count[256] 統計 ASCII 出現次數
* 再依照「頻率 + ASCII」規則輸出

⸻

正確排序方式

排序規則是：

1. frequency ascending
2. ASCII descending

⸻

常見解法

* 先統計 freq
* 再用 pair (freq, ascii) 丟進 vector
* 最後 sort

⸻

4. Pseudocode

START
WHILE input exists
    Read line
    count[256] = 0
    FOR each character
        count[ascii]++
    FOR freq = 1 to max
        FOR ascii = 255 down to 0
            IF count[ascii] == freq
                print ascii, freq
    print blank line
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <string>
using namespace std;
int main(){
    string line;
    
    while(getline(cin ,line)){
        int count[256]={0};
        
        for(int i=0; i<line.size(); i++){
            int x=line[i];
            count[x]++;
        }
        
        for(int freq=0; freq<1000; freq++){
            for(int ascii=256; ascii>0; ascii--){
                if(count[ascii]==freq && count[ascii]!=0){
                    cout<<ascii<<" "<<count[ascii]<<endl;
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}

⸻

Why it failed:

* ❌ ascii loop從 256 開始 → 越界（應該 255）
* ❌ 頻率排序方式效率差且不完整
* ❌ 沒有正確處理排序規則（應用 vector sort）
* ❌ 可能輸出順序錯誤（不保證 stable rule）
* ❌ freq loop 到 1000 是硬猜

⸻

Correct Code

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string line;
    bool first = true;
    while(getline(cin, line)){
        if(!first) cout << endl;
        first = false;
        int cnt[256] = {0};
        for(char c : line){
            cnt[(unsigned char)c]++;
        }
        vector<pair<int,int>> v;
        for(int i = 0; i < 256; i++){
            if(cnt[i] > 0){
                v.push_back({cnt[i], i});
            }
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        for(auto &p : v){
            cout << p.second << " " << p.first << endl;
        }
    }
    return 0;
}

⸻

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Sorting	brute freq loop	stable sort
ASCII range	0–256 (錯)	0–255
Rule handling	不完整	正確雙排序規則
Output format	容易錯	正確 blank line control

⸻

Reflection

* 這題核心不是 counting，而是 sorting rule
* UVA 常見陷阱：
    * ASCII 範圍錯（255 vs 256）
    * output blank line 控制
    * 自己硬寫 loop sorting → 很容易錯
* 正確觀念：
    👉 「先轉成 (freq, ascii) 再 sort」最安全