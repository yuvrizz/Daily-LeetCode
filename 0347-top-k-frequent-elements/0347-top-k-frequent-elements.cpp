class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        vector <pair<int,int>> vec; 

        for(auto x : freq){
            vec.push_back(make_pair(x.second,x.first));
        }

        priority_queue <pair<int,int>> pq(vec.begin(), vec.end());
        vector<int> ans;

        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};