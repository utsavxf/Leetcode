class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //BRUTE FORCE O(N^2)
        int n=baskets.size();
        int cnt=0;
        vector<int>isEmpty(n,1);
        for(auto it:fruits){
            for(int i=0;i<n;i++){
              if(isEmpty[i] and baskets[i]>=it){
                isEmpty[i]=0;
                cnt++;
                break;
              }
            }
        }
        return n-cnt;
    }
};
