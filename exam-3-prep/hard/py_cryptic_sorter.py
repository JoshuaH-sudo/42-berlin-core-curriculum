# Write a function that sorts a list of strings according to multiple criteria:
# 1. Primary sort: By string length (shortest first)
# 2. Secondary sort: ASCII order, except letters are compared case-insensitively
#    (for strings of same length)
# 3. Tertiary sort: By number of vowels (ascending, for same length and lexically equal)
# 4. Equal strings will appear in the same order as in the input list.
from functools import cmp_to_key

def cryptic_sorter(strings: list[str]) -> list[str]:
    strings.sort(key=len)
    print([(len(s), s.lower(), sum(1 for char in s if char.lower() in 'aeiou')) for s in strings])
    strings.sort(key=lambda s: (len(s), s.lower(), sum(1 for char in s if char.lower() in 'aeiou')))
    return strings

if __name__ == "__main__":
    print(cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]))