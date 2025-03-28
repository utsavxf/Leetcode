class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        if(sentence[0]!=sentence[n-1])return false;
        //now we have to seperate words
        char last;
           for (int i = 1;i<n;i++) {
            if (sentence[i] == ' ') {
                last = sentence[i - 1];  // Store the last character of the word
            } else if (sentence[i - 1] == ' ' && sentence[i]!= last) {
                return false;
            }
        }
        return true;
    }
};
