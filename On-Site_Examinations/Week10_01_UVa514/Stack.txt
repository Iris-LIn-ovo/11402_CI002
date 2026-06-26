// 宣告一個用來放整數 (int) 的堆疊，名字叫做 s
stack<int> s; 

s.push(10);   // 1. 推入 (Push)：把 10 丟進堆疊最頂端
s.push(20);   //    再把 20 丟進去，此時 20 在最上面

int top_val = s.top(); // 2. 看頂端 (Top)：看看最上面的元素是誰（會拿到 20）
                       // ⚠️ 注意：這只是看，並不會把數字拿走

s.pop();      // 3. 彈出 (Pop)：把最上面的元素（20）踢掉
              // ⚠️ 注意：pop() 回傳值是 void，它「純剔除」不拿回數值

bool is_empty = s.empty(); // 4. 檢查是否為空 (Empty)：如果堆疊空了回傳 true，否則 false

int current_size = s.size(); // 5. 取得大小 (Size)：看現在堆疊裡總共卡了幾個元素