/*
Intuition : Every anagram when sorted read the same word
So, for every word we encounter, let's sort it and see which bucket it belongs to
Examples ; {"eat, "tea"}
If we take, "eat" and sort it, we get "aet" and now we attach the word "eat" to "aet" as it is an anagram of it
We keep repeating this process and once we are done iterating throught the array, we now iterate through the hashmap and push_back the vector that contains all the anagrams for all keys possible.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;
    unordered_map<string, vector<string> > um;
    for(int i = 0; i < strs.size(); i++){
        string sorted = strs[i];
        sort(sorted.begin(), sorted.end());
        um[sorted].push_back(strs[i]);
    }
    for(auto it : um){
        ans.push_back(it.second);
    }
    return ans;
}