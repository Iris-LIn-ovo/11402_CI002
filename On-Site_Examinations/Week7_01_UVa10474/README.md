UVa 10474 - Where is the Marble?

1. Problem Information

* Platform: UVa
* Problem ID: 10474
* Problem Title: Where is the Marble?
* Problem Link: https://onlinejudge.org/external/104/10474.html
* Source Code (Fail): ./src/marbles_fail.cpp
* Source Code (Correct/Accepted): ./src/marbles_accepted.cpp

⸻

2. Problem Description

給定一組整數（marbles），以及多個查詢。

你需要對每個查詢：

* 判斷該數字是否存在於集合中
* 如果存在，輸出它在排序後的位置（從 1 開始）
* 如果不存在，輸出 not found

⸻

輸出格式

每組測資輸出：

CASE# X:

每個查詢輸出：

* x found at i
* 或 x not found

⸻

3. Solution Idea

核心想法

* 先將所有數字排序
* 對每個 query 使用 binary search
* 找到「第一次出現的位置」（lower bound 概念）

⸻

重點

* 必須找最左邊出現的位置（first occurrence）
* 因為可能有重複元素
* 所以找到後要繼續往左縮

⸻

Edge Cases

* 重複數字
* 查詢不存在的數
* 所有數字相同
* 查詢數量很多

⸻

4. Pseudocode

START
case = 1
WHILE read m, n and not (0,0)
    read m numbers into array
    sort array
    print "CASE# case:"
    FOR each query
        binary search:
            find leftmost index of x
        IF found
            print position + 1
        ELSE
            print not found
    case++
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int m,n;
	int count=1;
	while(cin>>m>>n && m!=0 && n!=0){
		
		cout<<"CASE# "<<count<<":"<<endl;
		
		vector<int> num;
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			num.push_back(x);
		}
		sort(num.begin(), num.end());
		
		
		while(n--){
			int x;
			cin>>x;
			
			int ans=-1;
			int min=0,max=num.size()-1;
			bool isfound=0;
			
			while(min<=max){
				int mid=(min+max)/2;
				
				if(num[mid]<x){
					min=mid+1;
				}
				else if(num[mid]>x){
					max=mid-1;
				}
				else{
					ans=mid;
					max=mid-1;
				}
			}
			
			if(ans==-1){
				cout<<x<<" not found"<<endl;
			}
			else{
				cout<<x<<" found at "<<ans+1<<endl;
			}
		}
		
		
		count++;
	}
	
	return 0;
}

⸻

Why it failed:

* ❌ binary search 正確（幾乎 AC）
* ⚠️ 變數命名 min/max（不建議，容易與 std::min/max 混淆）
* ⚠️ isfound 沒使用（冗餘）
* ⚠️ 可讀性偏低
* ⚠️ 沒用 lower_bound（標準解法）

👉 但本質上這份 code 是 AC 等級寫法

⸻

6. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int m, n;
    int kase = 1;
    while(cin >> m >> n && m && n){
        vector<int> v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << "CASE# " << kase++ << ":" << endl;
        while(n--){
            int x;
            cin >> x;
            int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
            if(pos < v.size() && v[pos] == x)
                cout << x << " found at " << pos + 1 << endl;
            else
                cout << x << " not found" << endl;
        }
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Search method	manual binary search	lower_bound
Readability	中等	高
Edge handling	手寫	STL 保證
Correctness	OK	更穩定

⸻

Reflection

* 這題核心是：
    👉 sorted array + first occurrence search
* 重點不是 binary search，而是：
    * 找 leftmost match
* 最佳解：
    👉 lower_bound（標準模板）
* UVA 類似題型：
    * 一定可以用 STL 優化