# Write a function that transforms a string by alternating the case of alphabetic
# characters only. Non-alphabetic characters remain unchanged and are ignored for
# the purpose of alternation. The first alphabetic character should be lowercase,
# the second uppercase, the third lowercase, and so on.

def string_sculptor(text: str) -> str:
	result = []
	should_be_upper = False  # Start with lowercase

	for char in text:
		# Only alphabetic characters affect the alternation. Spaces are also considered
		if char.isalpha() or char.isspace():
			if should_be_upper:
				result.append(char.upper())
			else:
				result.append(char.lower())
			should_be_upper = not should_be_upper  # Toggle for next alphabetic character
		else:
			result.append(char)  # Non-alphabetic characters are added unchanged

	return ''.join(result)
