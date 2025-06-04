class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)return word;
        int n=word.size();
        unordered_map<int,int>m;
        string result;
        int maxLen=n-numFriends+1;
        
        char maxWord='a';
        for(auto it:word)
        if(it>maxWord)maxWord=it;
        
        for(int i=0;i<n;i++){
            int currScore=0;
            string curr="";
            if(word[i]==maxWord){
                bool crossed=false;
                for(int j=i;j<min(i+maxLen,n);j++){
                    curr+=word[j];
                    currScore+=word[j];
                    int len=j-i+1;
                    if(crossed==true){
                        m[len]=currScore;
                        result=curr;
                    }
                    else{
                    if(currScore>m[len]){
                        m[len]=currScore;
                        result=curr;
                        crossed=true;
                    }else if(currScore==m[len]){
                        continue;
                    }else break;
                    }
                }
            }
        }
        return result;
        
    }
};
