UVa 10931 - Parity

1. Problem Information

* Platform: UVa
* Problem ID: 10931
* Problem Title: Parity
* Problem Link: https://onlinejudge.org/external/109/10931.html
* Source Code (Fail): ./src/parity_fail.cpp
* Source Code (Correct/Accepted): ./src/parity_accepted.cpp

⸻

2. Problem Description

給定一個整數 n（直到輸入 0 結束），需要：

* 將 n 轉成二進位
* 計算 binary representation 中 1 的個數（popcount）
* 輸出：
    * 二進位表示
    * 1 的個數（mod 2 parity）

⸻

輸出格式

The parity of <binary> is <count> (mod 2).

⸻

3. Solution Idea

核心想法

* 將 n 轉換成 binary
* 同時記錄每一位
* 計算 1 的數量（popcount）

⸻

流程

1. 不斷讀入 n（n != 0）
2. 用 %2 轉 binary
3. 存入 vector（反向）
4. 反轉輸出 binary
5. 計算 1 的數量
6. 輸出結果

⸻

Edge Cases

* n = 1
* n = 2
* 多位數 binary
* 直到 0 停止

⸻

4. Pseudocode

START
WHILE read n and n != 0
    vector bits
    WHILE n > 0
        push n % 2
        n = n / 2
    reverse output bits
    count number of 1s
    print formatted result
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=0){
		vector<int> num;
		int a=n;
		while(a>2){
			int x;
			x=a%2;
			num.push_back(x);
			int y=a/2;
			a=y;
		}
		if(a==2){
			num.push_back(0);
			num.push_back(1);
		}
		else if(a==1){
			num.push_back(1);
		}
		
		
		int count=0;
		for(int i=num.size(); i>0; i--){
			if(num[i-1]==1)count++;
		}
		
		cout<<"The parity of ";
		for(int i=num.size(); i>0; i--){
			cout<<num[i-1];
		}
		cout<<" is "<<count<<" (mod 2)."<<endl;
	}
	
	
	return 0;
}

⸻

Why it failed:

* ❌ binary 轉換邏輯錯誤（while(a>2) 不完整）
* ❌ 沒正確處理 a == 0 / 1 / 2 情況
* ❌ 邏輯複雜，不必要手動補 case
* ❌ 容易漏掉最高位
* ❌ 寫法冗長且容易錯

⸻

6. Correct Code

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> bits;
        int x = n;
        int count = 0;
        while(x > 0){
            int bit = x % 2;
            bits.push_back(bit);
            if(bit == 1) count++;
            x /= 2;
        }
        cout << "The parity of ";
        for(int i = bits.size() - 1; i >= 0; i--){
            cout << bits[i];
        }
        cout << " is " << count << " (mod 2)." << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Binary conversion	手動分 case	標準 %2 loop
Correctness	易錯	穩定
Complexity	複雜	簡潔
Counting	分離處理	同時處理

⸻

Reflection

* 這題核心是：
    👉 binary conversion + popcount
* 常見錯誤：
    * 手動處理 1/2/0 case
    * binary loop 寫錯條件
* 最佳做法：
    * %2 + /2 standard pattern
* UVA 重點：
    * 不要寫「特例補丁」，要寫通用邏輯