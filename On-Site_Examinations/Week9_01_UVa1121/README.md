UVa 1121 - Subsequence

1. Problem Information

* Platform: UVa
* Problem ID: 1121
* Problem Title: Subsequence
* Problem Link: https://onlinejudge.org/external/11/1121.html
* Source Code (Fail): ./src/subsequence_fail.cpp
* Source Code (Correct/Accepted): ./src/subsequence_accepted.cpp

⸻

2. Problem Description

給定一個長度為 n 的正整數陣列，以及一個目標值 s。

需要找出：

👉 最短的連續子陣列長度，使其總和 ≥ s

如果不存在，輸出 0。

⸻

3. Solution Idea

核心想法

這題是典型的：

👉 Sliding Window（雙指標）

⸻

觀念

* 用兩個指標 a（右）與 b（左）
* 維持一個區間 sum
* 右邊擴張，左邊收縮

⸻

流程

1. sum 擴張右端
2. 當 sum ≥ s：
    * 更新答案
    * 左端縮小
3. 重複直到結束

⸻

Edge Cases

* 沒有任何區間符合
* 單一元素就滿足
* 全部加起來仍不足

⸻

4. Pseudocode

START
WHILE read n, s
    read array
    left = 0
    sum = 0
    ans = INF
    FOR right = 0 to n-1
        sum += arr[right]
        WHILE sum >= s
            update ans
            sum -= arr[left]
            left++
    IF ans == INF
        print 0
    ELSE
        print ans
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,s;
	while(cin>>n>>s){
		vector<int> num;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		int sum=num[0];
		int ans=1e9,a=0,b=0;
		while(a<n){
			if(sum<s && sum>=0){
				a++;
				if(a<n){
					sum+=num[a];
				}
			}
			else{
				if(ans>a-b+1){
					ans=a-b+1;
				}
				sum-=num[b];
				b++;
			}
		}
		if(ans==1e9){
			cout<<0<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}

⸻

Why it failed:

* ⚠️ 邏輯接近正確，但有幾個問題：

❌ 1. 初始 sum = num[0]

* 容易讓邏輯變複雜
* sliding window 應該從 0 開始

❌ 2. 條件寫法不穩定

if(sum < s && sum >= 0)

* sum >= 0 多餘（題目都是正數）

❌ 3. window 更新方式不夠 clean

* a/b 控制混亂
* 可讀性差

❌ 4. 架構偏「手動模擬」

* 沒有標準 sliding window 寫法

⸻

6. Correct Code

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, s;
    while(cin >> n >> s){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int sum = 0;
        int left = 0;
        int ans = 1e9;
        for(int right = 0; right < n; right++){
            sum += v[right];
            while(sum >= s){
                ans = min(ans, right - left + 1);
                sum -= v[left];
                left++;
            }
        }
        if(ans == 1e9)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Structure	manual two-pointer	clean sliding window
Initialization	sum = num[0]	sum = 0
Readability	medium	high
Robustness	fragile	stable

⸻

Reflection

* 這題核心：
    👉 two pointers / sliding window
* 關鍵觀念：
    * 不要「模擬移動」
    * 要用「統一模板」
* UVA sliding window 標準套路：

right 擴張 + left 收縮