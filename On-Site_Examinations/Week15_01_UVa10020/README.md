UVa 10020 - Minimal Coverage

1. Problem Information

* Platform: UVa
* Problem ID: 10020
* Problem Title: Minimal Coverage
* Problem Link: https://onlinejudge.org/external/100/10020.html
* Source Code (Fail): ./src/minimal_coverage_fail.cpp
* Source Code (Correct/Accepted): ./src/minimal_coverage_accepted.cpp

⸻

2. Problem Description

給定一個區間 ([0, m])，以及多個小區間 ([a, b])，要求選出最少數量的區間來完整覆蓋 ([0, m])。

⸻

目標

* 覆蓋整段 ([0, m])
* 使用最少區間
* 若無法覆蓋 → 輸出 0（或空行）

⸻

3. Solution Idea

核心想法

👉 Greedy + interval selection

⸻

關鍵策略

每次選：

👉 在目前能覆蓋起點的區間中
👉 結束點最遠的那一個

⸻

流程

1. 排序所有區間（依 start）
2. 從 0 開始
3. 每次挑最遠可延伸區間
4. 更新 current coverage
5. 重複直到 ≥ m

⸻

4. Pseudocode

read T
FOR each test case
    read m
    read intervals
    sort intervals by start
    cur = 0
    i = 0
    WHILE cur < m
        best = cur
        WHILE interval.start <= cur
            best = max(best, interval.end)
            i++
        IF best == cur
            FAIL
        cur = best
        add interval to answer
print result

⸻

5. Source Code

Fail Code

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	int N;
	cin>>N;
	string blank;
	getline(cin, blank);
	for(int n=0; n<N; n++){
		int m;
		cin>>m;
		bool num[m]={0};
		int pair[100000][2];
		int pcount=0;
		for(int i=0; i<100001; i++){
			int a,b;
			cin>>a>>b;
			if(a==0 && b==0)break;
			if(a>=0 && a<=m && b>=m){
				int x;
				if(b>m){
					x=m-a;
				}
				else{
					x=b-a;
				}
				
				pair[pcount][0]=a;
				pair[pcount][1]=b;
				pcount++;
				
				if(x==0){
					num[m]==1;
					
				}
				else{
					for(int l=0; l<x; l++){
						num[l+a]==1;
					}
				}
			}
		}
		
		bool ok=1;
		for(int i=0; i<=m; i++){
			if(num[i]==0)ok=0;
		}
		if(ok==0){
			cout<<endl;
		}
		else{
			for(int i=0; i<pcount; i++){
				cout<<pair[i][0]<<" "<<pair[i][1]<<endl;
			}
		}
		cout<<endl;
	}
	
	return 0;
}

⸻

6. Why it failed

這份 code 的問題不是小 bug，而是：

⸻

❌ 1. 完全錯的解題模型

你現在做的是：

用 array 模擬 coverage

但正確解法是：

👉 greedy interval selection

⸻

❌ 2. 錯誤思維：用「填格子」

bool num[m] = {0};

👉 這會導致：

* O(m × intervals)
* 邏輯複雜
* 容易 WA

⸻

❌ 3. == 寫錯（嚴重 bug）

num[m] == 1;
num[l+a] == 1;

👉 這不是 assignment，是 comparison！

應該是：

num[m] = 1;
num[l+a] = 1;

⸻

❌ 4. 邊界條件完全錯誤

if(a>=0 && a<=m && b>=m)

👉 正確應該：

* a <= m
* b >= 0
* 不需要強制 b >= m

⸻

❌ 5. 完全沒有 greedy core

沒有：

* sort intervals
* choose best extension
* maintain current coverage

⸻

👉 結論：

❌ 這不是 bug，是「解題方向錯」

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Seg{
    int l, r;
};
bool cmp(Seg a, Seg b){
    return a.l < b.l;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int m;
        cin >> m;
        vector<Seg> v;
        while(true){
            int a, b;
            cin >> a >> b;
            if(a == 0 && b == 0) break;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), cmp);
        vector<Seg> ans;
        int cur = 0;
        int i = 0;
        int n = v.size();
        bool ok = true;
        while(cur < m){
            int best = cur;
            int pick = -1;
            while(i < n && v[i].l <= cur){
                if(v[i].r > best){
                    best = v[i].r;
                    pick = i;
                }
                i++;
            }
            if(best == cur){
                ok = false;
                break;
            }
            ans.push_back(v[pick]);
            cur = best;
        }
        if(!ok){
            cout << 0 << "\n";
        }else{
            cout << ans.size() << "\n";
            for(auto &x : ans){
                cout << x.l << " " << x.r << "\n";
            }
        }
        if(T) cout << "\n";
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
strategy	coverage simulation	greedy interval selection
complexity	high	O(n log n)
correctness	WA risk	AC
thinking model	grid fill	interval optimization

⸻

Reflection

* 這題核心：
    👉 Interval Greedy (maximum reach)
* 最大錯誤：
    * 用「填表」代替「選區間」
* 正確思維：
    👉 永遠選「能延伸最遠的區間」