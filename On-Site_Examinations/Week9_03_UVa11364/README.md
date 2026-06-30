UVa 11364 - Parking

1. Problem Information

* Platform: UVa
* Problem ID: 11364
* Problem Title: Parking
* Problem Link: https://onlinejudge.org/external/113/11364.html
* Source Code (Fail): ./src/parking_fail.cpp
* Source Code (Correct/Accepted): ./src/parking_accepted.cpp

⸻

2. Problem Description

有一條街上有很多停車位，每個停車位都有不同的商店位置。

你需要找到一個停車點，使得所有商店走路距離最小。

⸻

規則

* 只能選一個停車點
* 每個商店到停車點的距離是：

|position - parking_position|

* 要讓所有距離總和最小

⸻

3. Solution Idea

核心觀念

👉 最佳停車點 = median（中位數）

⸻

為什麼？

在一維座標中：

* sum of absolute distances 最小點 = median

⸻

流程

1. 讀入所有位置
2. sort
3. 取 median
4. 計算所有 distance sum

⸻

4. Pseudocode

START
FOR each test case
    read n
    read array
    sort array
    median = middle element
    ans = sum(|x - median|)
    print ans
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	
	int t,n;
	cin>>t;
	
	for(int j=0; j<t; j++){
		cin>>n;
		int max,min,a;
		min=1000;
		max=-1;
		
		for(int i=0; i<n; i++){
			cin>>a;
			
			if(a<min){
				min=a;
			}
			if(a>max){
				max=a;
			}
		}
		
		int ans;
		ans=(max-min)*2;
		
		cout<<ans<<endl;
			
	}
	
	
	return 0;
}

⸻

Why it failed:

⸻

❌ 1. 完全錯誤公式

ans = (max - min) * 2;

👉 這只是「兩端距離」，不是總距離

⸻

❌ 2. 忽略所有中間點

* 題目需要 sum of distances
* 不是 range

⸻

❌ 3. 沒有 median 概念

這題核心不是 max/min，而是：

👉 median optimization

⸻

6. Correct Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int median = v[n / 2];
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(v[i] - median);
        }
        cout << ans << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Concept	max-min	median
Formula	incorrect	correct
Logic	incomplete	correct math model
Output	wrong model	correct sum

⸻

Reflection

* 這題核心：
    👉 absolute distance minimization
* 最大錯誤：
    * 用 range 代替 sum
* 正確觀念：
    👉 一維最小距離 = median
* UVA 很常考：
    * “看起來像 min/max，其實是 median”