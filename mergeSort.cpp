#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums , int left ,int mid , int right){
    vector<int> left_arr(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> right_arr(nums.begin() + mid + 1, nums.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while(i < left_arr.size() && j < right_arr.size()){
        if(left_arr[i] < right_arr[j]){
            nums[k++] = left_arr[i++];
        }else{
            nums[k++] = right_arr[j++];
        }
    }

    while(i < left_arr.size()){
        nums[k++] = left_arr[i++];
    }
    while(j < right_arr.size()){
        nums[k++] = right_arr[j++];
    }
    
    left_arr.clear();
    right_arr.clear();
}

void mergeSort(vector<int>& nums , int low , int high){
    if(low >= high){
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
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
    mergeSort(nums, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}