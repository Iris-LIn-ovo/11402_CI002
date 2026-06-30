UVa 11063 - B2-Sequence

1. Problem Information

* Platform: UVa
* Problem ID: 11063
* Problem Title: B2-Sequence
* Problem Link: https://onlinejudge.org/external/110/11063.html
* Source Code (Fail): ./src/b2_sequence_fail.cpp
* Source Code (Correct/Accepted): ./src/b2_sequence_accepted.cpp

⸻

2. Problem Description

給定一個數列，判斷它是否為 B2-Sequence。

⸻

B2-Sequence 定義

一個數列必須滿足：

1. 所有數字必須為 正整數
2. 數列必須是 嚴格遞增
3. 所有「兩兩相加」的結果必須 互不相同

⸻

任務

輸出：

* 是 B2-Sequence → It is a B2-Sequence.
* 否則 → It is not a B2-Sequence.

⸻

3. Solution Idea

核心想法

分成兩個檢查：

① 基本條件

* 全部 > 0
* 嚴格遞增

② pair sum 檢查

* 生成所有 i ≤ j 的 pair sum
* 檢查是否有重複

⸻

流程

1. 讀入數列
2. 檢查是否正數 + 遞增
3. 建立所有 pair sum
4. sort
5. 檢查是否有重複
6. 輸出結果

⸻

Edge Cases

* n = 1（一定成立）
* 有 0 或負數
* 重複 pair sum
* 非遞增數列

⸻

4. Pseudocode

START
case = 1
WHILE input exists
    read n
    read array
    isB2 = true
    check:
        all positive
        strictly increasing
    generate all pair sums (i <= j)
    sort sums
    IF any duplicate exists
        isB2 = false
    print result
    print blank line
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int count=1;
	
	while(cin>>n){
		bool isb2=1;
		vector<int> num;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
			if (x<=0)isb2=0;
			else if(i>0 && x<num[i-1])isb2=0;
		}
		
		vector<int> add;	
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				int x=num[i]+num[j];
				add.push_back(x);
			}
		}
		sort(add.begin(), add.end());
		
		for(int i=0; i<add.size()-1; i++){
			if(add[i]==add[i+1]){
				isb2=0;
			}
		}
		
		if(isb2==0){
			cout<<"Case #"<<count<<": It is not a B2-Sequence."<<endl;
		}
		else{
			cout<<"Case #"<<count<<": It is a B2-Sequence."<<endl;
		}
		count++;
		cout<<endl;
	}
	
	return 0;
}

⸻

Why it failed / issues

* ⚠️ 邏輯基本正確，但有幾個潛在問題：
    * ❌ isb2 在發現錯誤後仍繼續算 pair sums（浪費）
    * ❌ 沒有 early break（效能不佳）
    * ❌ pair sum 檢查可以用 set 更簡潔
    * ⚠️ vector add 可能重複存大量資料（O(n²) 空間）
    * ⚠️ 沒有 short-circuit optimization

👉 但整體其實是 AC 等級寫法

⸻

6. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int n;
    int kase = 1;
    while(cin >> n){
        vector<int> v(n);
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] <= 0) ok = false;
            if(i > 0 && v[i] <= v[i-1]) ok = false;
        }
        set<int> s;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = v[i] + v[j];
                if(s.count(sum)) ok = false;
                s.insert(sum);
            }
        }
        cout << "Case #" << kase++ << ": ";
        if(ok)
            cout << "It is a B2-Sequence." << endl;
        else
            cout << "It is not a B2-Sequence." << endl;
        cout << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Duplicate check	sort vector	set detection
Efficiency	O(n² log n)	O(n²) + early check
Structure	分離處理	即時判斷
Readability	中	高

⸻

Reflection

* 這題核心是：
    👉 pair sum uniqueness + strict increasing
* 常見優化思路：
    * 用 set 取代 sort + duplicate check
* UVA 類型特點：
    * brute force 可以過，但要寫乾淨
* 關鍵觀念：
    👉「pair sum 問題 = 用 set 最直覺」