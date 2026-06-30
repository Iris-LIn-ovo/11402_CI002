UVa 11389 - The Bus Driver Problem

1. Problem Information

* Platform: UVa
* Problem ID: 11389
* Problem Title: The Bus Driver Problem
* Problem Link: https://onlinejudge.org/external/113/11389.html
* Source Code (Fail): ./src/bus_driver_fail.cpp
* Source Code (Correct/Accepted): ./src/bus_driver_accepted.cpp

⸻

2. Problem Description (My Own Words)

有：

* n 個 bus driver
* 每個 driver 有：
    * morning route（早班時間）
    * evening route（晚班時間）
* 一天工作總時間限制為 d

⸻

規則

* 一個 driver 如果：
    [
    morning + evening > d
    ]
    就會產生 overtime
* overtime 只算超過的部分：

[
max(0, (morning + evening - d))
]

⸻

目標

👉 安排 pairing，使 overtime cost 最小
👉 並輸出 total overtime × r

⸻

3. Thinking Logic and Solution Strategy

Initial Thoughts

一開始可能會想：

* 隨便配
* 或 greedy 一半一半

但會發現：

👉 pairing 方式會影響 total overtime

⸻

Final Strategy

👉 Greedy sorting pairing

⸻

核心想法

* morning 小的 + evening 大的
* morning 大的 + evening 小的

👉 讓總和盡量平均分散

⸻

4. Pseudocode

read n, d, r
read morning[]
read evening[]
sort(morning)
sort(evening)
total = 0
for i in 0..n-1:
    sum = morning[i] + evening[n-1-i]
    overtime += max(0, sum - d)
print overtime * r

⸻

5. Fail Code vs Correct Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,d,r;
	int count=0;
	while(cin>>n>>d>>r){
		if(count!=0){
			cout<<endl;
		}
		count++;
		if(n==0 && d==0 & r==0){
			break;
		}
		vector<int> m;
		vector<int> a;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			m.push_back(x);
		}
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		
		sort(m.begin(), m.end());
		sort(a.begin(), a.end());
		
		int sum;
		int overtime=0;
		for(int i=0; i<n; i++){
			sum=m[i]+a[n-1-i];
			int over=sum-d;
			if(over<0)over=0;
			overtime+=over;
		}
		
		int pay=r*overtime;
		cout<<pay;
	}
	
	return 0;
}

⸻

6. Why it failed

❌ 1. 條件寫錯（重大 bug）

if(n==0 && d==0 & r==0)

👉 & 應該是 &&

⸻

❌ 2. 沒處理輸出格式

cout << pay;

👉 少 newline / format

⸻

❌ 3. pairing concept OK，但命名混亂

* m = morning
* a = afternoon

👉 可讀性差

⸻

❌ 4. break logic 放錯位置

應該先判斷 termination，再處理輸出

⸻

7. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, d, r;
    while (cin >> n >> d >> r) {
        if (n == 0 && d == 0 && r == 0)
            break;
        vector<int> morning(n);
        vector<int> evening(n);
        for (int i = 0; i < n; i++) {
            cin >> morning[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> evening[i];
        }
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());
        int overtime = 0;
        for (int i = 0; i < n; i++) {
            int total = morning[i] + evening[n - 1 - i];
            if (total > d) {
                overtime += (total - d);
            }
        }
        cout << overtime * r << endl;
    }
    return 0;
}

⸻

8. Difference and Reflection

Item	Fail Code	Correct Code
termination	bug (&)	correct &&
pairing	correct idea	same
output	missing format	clean
structure	messy	clean

⸻

9. Reflection

* 這題核心：
    👉 sorting + greedy pairing
* 最大問題：
    * 小 bug（& vs &&）會直接 WA
* 正確觀念：
    👉 greedy 題要注意「pairing 方式 + 細節」