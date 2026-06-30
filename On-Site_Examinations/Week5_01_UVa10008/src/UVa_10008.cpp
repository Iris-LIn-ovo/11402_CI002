#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    int cnt[26] = {0};
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        for(char c : s){
            if(isalpha(c)){
                c = toupper(c);
                cnt[c - 'A']++;
            }
        }
    }
    vector<pair<char,int>> v;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            v.push_back({char('A' + i), cnt[i]});
        }
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    for(auto &p : v){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}