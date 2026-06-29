class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
          int match_count = 0;
            for (const std::string& pattern : patterns) 
            {
                if (word.find(pattern) != string::npos) {
                     match_count++;
                 }
             }
    return match_count;
    }
};
