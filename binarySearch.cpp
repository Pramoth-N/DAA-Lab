#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &nums, int x){
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid] == x){
            return true;
        }
        else if(nums[mid] < x){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    if(n<=0){
        cout << "-1" << endl;
        return 0;
    }
    vector<int> nums(n);

    for (int i = 0; i < n; i++){
        cin >> nums[i];
        if(cin.fail()){
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    int x;
    cin >> x;
    if(binarySearch(nums, x)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
}