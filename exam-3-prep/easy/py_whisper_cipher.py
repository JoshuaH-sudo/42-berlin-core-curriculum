# Write a function that creates a simple cipher by shifting letters in a sting
# by a given amount. Non-alphabetic characters should remain unchanged.

def whisper_cipher(text: str, shift: int) -> str:
    result = ''
    for c in text:
        if c.isalpha():
            if c.islower():
                result += chr((ord(c) - ord('a') + shift) % 26 + ord('a'))
            else:
                result += chr((ord(c) - ord('A') + shift) % 26 + ord('A'))
        else:
            result += c
    return result

if __name__ == "__main__":
    print(whisper_cipher("hello123", 3))