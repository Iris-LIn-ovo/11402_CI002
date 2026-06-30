UVa 12250 - Language Detection

1. Problem Information

* Platform: UVa
* Problem ID: 12250
* Problem Title: Language Detection
* Problem Link: https://onlinejudge.org/external/122/12250.html
* Source Code (Fail): ./src/language_detection_fail.cpp
* Source Code (Correct/Accepted): ./src/language_detection_accepted.cpp

⸻

2. Problem Description

給定多筆輸入字串，每筆代表一句「問候語」。

需要判斷該問候語屬於哪一種語言。

⸻

對應關係

Greeting	Language
HELLO	ENGLISH
HOLA	SPANISH
HALLO	GERMAN
CIAO	ITALIAN
BONJOUR	FRENCH
ZDRAVSTVUJTE	RUSSIAN

如果不在表內 → 輸出 UNKNOWN

⸻

3. Solution Idea

核心想法

* 用 if-else 或 map 做對照
* 逐行讀入字串直到 # 結束

⸻

流程

1. 讀入字串 a
2. 如果 a == “#”
    * 結束
3. 判斷對應語言
4. 輸出 Case i

⸻

Edge Cases

* 未知字串
* 大寫輸入（固定）
* 結束符號 #

⸻

4. Pseudocode

START
case = 1
WHILE read string a and a != "#"
    print "Case case: "
    IF a == HELLO → ENGLISH
    ELSE IF a == HOLA → SPANISH
    ELSE IF a == HALLO → GERMAN
    ELSE IF a == CIAO → ITALIAN
    ELSE IF a == BONJOUR → FRENCH
    ELSE IF a == ZDRAVSTVUJTE → RUSSIAN
    ELSE → UNKNOWN
    case++
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
	string a;
	int count=1;
	
	while(cin>>a && a!="#"){
		cout<<"Case "<<count<<": ";
		if(a=="HELLO"){
			cout<<"ENGLISH";
		}
		else if(a=="HOLA"){
			cout<<"SPANISH";
		}
		else if(a=="HALLO"){
			cout<<"GERMAN";
		}	
		else if(a=="CIAO"){
			cout<<"ITALIAN";
		}
		else if(a=="BONJOUR"){
			cout<<"FRENCH";
		}
		else if(a=="ZDRAVSTVUJTE"){
			cout<<"RUSSIAN";
		}
		else{	
			cout<<"UNKNOWN";	
		}
		cout<<endl;
		count++;
	}
	
	return 0;
}

⸻

Why it failed:

* ⚠️ 其實這份是 AC 等級解法
* 只是可以優化：
    * ❌ if-else 太長（可用 map）
    * ❌ 可讀性一般
    * ❌ 擴充性差（新增語言要改 code）

👉 但邏輯完全正確

⸻

6. Correct Code (Improved)

#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<string, string> mp = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"CIAO", "ITALIAN"},
        {"BONJOUR", "FRENCH"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };
    string s;
    int caseNum = 1;
    while(cin >> s && s != "#"){
        cout << "Case " << caseNum++ << ": ";
        if(mp.count(s))
            cout << mp[s] << endl;
        else
            cout << "UNKNOWN" << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
Logic	if-else chain	hash map
Scalability	low	high
Readability	medium	high
Maintenance	hard	easy

⸻

Reflection

* 這題核心很簡單：
    👉 string mapping
* 重點不是邏輯，而是：
    * 用不用資料結構優化
* UVA 常見技巧：
    👉 能用 map 就不要寫 if-else chain