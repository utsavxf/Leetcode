class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //optimal way is using only 1 loop
        int n=nums.size();
        long long ans=0;
        long long maxElement=0;
        long long maxDifference=0;
        for(int i=0;i<n;i++){
            ans=max(ans,maxDifference*nums[i]);
            maxDifference=max(maxDifference,maxElement-nums[i]);
            maxElement=max(maxElement,(long long)nums[i]);
        }
        if(ans<=0)return 0;
        return ans;
    }
};
