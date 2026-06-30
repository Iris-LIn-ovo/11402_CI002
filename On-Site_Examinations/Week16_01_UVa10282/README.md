UVa 10282 - Babelfish

1. Problem Information

* Platform: UVa
* Problem ID: 10282
* Problem Title: Babelfish
* Problem Link: https://onlinejudge.org/external/102/10282.html
* Source Code (Fail): ./src/babelfish_fail.cpp
* Source Code (Correct/Accepted): ./src/babelfish_accepted.cpp

⸻

2. Problem Description

你會先得到一組「字典資料」，每行包含：

foreign_word english_word

⸻

任務

之後輸入查詢字：

* 如果字典中有這個 foreign_word → 輸出對應 english_word
* 如果沒有 → 輸出 "eh"

⸻

3. Solution Idea

核心觀念

👉 hash map / dictionary lookup

⸻

最佳方法

用：

unordered_map<string, string>

⸻

流程

1. 讀取字典直到空行
2. 存入 map
3. 查詢每個單字
4. O(1) lookup

⸻

4. Pseudocode

map = {}
WHILE read line:
    if line empty: break
    map[b] = a
WHILE read query:
    if query in map:
        print map[query]
    else:
        print "eh"

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int main(){
	string a,b;
	vector<vector<int> > v(100000); 
	int count=0
	while(cin>>a>>b){
		v[count].push_back(a);
		v[count].push_back(b);
		count++;
		for(int i=0; i<count; i++){
			if(a====v[i][1]){
				cout<<v[i][0]<<endl;
				break;
			}
		}
	}
	
	while(1){
		string ans;
		cin>>ans;
		for(int i=0; i<count; i++){
			if(ans==v[i][1]){
				cout<<v[i][0]<<endl;
			}
			else{
				cout<<"eh"<<endl;
			}
		}
	}
	
	
	return 0;
}

⸻

6. Why it failed

這份 code 問題很多，不只是 bug，而是「資料結構錯誤」。

⸻

❌ 1. vector type 完全錯

vector<vector<int>> v;

但你存的是：

string a, b;

👉 應該是：

* vector<pair<string,string>>
    或
* unordered_map

⸻

❌ 2. 語法錯誤

int count=0
a====

⸻

❌ 3. 查詢邏輯錯誤

for(int i=0; i<count; i++)

👉 每次查詢都 O(n)，且還輸出：

else cout << "eh";

👉 會輸出很多次 eh（錯誤）

⸻

❌ 4. 無限迴圈設計錯

while(1)

沒有 EOF 控制

⸻

❌ 5. key-value 用反 or 沒固定

你比較：

if(ans == v[i][1])

但 v[i][1] 根本不是 string（型別錯）

⸻

7. Correct Code

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, string> mp;
    string a, b;
    // read dictionary
    while(true){
        string line;
        getline(cin, line);
        if(line.empty()) break;
        int pos = line.find(' ');
        a = line.substr(0, pos);
        b = line.substr(pos + 1);
        mp[b] = a;
    }
    // query
    string q;
    while(cin >> q){
        if(mp.count(q)){
            cout << mp[q] << "\n";
        }else{
            cout << "eh\n";
        }
    }
    return 0;
}

⸻

8. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
structure	vector<vector>	unordered_map
lookup	O(n) scan	O(1) hash
output	wrong loop printing	single output
correctness	WA	AC

⸻

Reflection

* 這題核心：
    👉 dictionary lookup
* 最大錯誤：
    * 沒用 map
    * 用 vector 硬掃
* 正確觀念：
    👉 看到 “key → value 查詢” = hashmap