#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    // 1️⃣ 找在哪一列
    int row = -1;
    for(int i = 0; i < m; i++){
        if(target >= matrix[i][0] && target <= matrix[i][n-1]){
            row = i;
            break;
        }
    }

    // 找不到那一列
    if(row == -1){
        cout << "false" << endl;
        return 0;
    }

    // 2️⃣ 在那一列做 binary search
    int left = 0, right = n - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(matrix[row][mid] == target){
            cout << "true" << endl;
            return 0;
        }
        else if(matrix[row][mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << "false" << endl;

    return 0;
}