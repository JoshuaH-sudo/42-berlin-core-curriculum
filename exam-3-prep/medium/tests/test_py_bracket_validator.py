import pytest
from medium.py_bracket_validator import bracket_validator


@pytest.mark.parametrize("s, expected", [
    ("()", True),
    ("()[]{}", True),
    ("(]", False),
    ("([)]", False),
    ("{[]}", True),
    ("hello(world)[test]{code}", True),
    ("((()))", True),
    ("((())", False),
    ("", True),
])
def test_bracket_validator(s, expected):
    assert bracket_validator(s) == expected
