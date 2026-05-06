from .py_whisper_cipher import whisper_cipher


def test_basic_shift():
    assert whisper_cipher("hello", 3) == "khoor"


def test_preserves_case_and_punctuation():
    assert whisper_cipher("Hello World!", 1) == "Ifmmp Xpsme!"


def test_wraps_lowercase_letters():
    assert whisper_cipher("xyz", 3) == "abc"


def test_wraps_uppercase_and_keeps_digits():
    assert whisper_cipher("ABC123def", 5) == "FGH123ijk"


def test_empty_string():
    assert whisper_cipher("", 10) == ""