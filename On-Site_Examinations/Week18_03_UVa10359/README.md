UVa 10359 - Tiling

1. Problem Information

* Platform: UVa
* Problem ID: 10359
* Problem Title: Tiling
* Problem Link: https://onlinejudge.org/external/103/10359.html
* Source Code (Fail): ./src/tiling_fail.cpp
* Source Code (Correct/Accepted): ./src/tiling_accepted.cpp

⸻

2. Problem Description (My Own Words)

給你一個整數 n，代表一個 2×n 的長方形。

你要計算：

👉 有幾種方式可以用 2×1 的骨牌（domino）鋪滿整個區域

⸻

3. Key Insight

這題本質是：

Fibonacci-like DP（但其實是更大數的 Fibonacci）

⸻

recurrence

[
f(n) = f(n-1) + f(n-2)
]

⸻

base cases

* f(0) = 1
* f(1) = 1
* f(2) = 2

⸻

4. Thinking Logic and Solution Strategy

Initial Thoughts

你這份 code 的想法其實是：

* 想用 Fibonacci
* 再額外加 combinatorics（2^k * something）

👉 這是典型「想太複雜」

⸻

Final Strategy

👉 正解其實就是：

* Fibonacci
* 但 n 很大 → 必須 Big Integer

⸻

5. Pseudocode

dp[0] = 1
dp[1] = 1
for i = 2 to n:
    dp[i] = dp[i-1] + dp[i-2]
print dp[n]

⸻

6. Fail Code vs Correct Code

Fail Code

#include <iostream>
#include <vector>
using namespace std;
int main(){
	long long n;
	int count=0;
	while(cin>>n){
		if(count!=0){
			cout<<endl;
		}
		
		long long ans=0;
		if(n==0 || n==1){
			cout<<"1";
		}
		else if(n==2){
			cout<<"3";
		}
		else{
			long long f[260];
			long long a=0,b=1,sum=0;
			for(int i=0; i<251; i++){
				if(a+b>0){
					sum=a+b;
					f[n]=sum;
					a=b;
					b=sum;
				}
			}
			
			
			if(n%2==0){
				long long brige=n/2;
				for(int i=0; i<brige; i++){
					long long x=1;
					for(int j=0; j<brige-i; j++){
						x*=2;
					}
					int y;
					y=x*(2*i+1);
					ans+=y;
				}
				cout<<ans;
			}
			else{
				long long brige=n/2;
				for(int i=0; i<brige; i++){
					long long x=1;
					for(int j=0; j<brige-i; j++){
						x*=2;
					}
					int y;
					y=x*(2*i+2);
					ans+=y;
				}
				cout<<ans;
			}
		}
		
		count++;
	}
	
	return 0;
}

⸻

7. Why it failed

❌ 1. 完全錯誤模型

你混了：

* Fibonacci
* combinatorics
* exponential counting

👉 但這題其實只有 Fibonacci DP

⸻

❌ 2. f[n] 沒有意義

f[n] = sum;

👉 每次覆蓋，根本沒 DP

⸻

❌ 3. brute exponentiation（錯方向）

x *= 2;

👉 這不是 tiling 的結構

⸻

❌ 4. even/odd 分支是錯誤假設

tile 不會因奇偶改公式

⸻

❌ 5. output 沒 newline / format 不完整

⸻

8. Correct Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// big integer addition
string add(string a, string b){
    string res = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    vector<string> dp(5005);
    dp[0] = "1";
    dp[1] = "1";
    for(int i = 2; i <= 5000; i++){
        dp[i] = add(dp[i-1], dp[i-2]);
    }
    long long n;
    bool first = true;
    while(cin >> n){
        if(!first) cout << endl;
        first = false;
        cout << dp[n] << endl;
    }
    return 0;
}

⸻

9. Difference and Reflection

Item	Fail Code	Correct Code
model	wrong math	Fibonacci DP
logic	overcomplicated	simple
correctness	incorrect	correct
scaling	broken	big integer

⸻

10. Reflection

* 這題核心：
    👉 Tiling = Fibonacci
* 最大問題：
    * 自己推公式（錯）
* 正確策略：
    👉 “看到 tiling → 直接 DP / Fibonacci”