class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26,0);
        int ans = 0;

        for(int i=0; i<word.size(); i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());

        for(int i=0; i<freq.size(); i++){
            ans += ((i/8)+1) * freq[i];
        }

        return ans;
    }
};