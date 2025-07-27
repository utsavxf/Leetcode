class Solution {
public:
    
    bool check(int curr,int left,int right){
        return (curr>left and curr>right) || (curr<left and curr<right);
    }

    int countHillValley(vector<int>& nums) {
        //we can ignore the duplicates
        int n=nums.size();
        vector<int>newNum;
        newNum.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
            newNum.push_back(nums[i]);
        }

        int n1=newNum.size();
        int cnt=0;
        for(int i=1;i<n1-1;i++){
            if(check(newNum[i],newNum[i-1],newNum[i+1]))
            cnt++;
        }
        return cnt;
    }
};
