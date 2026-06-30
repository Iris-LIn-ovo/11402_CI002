#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        // 桶陣列：索引代表頻率，vector 儲存該頻率下的所有元素
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : countMap) {
            buckets[count].push_back(num);
        }
        
        vector<int> result;
        // 從高頻率往低頻率收集
        for (int i = n; i >= 0 && result.size() < k; i--) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) break;
                }
            }
        }
        
        return result;
    }
};
