UVa 673 - Parentheses Balance

1. Problem Information

* Platform: UVa
* Problem ID: 673
* Problem Title: Parentheses Balance
* Problem Link: https://onlinejudge.org/external/6/673.html
* Source Code (Fail): ./src/parentheses_balance_fail.cpp
* Source Code (Correct/Accepted): ./src/parentheses_balance_accepted.cpp

⸻

2. Problem Description

判斷每一行字串中的括號是否「完全匹配」。

⸻

規則

只考慮：

* ( 與 )
* [ 與 ]

需要檢查：

* 是否正確配對
* 是否正確順序（不能錯位 closing）
* 是否全部匹配完

⸻

輸出

* 正確 → Yes
* 錯誤 → No

⸻

3. Solution Idea

核心想法

👉 使用 stack 模擬括號配對

⸻

規則

* 左括號 ( [ → push
* 右括號：
    * 必須 match stack top
    * 不符合 → fail

⸻

重要點

最後還要檢查：

👉 stack 必須是空的

⸻

4. Pseudocode

START
READ n
FOR each test case
    read line
    stack s
    valid = true
    FOR each char
        IF '(' or '[' → push
        IF ')':
            if stack top == '(' → pop
            else invalid
        IF ']':
            if stack top == '[' → pop
            else invalid
    IF valid AND stack empty → Yes
    ELSE → No
END

⸻

5. Source Code

Fail Code

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	cin.ignore();
	for(int s=0; s<n; s++){
		bool iscorrect=1;
		string x;
		getline(cin, x);
		stack<char> c;
		
		for(int i=0; i<x.size(); i++){
			char ch=x[i];
			if(ch=='(' || ch=='['){
				c.push(ch);
			}
			else if(ch==')'){
				if(c.empty()==0 && c.top()=='('){
					c.pop();
				}
				else{
					iscorrect=0;
				}
			}
			else if(ch==']'){
				if(c.empty()==0 && c.top()=='[' ){
					c.pop();
				}
				else{
					iscorrect=0;
				}
			}
			
		}
		
		if(iscorrect==0){
			cout<<"No"<<endl;
		}
		else if(c.empty()==0){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}	
	}
	
	return 0;
}

⸻

Why it failed:

這份其實接近 AC，但有一個關鍵隱患：

⸻

❌ 1. 沒有「提前 break」

iscorrect = 0;

但你：

* 沒有 break
* 仍繼續掃描字串
* stack 狀態可能繼續被誤操作

👉 正確做法：一旦 invalid 就停止處理

⸻

❌ 2. continue 處理不完整

當 iscorrect = 0 後仍繼續：

* push/pop 邏輯仍在執行
* 可能造成 stack 偽狀態

⸻

❌ 3. 邏輯雖對，但「穩定性不足」

⸻

6. Correct Code

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        stack<char> st;
        bool ok = true;
        for(char c : s){
            if(c == '(' || c == '['){
                st.push(c);
            }
            else if(c == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(!st.empty()) ok = false;
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

⸻

7. Difference and Reflection

Key Differences

Item	Fail Code	Correct Code
control flow	continues after error	breaks immediately
safety	medium	high
stack integrity	risk	guaranteed
readability	ok	clean

⸻

Reflection

* 這題核心：
    👉 stack matching + early exit
* 最大問題：
    * 沒有 stop-on-fail
* 正確習慣：
    👉 一旦 mismatch → break
* UVA stack 題標準模板：

push left
match right
fail → break