class Solution {
public:
    // Comparator function to sort pairs by frequency (static)
    static bool comparator(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; // Sort in descending order of frequency
    }

    string frequencySort(string s) {
        int n = s.length();
        
        // Initialize a vector of pairs, where each index corresponds to a character's frequency
        vector<pair<char, int>> vec(123);  // 123 for ASCII characters

        // Count the frequency of each character
        for (char ch : s) {
            vec[ch].first = ch;               // Store the character
            vec[ch].second++;                 // Increment the frequency
        }

        // Sort the vector based on the frequency using the comparator
        sort(vec.begin(), vec.end(), comparator);  // No need for object instance

        // Build the result string
        string res = "";
        for (int i = 0; i <= 122; i++) {
            if (vec[i].second > 0) {  // Ignore characters with 0 frequency
                string temp = string(vec[i].second, vec[i].first); // Repeat char by frequency
                res += temp;  // Append the character `freq` times
            }
        }

        return res;  // Return the result string
    }
};
