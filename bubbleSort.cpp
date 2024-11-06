#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    if(n<=0){
        cout << "-1";
        return 0;
    }
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(cin.fail()){
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    bubbleSort(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}