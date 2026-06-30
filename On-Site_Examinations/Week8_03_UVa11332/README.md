UVa 11332 - Summing Digits

1. Problem Information

* Platform: UVa
* Problem ID: 11332
* Problem Title: Summing Digits
* Problem Link: https://onlinejudge.org/external/113/11332.html
* Source Code (Fail): ./src/summing_digits_fail.cpp
* Source Code (Correct/Accepted): ./src/summing_digits_accepted.cpp

⸻

2. Problem Description

給定一個整數 n，反覆執行以下操作：

👉 將數字的每一位相加

直到結果變成 一位數為止

⸻

例子

9875 → 9+8+7+5 = 29 → 2+9 = 11 → 1+1 = 2

輸出：2

⸻

3. Solution Idea

核心想法

* 不斷拆解數字
* 加總每一位 digit
* 重複直到結果 < 10

⸻

流程

1. 讀入 n
2. while n >= 10：
    * 拆 digit 加總
    * 更新 n
3. 輸出結果

⸻

Edge Cases

* 已經是一位數
* 很大的數字
* 多次 digit reduction

⸻

4. Pseudocode

START
WHILE read n and n != 0
    WHILE n >= 10
        sum = 0
        WHILE n > 0
            sum += n % 10
            n /= 10
        n = sum
    print n
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	
	while(cin>>n && n!=0){
		int a,ans=0,sum=100;
		a=n;
		
		while(sum>=10){
			ans=0;
			while(a>0){
				int x;
				x=a%10;
				ans+=x;
				a/=10;
			}
			sum=ans;
			a=ans;
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}

⸻

Why it failed:

* ❌ sum = 100 初始化多餘且不合理
* ❌ sum / ans / a 角色混亂（邏輯不清）
* ❌ 沒有直接用 n 控制主流程
* ❌ 變數更新不乾淨（容易 bug）
* ❌ 結構冗長但本質簡單

👉 這題不是難，是寫得太複雜

⸻

6. Correct Code

#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n && n != 0){
        while(n >= 10){
            int sum = 0;
            while(n > 0){
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        cout << n << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Structure	多變數混亂	單變數控制
Readability	低	高
Logic	間接	直接
Correctness	易錯	穩定

⸻

Reflection

* 這題核心：
    👉 digit sum reduction
* 常見錯誤：
    * 用太多變數（ans/sum/a）
    * 沒有統一控制 n
* 正確思維：
    👉 「全部用 n 本身做更新」
* UVA 經典技巧：
    * 能簡單就不要複雜化