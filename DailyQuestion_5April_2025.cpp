class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        //how do you find all the subsets? by dp using take and not take approach
        //or finding subsets using the bit manipulation approach
        int n=nums.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int temp_xor=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                temp_xor^=nums[j];
            }
            ans+=temp_xor;
        }
        return ans;
    }
};
