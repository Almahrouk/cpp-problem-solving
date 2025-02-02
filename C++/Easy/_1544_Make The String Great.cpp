class Solution {
public:
    std::string makeGood(std::string s) {
        int endPosition = 0; // Represents the end position of the modified string
        char charArray[s.size()]; // Convert the string to a character array

        // Convert the string to a character array
        for (int i = 0; i < s.size(); ++i) {
            charArray[i] = s[i];
        }

        // Loop through each character in the string
        for (int currentPosition = 0; currentPosition < s.size(); currentPosition++) {
            // Check if the current character can be removed
            if (endPosition > 0 && abs(charArray[currentPosition] - charArray[endPosition - 1]) == 32)
                endPosition--; // Decrement the end position if the current character can be removed
            else {
                // Otherwise, keep the current character and increment the end position
                charArray[endPosition] = charArray[currentPosition];
                endPosition++;
            }
        }

        // Convert the modified character array to a string and return only the valid portion
        return std::string(charArray, charArray + endPosition);
    }
};