UVa 495 - Fibonacci Freeze

1. Problem Information

* Platform: UVa
* Problem ID: 495
* Problem Title: Fibonacci Freeze
* Problem Link: https://onlinejudge.org/external/4/495.html
* Source Code (Fail): ./src/fibonacci_freeze_fail.cpp
* Source Code (Correct/Accepted): ./src/fibonacci_freeze_accepted.cpp

⸻

2. Problem Description (My Own Words)

輸入一個整數 n，你要輸出：

👉 第 n 個 Fibonacci number

⸻

定義

* F(0) = 0
* F(1) = 1
* F(n) = F(n-1) + F(n-2)

⸻

注意

n 可能很大，所以不能用一般 int / long long（會 overflow）

⸻

3. Solution Idea

核心觀念

👉 Big Integer Fibonacci（字串或 array 模擬）

⸻

為什麼需要 Big Integer？

Fibonacci 成長非常快：

* F(50) 已經超過 long long
* 題目 n 可達 5000

⸻

4. Pseudocode

dp[0] = 0
dp[1] = 1
for i = 2 to max_n:
    dp[i] = dp[i-1] + dp[i-2] (big integer)
for each input n:
    print dp[n]

⸻

5. Source Code

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
		cout<<"The Fibonacci number for "<<n<<" is ";
		if(n==0){
			cout<<"0";
		}
		else if(n==1){
			cout<<"1";
		}
		else{
			long long a=0,b=1,sum=0;
			for(int i=0; i<n-1; i++){
				if(a+b>0){
					sum=a+b;
					a=b;
					b=sum;
				}
				else
				
			}
			cout<<sum;
		}
		count++;
	}
	
	return 0;
}

⸻

6. Why it failed

❌ 1. Overflow（致命問題）

long long a=0,b=1;

👉 Fibonacci 很快超過 long long

⸻

❌ 2. loop 邏輯錯

for(int i=0; i<n-1; i++)

👉 沒有正確處理 base case / update flow

⸻

❌ 3. code 未完成

else

👉 程式直接斷掉

⸻

❌ 4. 沒有 memoization / DP

每次重算 → inefficient

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// big integer add
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
    vector<string> fib(5005);
    fib[0] = "0";
    fib[1] = "1";
    for(int i = 2; i <= 5000; i++){
        fib[i] = add(fib[i-1], fib[i-2]);
    }
    int n;
    bool first = true;
    while(cin >> n){
        if(!first) cout << endl;
        first = false;
        cout << "The Fibonacci number for " << n << " is " << fib[n] << endl;
    }
    return 0;
}

⸻

8. Difference and Reflection

Item	Fail Code	Correct Code
data type	long long	string big integer
correctness	overflow	correct
DP	missing	precompute
output	incomplete	correct format

⸻

9. Reflection

* 這題核心：
    👉 Big Integer + DP Fibonacci
* 最大錯誤：
    * 用 long long 嘗試算 Fibonacci
* 正確觀念：
    👉 看到 “Fibonacci + large n” = 一定要 big integer DP