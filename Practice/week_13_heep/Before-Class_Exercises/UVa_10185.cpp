#include <iostream>
#include <string>
#include <set>
#include <cctype> // 為了使用 isalpha 和 tolower

using namespace std;

int main() {
    string s;
    set<string> dictionary; // 宣告一個存儲 string 的 set
    
    // 一行一行讀入，直到檔案結束 (EOF)
    while (cin >> s) {
        string word = "";
        
        // 逐字元檢查讀入的字串
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) { 
                // 如果是英文字母，轉成小寫並加到當前的單字裡
                word += tolower(s[i]);
            } else {
                // 如果遇到標點符號或數字，代表一個單字結束了
                if (word != "") {
                    dictionary.insert(word); // 丟進 set，它會自動排序並去重
                    word = ""; // 清空，準備接下一個單字
                }
            }
        }
        
        // 檢查字串結尾是否還有殘留的單字（例如這行最後一個字沒接標點符號）
        if (word != "") {
            dictionary.insert(word);
        }
    }
    
    // 因為 set 底層是紅黑樹，內部已經自動幫你按照 A-Z 排好了
    // 直接用 range-based for loop 印出，就是完美的字典
    for (const string& w : dictionary) {
        cout << w << endl;
    }
    
    return 0;
}