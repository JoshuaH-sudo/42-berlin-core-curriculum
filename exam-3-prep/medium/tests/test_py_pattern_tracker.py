import pytest
from medium.py_pattern_tracker import pattern_tracker


def test_consecutive_digits():
    assert pattern_tracker("123") == 2

def test_digits_with_letter():
    assert pattern_tracker("12a34") == 2

def test_descending_digits():
    assert pattern_tracker("987654321") == 0

def test_ascending_sequence():
    assert pattern_tracker("01234567") == 7

def test_only_letters():
    assert pattern_tracker("abc") == 0

def test_alternating_digits_letters():
    assert pattern_tracker("1a2b3c4") == 0

def test_repeated_digits():
    assert pattern_tracker("112233") == 2
