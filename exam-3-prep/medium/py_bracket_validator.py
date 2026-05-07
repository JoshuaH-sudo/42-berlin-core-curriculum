# Write a function that checks if brackets [], parentheses (), and braces {} are properly
# balanced and correctly nested in a string. All others characters are ignored.
# Return True if balanced, False otherwise

def bracket_validator(s: str) -> bool:
    stack = []
    # Maps each closing bracket to its expected opening counterpart
    pairs = {')': '(', ']': '[', '}': '{'}
    
    for char in s:
        if char in pairs.values():
            # Opening bracket — push onto stack to track what needs closing
            stack.append(char)
        elif char in pairs.keys():
            # Closing bracket — check the top of the stack matches the expected opener.
            # If the stack is empty there's nothing to close, or if the top doesn't match
            # the expected opener the brackets are incorrectly nested → invalid.
            if not stack or stack[-1] != pairs[char]:
                return False
            stack.pop()
        # Any other character is ignored per the problem spec
    
    # If the stack is empty all openers were matched and closed — valid.
    # A non-empty stack means unclosed opening brackets remain → invalid.
    return len(stack) == 0
