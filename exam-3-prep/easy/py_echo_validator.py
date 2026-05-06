# Write a function that checks if a string is a palindrome, 
# ignoring spaces and case, only consider alphabetic characters for the comparison. 
# The function should return True if the string is a palindrome, and False otherwise.

def echo_validator(text: str) -> bool:
    cleaned_text = ''.join(char.lower() for char in text if char.isalpha())
    return cleaned_text == cleaned_text[::-1]