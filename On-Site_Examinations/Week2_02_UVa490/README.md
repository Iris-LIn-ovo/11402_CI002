UVa 490 - Rotating Sentences

1. Problem Information

* Platform: UVa
* Problem ID: 490
* Problem Title: Rotating Sentences
* Problem Link: https://onlinejudge.org/external/4/490.html
* Source Code (Fail): ./src/rotating_sentences_fail.cpp
* Source Code (Correct/Accepted): ./src/rotating_sentences_accepted.cpp

⸻

2. Problem Description

Given multiple lines of text, rotate the entire block of text 90 degrees clockwise.

* Each line may have different lengths
* Missing characters should be filled with spaces
* Output the rotated result line by line

⸻

3. Solution Idea

* Store all input lines in a vector
* Find the maximum length among all lines
* Simulate rotation:
    * Outer loop: iterate columns (0 → max length)
    * Inner loop: iterate rows from bottom to top
* For each position:
    * If the current line is too short → print space
    * Otherwise → print the character

⸻

4. Pseudocode

START
Create vector<string> lines
WHILE input exists
    Read full line and store
Find max length among all lines
FOR i = 0 to max length - 1
    FOR j = last line to first line
        IF i >= length of line[j]
            print space
        ELSE
            print line[j][i]
    print newline
END

⸻

5. Source Code

Fail Code

// 常見錯誤版本（示意）
// 沒有補空格，導致輸出錯位

Issues:

* 沒有處理不同長度字串
* 未補空格導致輸出歪掉
* 旋轉方向可能寫反

⸻

Accepted Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<string> line;
    string s;
    while(getline(cin, s)){
        line.push_back(s);
    }
    int maxlen = 0;
    for(int i = 0; i < line.size(); i++){
        if(line[i].size() > maxlen){
            maxlen = line[i].size();
        }
    }
    
    for(int i = 0; i < maxlen; i++){
        for(int j = line.size() - 1; j >= 0; j--){
            if(i > line[j].size() - 1){
                cout << " ";
            }
            else{
                cout << line[j][i];
            }
        }
        cout << endl;
    }
    
    return 0;
}

Why it works:

* 正確找出最長字串長度
* 使用「列當行」的方式模擬旋轉
* 從底往上輸出達成順時針旋轉
* 補空格確保矩陣對齊

⸻

6. Reflection

* 不同長度的字串一定要補空格（這題關鍵）
* 旋轉題要先想清楚「索引怎麼對應」
* UVa 很常考輸出格式細節
* vector + getline 是處理多行輸入的標配