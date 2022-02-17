#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ; cin>>t;
    while(t--)
    {
        int n ; cin>>n;
        bool cond = true;
        vector<int>nums(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin>>nums[i];
            
        }
        int last = INT_MAX;
        for(int i = 0 ; i < n- 1; i++)
        {
            int diff = nums[i];
            
            diff-=nums[i+1];
            int diff_ = abs(diff);
            if(last == INT_MAX)
                last = diff_;
            else
                if(abs(last - diff_) == 1)
                {
                    last = diff_;
                    continue;
                }
                else
                {
                    // cout<<nums[i];
                    cond = false; break;
                }
        }
        if(cond == false)
            cout<<"Incorrect Formation\n";
        else
            cout<<"Correct Formation\n";
    }
    return 0;
}
