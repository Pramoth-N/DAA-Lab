#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high){
    int pivot = nums[high], index = low;

    for (int i = low; i < high;i++){
        if(nums[i] < pivot){
            swap(nums[i], nums[index++]);
        }
    }
    swap(nums[index], nums[high]);

    return index;
}

void quickSort(vector<int>& nums , int low , int high){
    if(low >= high){
        return;
    }

    int pivot = partition(nums, low, high);

    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
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
    quickSort(nums, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}