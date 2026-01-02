class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        //brute force
        int n=nums.size();
        int n2=n/2;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]==n2)return nums[i];
        }
        return -1;
    }
};
