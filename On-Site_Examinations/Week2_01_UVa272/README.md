UVa 272 - TEX Quotes

Use this template to review your coding performance for each problem. Write clearly and use your own words.

1. Problem Information

* Platform: UVa
* Problem ID: 272
* Problem Title: TEX Quotes
* Problem Link: https://onlinejudge.org/external/2/272.html
* Source Code (Fail): N/A
* Source Code (Correct/Accepted): src/uva272.cpp

2. Problem Statement in My Own Words

這題的目標是將輸入文字中的雙引號 " 轉換成 TEX 格式的引號。

* 輸入是什麼？
    多行文字（不確定行數，直到 EOF）
* 輸出是什麼？
    將每個雙引號 " 依序替換成：
    * 開頭引號 → ``（兩個反引號）
    * 結尾引號 → ‘’（兩個單引號）
* 規則與限制：
    * 每遇到一個 " 就要交替轉換
    * 第一個 " 是開引號，第二個是關引號，以此類推
    * 要完整保留原本文字（除了引號替換）
    * 每行輸出後要換行
* 核心任務：
    判斷目前的 " 是第幾個（奇數或偶數），並替換成對應符號

3. Thinking Logic and Solution Strategy

Initial Thoughts

* 一開始想到用計數方式來記錄目前是第幾個引號
* 發現只需要知道「現在是開還是關」，不用真的計數全部

Final Strategy

* 使用一個 bool 變數來記錄目前狀態：
    * false → 下一個 " 是開引號
    * true → 下一個 " 是關引號
* 掃描整行字串：
    * 如果遇到 "：
        * 根據狀態輸出 `` 或 ‘’
        * 並切換狀態
    * 否則直接輸出原字元
* 使用 getline 讀取整行，確保空白不被忽略
* 每處理完一行記得輸出換行
* 為什麼可行？
    因為題目保證引號是成對出現，只要交替處理即可
* Edge Cases：
    * 空行
    * 一行有多個引號
    * 多行輸入
    * 忘記換行（會 WA）

4. Pseudocode

START
1. 設定 count = false
2. while (讀取一整行輸入)
3.     for 每個字元
4.         if 字元是 "
5.             if count == false
6.                 輸出 ``
7.                 count = true
8.             else
9.                 輸出 ''
10.                count = false
11.        else
12.            輸出該字元
13.    輸出換行
END

5. Fail Code vs Correct Code

Fail Code

// 常見錯誤版本（示意）

Why it failed:

* 沒有使用 getline，導致空白或整行處理錯誤
* 忘記在每行結尾加 endl
* 沒有正確切換引號狀態

Correct Code

// ✅
#include <iostream>
#include <string>
using namespace std;
int main(){
    
    string a;
    bool count=0;
    while(getline(cin, a)){
        for(int i=0; i<a.size(); i++){
            if(a[i] == '"' && count == 0){//用單引號包雙引號，代表文字雙引號
                cout<<"``";
                count=1;
            }
            else if(a[i] == '"' && count == 1){
                cout<<"''";
                count=0;
            }
            else{
                cout<<a[i];
            }
        }
        cout<<endl;//一定要加！！！不然過不了
        
    }
    return 0;
}

Why it works:

* 使用 getline 正確讀取整行
* 用 bool 控制開/關引號切換
* 每遇到 " 即進行替換
* 保留其他所有字元
* 每行結尾加 endl 符合輸出格式

6. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Logic	沒有正確切換狀態	使用 bool 控制開關
Edge Cases	忽略多行或空白	使用 getline 完整處理
Output Handling	少了換行	每行都有 endl
Other	字元判斷不完整	條件判斷清楚

Reflection

* 我犯的錯誤：
    * 忘記輸出換行導致 WA
    * 沒有注意輸入是多行
* 我學到：
    * UVa 很常考「輸入輸出格式」
    * 小細節（像換行）會直接影響 AC
* 下次改進：
    * 一開始就確認輸入型態（是否用 getline）
    * 測試多行與邊界情況
    * 寫完先檢查輸出格式