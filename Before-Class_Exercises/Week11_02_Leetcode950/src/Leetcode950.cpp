#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        deque<int> d;
        for (int i = 0; i < n; i++) {
            d.push_back(i);
        }
        
        vector<int> result(n);
        for (int card : deck) {
            // 取出當前佇列最前面的索引，將牌放入該位置
            result[d.front()] = card;
            d.pop_front();
            
            // 如果還有剩餘的空間，將下一個索引移動到佇列最後面
            if (!d.empty()) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        
        return result;
    }
};
