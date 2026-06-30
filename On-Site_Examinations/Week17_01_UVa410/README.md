UVa 410 - Station Balance

1. Problem Information

* Platform: UVa
* Problem ID: 410
* Problem Title: Station Balance
* Problem Link: https://onlinejudge.org/external/4/410.html
* Source Code (Fail): ./src/station_balance_fail.cpp
* Source Code (Correct/Accepted): ./src/station_balance_accepted.cpp

⸻

2. Problem Description (My Own Words)

你有：

* c 個 chamber（儀器槽）
* s 個 specimen（樣本重量）

每個 sample 有一個重量，你要把它們分配到 chamber 裡。

⸻

規則

* 每個 chamber 最多放 2 個 sample
* 可以空著
* 目標是讓 imbalance 最小

⸻

3. Imbalance 定義

平均重量

[
average = \frac{\sum weights}{c}
]

⸻

每個 chamber 的 imbalance

* chamber 有 sample：總和 − average
* chamber 空：0 − average

⸻

total imbalance

👉 所有 chamber 的 imbalance 絕對值加總

⸻

4. Thinking Logic and Solution Strategy

Initial Thoughts

一開始想：

* 直接平均分配
* 或 brute force

但會發現：

👉 分配方式太多，不能暴力

⸻

Final Strategy

使用 greedy：

👉 排序 + 雙指標配對

⸻

核心想法

* 最小 + 最大配一組
* 中間往內收
* 讓重量分布平均

⸻

為什麼可行

因為：

* extreme pairing 可以降低 variance
* 避免集中在某一 chamber

⸻

5. Pseudocode

read c, s
read all weights
sort weights
l = 0, r = s - 1
for i in [0 .. c-1]:
    if l <= r:
        if l == r:
            assign v[l]
        else:
            assign v[l], v[r]
        move pointers
compute average = sum / c
for each chamber:
    compute sum
    add abs(sum - average)

⸻

6. Fail Code vs Correct Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int c,s;
	while(cin>>c>>s){
		vector(int) v;
		int sum=0;
		for(int i=0; i<s; i++){
			int x;
			cin>>x;
			sum+=x;
			v.push_back(x);
		}
		int aver=sum/s;
		sort(v.begin(), v.end());
		
		if(c%2==1){
			v[n-1]
		}
		else{
			
		}
	}
}

⸻

Why it failed

* ❌ vector 宣告錯誤
* ❌ average 用錯（應該 /c，不是 /s）
* ❌ 沒有 chamber 分配邏輯
* ❌ greedy pairing 未實作完成
* ❌ 程式不完整

⸻

Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int c, s;
    int tc = 1;
    while (cin >> c >> s) {
        vector<int> v(s);
        double sum = 0;
        for (int i = 0; i < s; i++) {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        double avg = sum / c;
        vector<vector<int>> chamber(c);
        int l = 0, r = s - 1;
        for (int i = 0; i < c; i++) {
            if (l > r) break;
            if (l == r) {
                chamber[i].push_back(v[l]);
                l++;
            } 
            else {
                chamber[i].push_back(v[l]);
                chamber[i].push_back(v[r]);
                l++;
                r--;
            }
        }
        double imbalance = 0;
        cout << "Set #" << tc++ << endl;
        for (int i = 0; i < c; i++) {
            double sumc = 0;
            cout << " " << i << ":";
            for (int x : chamber[i]) {
                cout << " " << x;
                sumc += x;
            }
            cout << endl;
            imbalance += abs(sumc - avg);
        }
        cout << "IMBALANCE = " << fixed << setprecision(5)
             << imbalance << "\n\n";
    }
    return 0;
}

⸻

7. Difference and Reflection

Item	Fail Code	Correct Code
Idea	incomplete	greedy pairing
Structure	broken	clean chambers
Formula	wrong avg	correct avg
Output	none	full format

⸻

8. Reflection

* 這題核心：
    👉 sorting + two pointer pairing
* 關鍵技巧：
    * 最大 + 最小配對
* 常見錯誤：
    * 想太複雜（其實很簡單 greedy）

⸻

9. Key Takeaway

👉 看到：

* “balance”
* “minimize imbalance”

就要想到：

sorting + greedy pairing