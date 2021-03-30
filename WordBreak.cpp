/*
139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for( string str : wordDict ){
            dict.insert(str);
        }
        int size = s.size(); 
        //bool dp[size + 1] = {false};
        vector<bool> dp(size+1,false);
        dp[0] = true;
        
        for(int len =1; len<=size ; len++ ){
            for(int i=0 ; i<len ; i++){
                if( dp[i] && ( dict.find(s.substr(i,len-i))!=dict.end() ) ) {
                    dp[len] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};