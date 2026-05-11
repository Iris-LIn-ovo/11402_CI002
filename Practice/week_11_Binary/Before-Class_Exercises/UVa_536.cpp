#include <iostream>
#include <string>
using namespace std;

void chanpos(string pre, string in){
    if(pre.empty())return;

    char root=pre[0];//雖然把字元存進 int 沒問題，但當你最後執行 cout << root; 時
    //C++ 會因為 root 是 int 型態，而印出 ASCII 編碼（數字） 而不是字母（例如印出 65 而不是 A）
    int pos=in.find(root);

    string left_in=in.substr(0,pos);
    string left_pre=pre.substr(1,pos);

    string right_in=in.substr(pos+1);
    string right_pre=pre.substr(pos+1);

    chanpos(left_pre, left_in);
    chanpos(right_pre, right_in);
    cout<<root;

}

int main(){
    string pre,in;
    while(cin>>pre>>in){
        chanpos(pre,in);
        cout<<endl;
    }

    return 0;
}