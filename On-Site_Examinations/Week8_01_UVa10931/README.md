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

* 將 n 轉成二進位表示
* 計算其中 1 的個數（popcount）
* 輸出：
    * 二進位字串
    * 1 的數量（mod 2 parity）

⸻

輸出格式

The parity of <binary> is <count> (mod 2).

⸻

3. Solution Idea

核心想法

* 用 % 2 不斷拆解數字轉成 binary
* 同時統計 1 的數量
* 再將 binary 反轉輸出

⸻

流程

1. 讀入 n（n != 0）
2. while n > 0：
    * n % 2 → binary bit
    * n / 2 更新
3. 統計 1 的數量
4. 反向輸出 binary

⸻

Edge Cases

* n = 1
* n = 2
* n = power of 2
* 多位 binary

⸻

4. Pseudocode

START
WHILE read n and n != 0
    vector bits
    WHILE n > 0
        bits.push_back(n % 2)
        n = n / 2
    count 1s
    print bits reversed
    print count
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
		int a;
		a=n;
		vector<int> num;
		int count=0;
		
		while(a>=2){
			int x;
			x=a%2;
			num.push_back(x);
			
			a=a/2;
		}
		num.push_back(1);
		
		for(int i=0; i<num.size(); i++){
			if(num[i]==1)count++;
		}
		
		cout<<"The parity of ";
		
		for(int i=num.size()-1; i>=0; i--){
			cout<<num[i];
		}
		cout<<" is "<<count<<" (mod 2)."<<endl;
	}
	return 0;
}

⸻

Why it failed:

* ❌ binary 轉換條件錯誤：
    * while(a >= 2) → 會漏掉部分情況
* ❌ 強制 num.push_back(1) → 不正確
* ❌ 沒有處理 n = 0 / 1 正確通用流程
* ❌ 邏輯是「補尾巴」，不是標準 binary algorithm
* ❌ 容易錯在邊界值（最常 WA 點）

⸻

6. Correct Code

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> bits;
        int cnt = 0;
        while(n > 0){
            int bit = n % 2;
            bits.push_back(bit);
            if(bit == 1) cnt++;
            n /= 2;
        }
        cout << "The parity of ";
        for(int i = bits.size() - 1; i >= 0; i--){
            cout << bits[i];
        }
        cout << " is " << cnt << " (mod 2)." << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Binary conversion	手動補 1	標準 %2 loop
Edge handling	不完整	完整通用
Correctness	易錯	穩定
Logic style	patch-based	algorithm-based

⸻

Reflection

* 這題核心是：
    👉 binary conversion（不能寫特例）
* 最大錯誤來源：
    * while(a >= 2)（錯）
    * 手動補 1（錯）
* 正確觀念：
    👉 永遠用 while(n > 0) 寫 binary
* UVA 很愛考：
    * 「你有沒有寫乾淨的基礎算法」