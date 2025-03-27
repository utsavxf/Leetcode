class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //good question
        int n=nums.size();
        vector<int>bits(maximumBit,0);
        for(auto it:nums){
            for(int i=0;i<maximumBit;i++){
                if(it&(1<<i))bits[i]++;
            }
        }

        int last=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int k=0;
            //in this step we'll remove the last element and calculate the new k
            for(int j=maximumBit-1;j>=0;j--){
                if(last&(1<<j))bits[j]--;
                if(bits[j]%2==0){
                    k+=(1<<j);
                }
            }
            ans.push_back(k);
            last=nums[n-(i+1)];
        }
        
        return ans;
    }
};
