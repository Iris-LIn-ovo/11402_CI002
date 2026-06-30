UVa 11136 - Hoax or what

1. Problem Information

* Platform: UVa
* Problem ID: 11136
* Problem Title: Hoax or what
* Problem Link: https://onlinejudge.org/external/111/11136.html
* Source Code (Fail): ./src/hoax_fail.cpp
* Source Code (Correct/Accepted): ./src/hoax_accepted.cpp

⸻

2. Problem Description

有一個商店每天會進行交易：

* 每天會有多個票券價格進入系統
* 每天都要從所有票券中：
    * 找出最大值與最小值
    * 並計算兩者差值加入總和
    * 同時刪除最大與最小票券

目標是輸出所有天數的總差值。

⸻

3. Solution Idea

核心想法

這題關鍵是：

👉 維持一個「可快速取 min / max 的資料結構」

因此使用：

* multiset
    * 自動排序
    * 可 O(log n) 插入
    * 可 O(1) 取 min/max

⸻

流程

對每一天：

1. 插入所有票券
2. 取最小值 + 最大值
3. 加入 total
4. 刪除 min + max

⸻

Edge Cases

* 每天只有 1 張票（題目通常保證不會出現破壞情況）
* 重複票價（multiset 允許）
* 空集合保護

⸻

4. Pseudocode

START
WHILE read day and day != 0
    multiset m
    total = 0
    FOR each day
        insert all numbers into m
        min = smallest
        max = largest
        total += max - min
        remove one min
        remove one max
    print total
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <set>
using namespace std;
int main(){
    int day;
    while(cin>>day && day!=0){
        multiset<int> m;
        long long total=0;
        for(int d=0; d<day; d++){
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                int x;
                cin>>x;
                m.insert(x);
            }
            int min=*m.begin();
            int max=*(--m.end());
            total+=(max-min);
            
            m.erase(m.begin());
            if(m.empty()==0){
                m.erase(--m.end());
            }
        }
        cout<<total<<endl;
    }
    
    return 0;
}

⸻

Why it failed:

這份其實邏輯接近正確，但有幾個關鍵風險點：

⸻

❌ 1. m 沒有每天重置概念（邏輯誤解）

* 題目是「每天獨立插入 + 當天操作」
* 但你的 multiset 是跨 day 累積
* 其實這題應該每日處理完就清掉

⸻

❌ 2. erase(max) 寫法有 bug 風險

m.erase(--m.end());

* --m.end() 是 iterator 運算
* multiset erase iterator ok，但容易寫錯或 UB

⸻

❌ 3. 沒確保 min/max 是同一天的操作邏輯清楚

⸻

❌ 4. 潛在邏輯混亂

* multiset 是「全局」但實際應該是「每日操作流程」

⸻

6. Correct Code

#include <iostream>
#include <set>
using namespace std;
int main(){
    int day;
    while(cin >> day && day != 0){
        multiset<int> s;
        long long total = 0;
        for(int d = 0; d < day; d++){
            int n;
            cin >> n;
            for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                s.insert(x);
            }
            auto itMin = s.begin();
            auto itMax = prev(s.end());
            total += (*itMax - *itMin);
            s.erase(itMin);
            s.erase(itMax);
        }
        cout << total << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
iterator usage	unsafe	safe (prev)
structure clarity	moderate	clean
correctness	risky	stable
erase logic	potential UB	correct order-safe

⸻

Reflection

* 這題核心：
    👉 multiset + min/max extraction
* 重點不是資料結構，而是：
    * erase iterator 安全性
    * prev(s.end()) 比 –end() 更安全
* UVA 常見技巧：
    👉 STL 正確用法比邏輯更重要