class Solution:
    def maxVowels(self, s, k):
        vowels = set('aeiou')  # Set of vowels for quick lookup
        max_vowels = 0
        current_vowels = 0

        # Initialize the first window of size k
        for i in range(k):
            if s[i] in vowels:
                current_vowels += 1

        max_vowels = current_vowels

        # Slide the window across the string
        for i in range(k, len(s)):
            if s[i - k] in vowels:  # Remove the character that's sliding out of the window
                current_vowels -= 1
            if s[i] in vowels:  # Add the new character that's sliding into the window
                current_vowels += 1
            max_vowels = max(max_vowels, current_vowels)

        return max_vowels
