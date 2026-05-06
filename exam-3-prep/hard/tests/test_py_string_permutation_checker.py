from ..py_string_permutation_checker import string_permutation_checker


class TestStringPermutationChecker:
    def test_basic_permutation(self):
        assert string_permutation_checker("abc", "bca") is True

    def test_different_strings(self):
        assert string_permutation_checker("abc", "def") is False

    def test_anagram_words(self):
        assert string_permutation_checker("listen", "silent") is True

    def test_single_character_difference(self):
        assert string_permutation_checker("hello", "bello") is False

    def test_empty_strings(self):
        assert string_permutation_checker("", "") is True

    def test_one_empty_string(self):
        assert string_permutation_checker("a", "") is False

    def test_case_sensitive(self):
        assert string_permutation_checker("Abc", "abc") is False

    def test_with_spaces(self):
        assert string_permutation_checker("a gentleman", "elegant man") is True
