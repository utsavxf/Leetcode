class Solution {
public:

    bool isMatch(string a,string b){
        /*ok so what to we have to see
        we have x from string a and y from string b
        ->if mapping of x doesn't exists then check whether y is already mapped to something or not if it is return false else map x to y
        ->if mapping of x exists then check whether m1[x]=y or not
        */
        if(a.size()!=b.size())return false;
        unordered_map<char,char>m1,m2;
        for(int i=0;i<a.size();i++){
           char x=a[i];
           char y=b[i];
           if(m1.find(x)==m1.end()){
              if(m2.find(y)!=m2.end())return false;
              else{
                m1[x]=y;
                m2[y]=x;
              }
           }else if(m1[x]!=y)return false;  
        }
        return true;
    }


    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>result;
        for(auto it:words){
            if(isMatch(it,pattern))result.push_back(it);
        }
        return result;   
    }
};
