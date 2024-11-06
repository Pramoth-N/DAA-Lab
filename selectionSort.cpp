#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(nums[j] < nums[min]){
                min = j;
            }
        }
        swap(nums[i], nums[min]);
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
    selectionSort(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}