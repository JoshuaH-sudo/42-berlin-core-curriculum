# Write a function that merges two sorted lists into one sorted list.

def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
    merged = [*list1, *list2]

    return sorted(merged)

if __name__ == "__main__":
    print(shadow_merge([1, 3, 5], [2, 4, 6]))