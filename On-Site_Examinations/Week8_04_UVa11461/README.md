UVa 11461 - Square Numbers

1. Problem Information

* Platform: UVa
* Problem ID: 11461
* Problem Title: Square Numbers
* Problem Link: https://onlinejudge.org/external/114/11461.html
* Source Code (Fail): ./src/square_numbers_fail.cpp
* Source Code (Correct/Accepted): ./src/square_numbers_accepted.cpp

⸻

2. Problem Description

給定多組區間 [a, b]，需要計算：

👉 在區間內有多少個 完全平方數（perfect squares）

⸻

完全平方數定義

如果存在整數 k，使得：

i = k × k

則 i 是完全平方數。

⸻

3. Solution Idea

核心想法

* 逐一檢查區間中的每個數字
* 用 sqrt(i) 判斷是否為平方數

⸻

判斷方式

x = sqrt(i)
if x * x == i → 是平方數

⸻

Edge Cases

* a = 0 或 1
* b 很大（效率 OK）
* 區間很大

⸻

4. Pseudocode

START
WHILE read a, b and not (0,0)
    count = 0
    FOR i = a to b
        x = floor(sqrt(i))
        IF x*x == i
            count++
    print count
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b && a!=0 && b!=0){
		int count=0;
		for(int i=a; i<=b; i++){
			int x;
			x=sqrt(i);
			if(i==x*x)count++;
		}
		cout<<count<<endl;
	}
	
	return 0;
}

⸻

Why it failed:

* ⚠️ 這份其實是 AC 等級寫法
* 只是效率較低（O(n √n) 概念）
* 潛在問題：
    * sqrt 浮點誤差風險（小機率 WA）
    * 可以優化成 O(√n)

⸻

6. Correct Code (Optimized)

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b;
    while(cin >> a >> b && (a || b)){
        
        int start = sqrt(a);
        int end = sqrt(b);
        int count = end - start;
        // 修正邊界（a 本身是平方數）
        if(start * start == a) count++;
        cout << count << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Approach	brute force	math optimization
Complexity	O(n)	O(√n)
Accuracy	sqrt risk	safe integer logic
Performance	slower	faster

⸻

Reflection

* 這題核心是：
    👉 count perfect squares in range
* 最重要觀念：
    * 不需要逐個檢查
    * 直接用 sqrt(a), sqrt(b)
* UVA 常見技巧：
    👉 「把 range problem 轉成 math formula」