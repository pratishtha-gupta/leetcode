class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string,vector<string>> mp;
      for(auto it:strs)
      {
         string key = it;
         sort(key.begin(),key.end());
         mp[key].push_back(it);
      }
       vector<vector<string>> result;
        for (auto pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};