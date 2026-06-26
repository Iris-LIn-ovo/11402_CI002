#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0; // 偏好 0 的學生人數
        int count1 = 0; // 偏好 1 的學生人數
        
        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }
        
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 > 0) count0--; // 有喜歡 0 的學生，消耗掉
                else break;               // 沒有人喜歡 0，剩下的都無法進食
            } else {
                if (count1 > 0) count1--; // 有喜歡 1 的學生，消耗掉
                else break;               // 沒有人喜歡 1，剩下的都無法進食
            }
        }
        
        return count0 + count1;
    }
};
