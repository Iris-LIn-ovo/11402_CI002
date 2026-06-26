#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 建立映射，key 為數值，value 為 arr2 中的索引
        unordered_map<int, int> weight;
        for (int i = 0; i < arr2.size(); i++) {
            weight[arr2[i]] = i;
        }
        
        // 使用自定義比較函數
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool hasA = weight.count(a);
            bool hasB = weight.count(b);
            
            if (hasA && hasB) {
                return weight[a] < weight[b]; // 都在 arr2 中，比權重
            } else if (hasA || hasB) {
                return hasA; // 只有一個在 arr2 中，在的優先
            } else {
                return a < b; // 都不在 arr2 中，直接比數值
            }
        });
        
        return arr1;
    }
};
