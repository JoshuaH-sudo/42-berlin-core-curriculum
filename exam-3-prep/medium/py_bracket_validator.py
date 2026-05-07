# Write a function that checks if brackets [], parentheses (), and braces {} are properly
# balanced and correctly nested in a string. All others characters are ignored.
# Return True if balanced, False otherwise

def bracket_validator(s: str) -> bool:
    stack = []
    pairs = {')': '(', ']': '[', '}': '{'}
    
    for char in s:
        if char in pairs.values():
            stack.append(char)
        elif char in pairs.keys():
            if not stack or stack[-1] != pairs[char]:
                return False
            stack.pop()
    
    return len(stack) == 0