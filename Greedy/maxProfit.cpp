#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int deadline,profit;
};

int main() {
    int n;
    cin>>n;
    vector<Node> jobs(n);
    
    for(int i=0;i<n;i++){
        cin>> jobs[i].deadline >> jobs[i].profit ;
        if(jobs[i].deadline<1){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    sort(jobs.begin(),jobs.end(),[](Node& a , Node& b){return a.profit > b.profit;});
    
    vector<bool> slots(101,false);
    
    int maxProfit = 0 , jobsScheduled = 0;
    
    for(Node job : jobs){
        for(int i=job.deadline ;i>0;i--){
            if(!slots[i]){
                slots[i] = true;
                maxProfit += job.profit;
                ++jobsScheduled;
                break;
            }
        }
    }
    cout << jobsScheduled << "\n" << maxProfit;
    
}