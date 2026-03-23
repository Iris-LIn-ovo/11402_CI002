/*
179. Largest Number
Medium

Topics
premium lock icon
Companies
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

int main(){
    vector<int> num;
    int x;

    while(cin>>x){
        num.push_back(x);
    }
    vector<string> v;
    for(int i=0; i<num.size(); i++){
        v.push_back(to_string(num[i]));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    return 0;
}