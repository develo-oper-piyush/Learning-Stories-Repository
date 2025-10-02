class Solution {
public:
    string majorityFrequencyGroup(const string &s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;
        
        unordered_map<int, vector<char>> groups;
        for (auto it : freq) {
            char ch = it.first;
            int freq = it.second;
            groups[freq].push_back(ch);
        }
        
        int max_grp_size = 0;
        int max_freq = -1;
        for (auto &p : groups) {
            int freq = p.first;
            int grp_size = (int)p.second.size();
            
            if (grp_size > max_grp_size
                || (grp_size == max_grp_size && freq > max_freq)) {
                max_grp_size = grp_size;
                max_freq = freq;
            }
        }
        
        string ans;
        if (max_freq != -1) {
            for (char ch : groups[max_freq])
                ans.push_back(ch);
        }
        
        return ans;
    }
};
