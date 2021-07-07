class Solution {
public:
    bool static cmp(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second) return (a.first < b.first);
        return (a.second > b.second);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> res;
        vector<pair<string, int>> helper;
        /*priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto x : mp){
            pq.push_back(x);
        }
        for(int i = 0; i < words.size(); i++){
            string str = pq.top().first;
            pq.pop();
            res.push_back(str);
        }
        */
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto x : mp){
            helper.push_back(x);
        }
        sort(helper.begin(), helper.end(), cmp);
        for(int i = 0; i < k && i < helper.size(); i++){
            res.push_back(helper[i].first);
        }
        return res;
    }
};