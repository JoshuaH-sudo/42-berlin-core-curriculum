from ..py_cryptic_sorter import cryptic_sorter


def test_mixed_lengths():
    assert cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]) == [
        "cat",
        "dog",
        "apple",
        "banana",
        "elephant",
    ]


def test_case_insensitive_secondary_sort():
    assert cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]) == ["aaa", "AAA", "bbb", "BBB"]


def test_same_and_different_lengths():
    assert cryptic_sorter(["hello", "world", "hi", "test"]) == ["hi", "test", "hello", "world"]


def test_empty_list():
    assert cryptic_sorter([]) == []


def test_single_empty_string():
    assert cryptic_sorter([""]) == [""]


def test_single_element():
    assert cryptic_sorter(["hello"]) == ["hello"]


def test_all_same_length_no_vowels():
    # all length 3, no vowels — sorted alphabetically case-insensitive
    assert cryptic_sorter(["zzz", "bbb", "mmm"]) == ["bbb", "mmm", "zzz"]


def test_tertiary_vowel_sort():
    # same length, same case-insensitive lex order — sort by vowel count ascending
    # "aaa" has 3 vowels, "bbb" has 0 — but different words; use same-word variants
    # "bcd" = 0 vowels, "bce" = 1 vowel, same length, same lower: "bcd" < "bce" alphabetically
    # use strings equal case-insensitively: not possible with different vowel counts unless same letters
    # use: "xyz" (0 vowels) vs "xYz" (0 vowels) — same; test tertiary with identical lowercased strings
    # "aab" (2 vowels) vs "AAb" (2 vowels) — already covered by case test
    # Direct tertiary: strings that differ only in vowel count at same length
    # "cbz" (0 vowels) and "abz" differ alphabetically, so tertiary won't trigger
    # Construct: length=3, lower equal => same string differing by case only has same vowel count
    # Tertiary only fires when len and lower are equal — i.e. same letters, different case
    # "aaa" (3 vowels) vs "AAA" (3 vowels): same tertiary, stable order preserved
    result = cryptic_sorter(["aaa", "AAA"])
    assert result == ["aaa", "AAA"]  # stable: original order preserved


def test_all_same_string():
    assert cryptic_sorter(["hi", "hi", "hi"]) == ["hi", "hi", "hi"]


def test_numbers_and_special_chars():
    # digits and symbols have no vowels; sorted by length then ASCII order
    assert cryptic_sorter(["123", "!!", "a"]) == ["a", "!!", "123"]


def test_mixed_case_alphabetical():
    # same length, case-insensitive alpha order: "apple" < "Zebra" (a < z)
    assert cryptic_sorter(["Zebra", "apple"]) == ["apple", "Zebra"]


def test_already_sorted():
    assert cryptic_sorter(["a", "bb", "ccc"]) == ["a", "bb", "ccc"]


def test_reverse_sorted_input():
    assert cryptic_sorter(["ccc", "bb", "a"]) == ["a", "bb", "ccc"]
