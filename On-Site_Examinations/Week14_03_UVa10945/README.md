UVa 10945 - Mother Bear

1. Problem Information

* Platform: UVa
* Problem ID: 10945
* Problem Title: Mother Bear
* Problem Link: https://onlinejudge.org/external/109/10945.html
* Source Code (Fail): ./src/mother_bear_fail.cpp
* Source Code (Correct/Accepted): ./src/mother_bear_accepted.cpp

⸻

2. Problem Description

輸入一句話，判斷它是否是「回文（Palindrome）」。

⸻

規則

* 忽略大小寫
* 忽略所有非英文字母
* 只比較 a–z 字元

⸻

輸出

* 是回文 → "You won't be eaten!"
* 不是回文 → "Uh oh.."

⸻

3. Solution Idea

核心想法

👉 filter + two pointers / reverse compare

⸻

步驟

1. 只保留英文字母
2. 全部轉小寫
3. 檢查是否對稱

⸻

4. Pseudocode

WHILE read line
    IF line == "DONE"
        break
    filtered = ""
    FOR char in line
        IF isalpha → tolower → add
    IF filtered == reverse(filtered)
        print YES message
    ELSE
        print NO message

⸻

5. Source Code

Fail Code

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=0){
		set<int> s;
		vector<int> v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			s.insert(x);
			v.push_back(x);
		}
		
		int total=0;
		for(int i=0; i<n-1; i++){
			int count=0;
			sort(v.begin(), v.end());
			
			count+=v[1];
			count+=v[0];
			v[0]=9999999;
			v[1]=9999999;
			
			total+=count;
			v.push_back(count);
		}
		cout<<total<<endl;
	}
	
	return 0;
}

⸻

6. Why it failed

這份 code 完全不是本題（10945）問題模型，屬於「題目錯貼型錯誤」。

⸻

❌ 1. 完全錯題型

這份 code 做的是：

👉 類似 Huffman / merge cost / greedy sum

但 10945 是：

👉 Palindrome 判斷

⸻

❌ 2. 使用了完全無關的資料結構

set<int>, vector<int>

但題目應該：

* string
* filter characters

⸻

❌ 3. 邏輯完全 mismatch

Code 做的	題目需要
sorting + merging	palindrome check
min sum merge	string compare

⸻

👉 結論：

✔ 這不是 bug
❌ 是「題目解錯」

⸻

7. Correct Code

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s == "DONE") break;
        string t = "";
        for(char c : s){
            if(isalpha(c)){
                t += tolower(c);
            }
        }
        string r = t;
        reverse(r.begin(), r.end());
        if(t == r){
            cout << "You won't be eaten!" << "\n";
        }else{
            cout << "Uh oh.." << "\n";
        }
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
problem type	wrong problem	palindrome
data structure	set/vector	string
logic	greedy merge	two pointer / reverse
correctness	WA	AC

⸻

Reflection

* 這題最大問題不是 bug，而是：
    👉 題目模型整個搞錯
* UVA 常見致命錯誤：
    * 看關鍵字猜題型
* 正確習慣：
    👉 先確認 input/output pattern 再寫 code