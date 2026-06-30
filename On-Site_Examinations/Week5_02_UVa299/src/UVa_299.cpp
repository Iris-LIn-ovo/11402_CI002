#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int L;
        cin >> L;
        int arr[60];
        for(int i = 0; i < L; i++){
            cin >> arr[i];
        }
        int swaps = 0;
        for(int i = 0; i < L; i++){
            for(int j = i + 1; j < L; j++){
                if(arr[i] > arr[j]){
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    return 0;
}
