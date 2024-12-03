class Solution {
public:
bool isIsomorphic(string s, string t) 
{
    int ns = s.size();
    
    // Initialize seen array to map characters to their respective mappings
    vector<char> seen(256, 0);  // 256 to cover all ASCII characters
    
    // Iterate through each character in the strings
    for (int i = 0; i < ns; i++) 
    {
        char ch = s[i];

        // If the character in s has not been seen yet
        if (seen[ch] == 0) 
        {
            for (int j = 0; j < 256; j++) 
            {
                // If any character is already mapped to t[i], return false
                if (seen[j] == t[i])
                    return false;
            }
            seen[ch] = t[i];  // Map s[i] to t[i]
        } 
        else if (seen[ch] != t[i]) 
        {
            // If the character in s[i] is already mapped to a different character
            return false;
        }
    }
    return true;
}
};