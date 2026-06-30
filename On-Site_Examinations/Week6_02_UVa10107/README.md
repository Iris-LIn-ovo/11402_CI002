UVa 10107 - What is the Median?

1. Problem Information

* Platform: UVa
* Problem ID: 10107
* Problem Title: What is the Median?
* Problem Link: https://onlinejudge.org/external/101/10107.html
* Source Code (Fail): ./src/median_fail.cpp
* Source Code (Correct/Accepted): ./src/median_accepted.cpp

⸻

2. Problem Description

給定一串逐步輸入的整數序列，每讀入一個數字，就要輸出目前所有數字的 median（中位數）。

⸻

Median 定義

* 若數量為奇數：
    * 取中間那個數
* 若數量為偶數：
    * 取中間兩個數的平均值

⸻

3. Solution Idea

核心想法

* 每次讀入一個數字就加入 vector
* 對整個 vector 進行排序
* 根據目前大小計算 median

⸻

流程

1. 不斷讀入 n
2. push 到 vector
3. sort vector
4. 計算 median：
    * odd → 中間
    * even → 中間兩個平均
5. 輸出結果

⸻

Edge Cases

* 第一個數
* 偶數個數時要取平均
* vector 持續增長

⸻

4. Pseudocode

START
vector a
WHILE input exists
    read x
    push x into a
    sort a
    IF size == 1
        print a[0]
    ELSE IF size is odd
        print middle element
    ELSE
        print average of two middle elements
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	vector<int> a;
	while(cin>>n){
		int x;
		x=n;
		a.push_back(x);
		sort(a.begin(), a.end());
		
		int ans;
		if(a.size()%2==0){
			int y;
			y=a[a.size()/2-1] + a[a.size()/2];
			ans=y/2;
		}
		else if(a.size()%2==1 && a.size()!=1){
			ans=a[a.size()/2];
		}
		else if(a.size()==1)ans=n;
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}

⸻

Why it failed:

* ❌ median 用 int ans → 偶數平均可能失去小數精度
* ❌ 沒處理負數 / 偶數平均應該是精確 median（可能要 .5）
* ❌ 每次 sort → O(n² log n)（但這題勉強可過）
* ❌ 邏輯冗長（size==1 不必要）
* ❌ 沒考慮輸出格式統一性（可簡化）

⸻

6. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    int x;
    while(cin >> x){
        a.push_back(x);
        sort(a.begin(), a.end());
        int n = a.size();
        if(n % 2 == 1){
            cout << a[n / 2] << endl;
        }
        else{
            long long mid = a[n/2 - 1] + a[n/2];
            cout << mid / 2 << endl;
        }
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Median type	int（可能錯）	long long safer
Structure	冗長 if-else	簡化判斷
Robustness	邊界多餘處理	乾淨邏輯
Safety	overflow risk	safer math

⸻

Reflection

* 這題核心是：
    👉「動態中位數」
* 雖然可以 sort 解，但效率較差
* 常見觀念：
    * median = 排序後中間值
* 改進方向：
    * 可用 two heaps（進階 O(log n)）
* UVA 題重點：
    * 正確性 > 效率（但仍要合理）