# Write a function that determines if two strings are permutations of each other.
# Two strings are permutations if they contain the same characters with the same frequencies.

def string_permutation_checker(s1: str, s2: str) -> bool:
    s1_chars = {}
    s2_chars = {}

    for char in s1:
        if not s1_chars.get(char):
            s1_chars.update({
                char: 0
            })
        s1_chars[char] += 1
    for char in s2:
        if not s2_chars.get(char):
            s2_chars.update({
                char: 0
            })
        s2_chars[char] += 1
    
    return s1_chars == s2_chars

if __name__ == "__main__":
    print(string_permutation_checker("abc", "bca"))