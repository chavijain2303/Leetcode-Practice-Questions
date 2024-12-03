class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.length();
        int i = 0;
        reverse(s.begin(), s.end()); // Reverse the entire string

        int index = 0; // Index to store the cleaned-up version of the string
        while (i < n) 
        {
            // Skip leading spaces
            while (i < n && s[i] == ' ') 
                i++;
            
            if (i >= n) 
                break;

            // Find the end of the current word
            int start = i;
            while (i < n && s[i] != ' ') 
                i++;

            // Reverse the word
            reverse(s.begin() + start, s.begin() + i);

            // Copy the word to the correct position
            if (index != 0) 
                s[index++] = ' '; // Add a space before the next word
            while (start < i) 
                s[index++] = s[start++];
        }

        s.resize(index); // Remove trailing spaces
        return s;
    }
};
