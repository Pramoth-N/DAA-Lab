#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int j = i-1;
        int key = nums[i];
        while(j>=0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
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
    insertionSort(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}