class Solution {
public:
    vector<int> partitionLabels(string s) {
         //if a letter exists, all occurrences of it should appear only in 1 part
         //we will store start and end of each letter and then a single loop to determine the parts
         int n=s.size();
         vector<pair<int,int>>v(26,{-1,-1});
         for(int i=0;i<n;i++){
            int index=s[i]-'a';
            if(v[index].first==-1)v[index].first=v[index].second=i;
            else v[index].second=i;
         }
         vector<int>ans;
         int i=0;
         int start=0;
         int end=0;
         while(i<n){
           int index=s[i]-'a'; 
           end=max(end,v[index].second);
           if(i==end){
            ans.push_back(end-start+1);
            start=i+1;
            end=0;
           }
           i++;
         }
        return ans;
    }
};
