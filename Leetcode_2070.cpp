class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans;
        sort(items.begin(),items.end());
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        for(int i=0;i<queries.size();i++){
            int maxi=0;
            int s=0,e=items.size()-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(items[mid][0]<=queries[i]){
                    maxi=items[mid][1];
                    s=mid+1;
                }
                else if(items[mid][0]>queries[i]){
                    e=mid-1;
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
