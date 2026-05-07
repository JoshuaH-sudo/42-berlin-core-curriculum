# Write a function that rotates an array to the right by k positions, 
# rotating right by k means the last k elements move to the front.

def twist_sequence(arr: list[int], k: int) -> list[int]:
	if not arr:
		return arr  # Handle empty array
	k = k % len(arr)  # Handle cases where k is greater than array length
	return arr[-k:] + arr[:-k]  # Take the last k elements and concatenate with the rest

if __name__ == "__main__":
	print(twist_sequence([1, 2, 3, 4, 5], 2))  # Output: [4, 5, 1, 2, 3]
	print(twist_sequence([1, 2, 3], 4))        # Output: [3, 1, 2]
	print(twist_sequence([], 3))               # Output: []
