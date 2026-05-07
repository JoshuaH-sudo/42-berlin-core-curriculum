import pytest
from medium.py_string_sculptor import string_sculptor


def test_all_lowercase():
    assert string_sculptor("hello") == "hElLo"

def test_mixed_case_with_space():
    assert string_sculptor("Hello World") == "hElLo wOrLd"

def test_numbers_ignored_in_alternation():
    assert string_sculptor("aBc123def") == "aBc123DeF"

def test_special_chars_ignored_in_alternation():
    assert string_sculptor("Python3.9!") == "pYtHoN3.9!"

def test_empty_string():
    assert string_sculptor("") == ""
