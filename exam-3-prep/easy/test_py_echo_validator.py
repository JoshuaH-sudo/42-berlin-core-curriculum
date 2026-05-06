from py_echo_validator import echo_validator


def test_simple_palindrome():
    assert echo_validator("racecar") == True

def test_palindrome_with_spaces_and_mixed_case():
    assert echo_validator("A man a plan a canal Panama") == True

def test_not_palindrome_with_spaces():
    assert echo_validator("race a car") == False

def test_palindrome_sentence_mixed_case():
    assert echo_validator("Was it a car or a cat I saw") == True

def test_not_palindrome():
    assert echo_validator("hello") == False

def test_palindrome_no_punctuation():
    assert echo_validator("Madam Im Adam") == True

def test_empty_string():
    assert echo_validator("") == False
