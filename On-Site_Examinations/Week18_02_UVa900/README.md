UVa 900 - Brick Wall Patterns

1. Problem Information

* Platform: UVa
* Problem ID: 900
* Problem Title: Brick Wall Patterns
* Problem Link: https://onlinejudge.org/external/9/900.html
* Source Code (Fail): ./src/brick_wall_fail.cpp
* Source Code (Correct/Accepted): ./src/brick_wall_accepted.cpp

⸻

2. Problem Description (My Own Words)

輸入一個整數 n，代表牆的長度。

你要計算：

👉 有多少種方式可以用 1×1 與 2×1 的磚塊鋪滿整面牆

⸻

本質

這其實就是：

👉 Fibonacci number 問題

⸻

對應關係

* f(0) = 1
* f(1) = 1
* f(n) = f(n-1) + f(n-2)

⸻

3. Thinking Logic and Solution Strategy

Initial Thoughts

一開始直覺：

* 用 Fibonacci recursion / iteration
* 用 long long 存結果

⸻

Final Strategy

👉 使用 Fibonacci iteration

但要注意：

* 題目其實是 f(n)
* base case 要正確
* 不能亂 loop

⸻

4. Pseudocode

if n == 0 → print 1
if n == 1 → print 1
a = 1
b = 1
for i = 2 to n:
    sum = a + b
    a = b
    b = sum
print b

⸻

5. Fail Code vs Correct Code

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
		
		if(n==0){
			return 0;
		}
		else if(n==1){
			cout<<"1";
		}
		else{
			long long a=0,b=1,sum=0;
			for(int i=0; i<n; i++){
				if(a+b>0){
					sum=a+b;
					a=b;
					b=sum;
				}
			}
			cout<<sum;
		}
		count++;
	}
	
	return 0;
}

⸻

6. Why it failed

❌ 1. Fibonacci base case錯誤

題目定義：

* f(0) = 1
* f(1) = 1

但你的程式：

if(n==0) return 0;

👉 直接錯

⸻

❌ 2. iteration 多做了一步

for(int i=0; i<n; i++)

👉 Fibonacci step off-by-one

⸻

❌ 3. sum 沒有保證正確值

cout << sum;

👉 loop 結束後 sum 不一定是 f(n)

⸻

❌ 4. 沒有 pre-handle n==0/1 output format一致性

⸻

7. Correct Code

#include <iostream>
using namespace std;
int main(){
    long long n;
    bool first = true;
    while(cin >> n){
        if(!first) cout << endl;
        first = false;
        if(n == 0 || n == 1){
            cout << 1 << endl;
            continue;
        }
        long long a = 1, b = 1, sum = 0;
        for(long long i = 2; i <= n; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        cout << b << endl;
    }
    return 0;
}

⸻

8. Difference and Reflection

Item	Fail Code	Correct Code
base case	wrong	correct (1,1)
loop range	off	correct
output	wrong variable	correct b
logic	unstable	clean Fibonacci

⸻

9. Reflection

* 這題核心：
    👉 Fibonacci counting pattern
* 最大錯誤：
    * 把 Fibonacci 初始值搞錯
    * loop index off-by-one
* 正確觀念：
    👉 遇到 “tiling / brick / ways” → 幾乎都是 Fibonacci