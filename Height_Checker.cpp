#include <iostream>
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int n=heights.size(), ans=0;
        for(int i=0; i<n; i++)
            ans+=(heights[i]!=sorted[i]);
        return ans;      
    }
};

int main(){

     Solution sl;
     vector<int> nums = {1,1,4,2,1,3};
     
     int ans = sl.heightChecker(nums);

    
     cout << ans << " ";
}