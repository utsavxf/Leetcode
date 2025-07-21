class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>left(n,1e5);
        vector<int>right(n,1e5);
        
        //for right
        for(int i=0;i<n;i++){
          if(dominoes[i]=='R')right[i]=0;
          else if(dominoes[i]=='L') continue;
          else{
          if(i==0 || right[i-1]==1e5)continue;
          right[i]=right[i-1]+1;
          }
        }

        //for left
        for(int i=n-1;i>=0;i--){
          if(dominoes[i]=='L')left[i]=0;
          else if(dominoes[i]=='R') continue;
          else{
          if(i==n-1 || left[i+1]==1e5)continue;
          left[i]=left[i+1]+1;
          }
        }

        //final state
        string ans="";
        for(int i=0;i<n;i++){
            if(left[i]<right[i])ans+='L';
            else if(left[i]>right[i])ans+='R';
            else ans+='.';
        }

        return ans;

    }
};
