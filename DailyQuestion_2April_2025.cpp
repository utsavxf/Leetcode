class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //brute force is 3 for loops
        //so to maximize the expression value of i should be as large as possible, value of j should be as small as possible and value of k should be as large as possible
        int n=nums.size();
        //can be solved in 1 pass also
        long long ans=0;
        long long maximum_elem=0;
        long long maximum_diff=0;
        
        for(int i=0;i<n;i++){
            //compute the answer at first as you know (i,j)<k
            ans=max(ans,nums[i]*maximum_diff);
            //compute the diff next as you know i<j
            maximum_diff=max(maximum_diff,maximum_elem-nums[i]);
            maximum_elem=max(maximum_elem,(long long)nums[i]);   
        }
        return ans; 
    }
};
