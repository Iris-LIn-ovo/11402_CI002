UVa 11321 - Sort! Sort!! and Sort!!!

1. Problem Information

* Platform: UVa
* Problem ID: 11321
* Problem Title: Sort! Sort!! and Sort!!!
* Problem Link: https://onlinejudge.org/external/113/11321.html
* Source Code (Fail): ./src/sort_fail.cpp
* Source Code (Correct/Accepted): ./src/sort_accepted.cpp

⸻

2. Problem Description

給定 n 個整數與一個整數 m，需要依照以下規則排序：

排序規則

1. 先依照 x % m 由小到大排序
2. 若餘數相同：
    * 奇數在前
    * 偶數在後
3. 若仍相同：
    * 奇數：較大的在前
    * 偶數：較小的在前

⸻

3. Solution Idea

核心想法

這題是 custom sort（自訂排序）題型

* 不能用一般 sort
* 必須寫 comparator function

⸻

排序規則拆解

對兩個數 a, b：

1. a % m != b % m
    → 比較餘數
2. 同餘數：
    * 奇偶不同：
        * odd < even
    * 同為奇數：
        * 大的排前
    * 同為偶數：
        * 小的排前

⸻

4. Pseudocode

START
WHILE read n, m and not (0,0)
    read array
    sort using comparator:
        if a%m != b%m → smaller first
        if both odd → larger first
        if both even → smaller first
        odd before even
    print result
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
	int n,m
	while(cin>>n>>m && n!=0 && m!=0){
		cout<<n<<" "<<m<<endl;
		vector<int> num;
		vector<vector<int>> sortnum;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		
		for(int i=0; i<n; i++){
			int x;
			x=num[i]%m;
			sortnum[x].push_back(num[i]);
		}
		
		for(int i=0; i<m; i++){
			sort(sortnum.begin(), sortnum.end(), cmp)
		}
	}
	
	return 0;
}

⸻

Why it failed:

* ❌ int n,m missing ;
* ❌ sortnum 沒初始化大小（會 crash）
* ❌ 嘗試 bucket sort，但題目需要 complex comparator
* ❌ cmp 未定義
* ❌ sorting strategy 完全錯誤
* ❌ sort(sortnum.begin(), ...) 用錯容器

👉 本題核心不是 bucket sort，而是 custom comparator sort

⸻

6. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m;
bool cmp(int a, int b){
    int ra = a % m;
    int rb = b % m;
    if(ra != rb)
        return ra < rb;
    bool oa = a % 2;
    bool ob = b % 2;
    if(oa != ob)
        return oa > ob; // odd first
    if(oa) // both odd
        return a > b;
    // both even
    return a < b;
}
int main(){
    int n;
    while(cin >> n >> m && (n || m)){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp);
        cout << n << " " << m << endl;
        for(int x : v){
            cout << x << endl;
        }
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Approach	bucket sort attempt	comparator sort
Correctness	incorrect structure	correct logic
Implementation	incomplete	clean STL sort
Stability	broken	deterministic

⸻

Reflection

* 這題核心是：
    👉 multi-key sorting
* 常見錯誤：
    * 想用 bucket（錯方向）
    * 忘記 comparator 規則順序
* 正確思維：
    👉 「所有條件都可以塞進 cmp」
* UVA sorting 題標準套路：
    * sort + custom comparator