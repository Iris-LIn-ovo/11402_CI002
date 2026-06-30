UVa 10252 - Common Permutation

1. Problem Information

* Platform: UVa
* Problem ID: 10252
* Problem Title: Common Permutation
* Problem Link: https://onlinejudge.org/external/102/10252.html
* Source Code (Fail): ./src/common_permutation_fail.cpp
* Source Code (Correct/Accepted): ./src/common_permutation_accepted.cpp

⸻

2. Problem Description

給定兩個字串 a 與 b，找出它們的「共同字母集合」。

⸻

輸出要求

* 找出兩字串中 都出現的字元
* 每個字元只輸出「最小匹配次數」
* 最後結果要：
    * 依字母順序排序（a → z）

⸻

重點

👉 不是找 substring
👉 不是找 set
👉 是找 multiset intersection（含重複次數）

⸻

3. Solution Idea

核心想法

👉 用 frequency count（字元計數）

⸻

方法

1. 統計 a 每個字元出現次數
2. 統計 b 每個字元出現次數
3. 對每個字母：

min(cntA[c], cntB[c])

⸻

4. Pseudocode

read a, b
countA[26] = 0
countB[26] = 0
for c in a:
    countA[c]++
for c in b:
    countB[c]++
for c in 'a'..'z':
    repeat min(countA[c], countB[c]) times:
        print c

⸻

5. Source Code

Fail Code

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	string a, b;
	while(getline(cin, a) && getline(cin, b)){
		set<string> s;
		s.insert(a);
		s.insert(b);
		vector<char> ans;
		for(int i=0; i<a.size(); i++){
			for(int j=0; j<b.size(); j++){
				if(b[j]==a[i]){
					ans.push_back(b[j]);
					break;
				}
			}
		}
		sort(ans.begin(), ans.end());
		
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}

⸻

6. Why it failed

這份 code 主要問題是：

⸻

❌ 1. 沒有處理「重複次數限制」

if(b[j] == a[i]) ans.push_back(...)

👉 問題：

* 同一個 b[j] 可以被重複匹配多次
* 沒有「使用過就不能再用」

👉 會導致：

* 重複錯誤配對
* 輸出過多字元

⸻

❌ 2. 使用 set 完全無作用

set<string> s;

* 沒有被使用
* 多餘 code

⸻

❌ 3. O(n²) brute force + no bookkeeping

* 沒有 frequency control
* 本質錯在「multiset 沒建模」

⸻

7. Correct Code

#include <iostream>
#include <string>
using namespace std;
int main(){
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        int cntA[26] = {0};
        int cntB[26] = {0};
        for(char c : a){
            cntA[c - 'a']++;
        }
        for(char c : b){
            cntB[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            int times = min(cntA[i], cntB[i]);
            for(int j = 0; j < times; j++){
                cout << char('a' + i);
            }
        }
        cout << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
logic	brute matching	frequency intersection
duplicates	wrong	controlled
correctness	WA risk	AC
complexity	O(n²)	O(n)

⸻

Reflection

* 這題核心：
    👉 multiset intersection = frequency min
* 最大錯誤：
    * 用「找字」代替「計數」
* 正確思維：
    👉 只要看到「重複字元 + 交集」→ 一律 frequency