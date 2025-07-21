class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(n<3) return s;

        string result="";

        char prev2=s[0];
        char prev1=s[1];
        result+=prev2;
        result+=prev1;
        for(int i=2;i<n;i++){
            char curr=s[i];
            if(curr==prev1 and prev1==prev2)continue;
            result+=curr;
            prev2=prev1;
            prev1=curr;
        }

        return result;
    }
};
