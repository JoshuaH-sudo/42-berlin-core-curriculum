from .py_shadow_merge import shadow_merge


def test_interleaved_sorted_lists():
    assert shadow_merge([1, 3, 5], [2, 4, 6]) == [1, 2, 3, 4, 5, 6]


def test_already_ordered_ranges():
    assert shadow_merge([1, 2, 3], [4, 5, 6]) == [1, 2, 3, 4, 5, 6]


def test_single_element_and_longer_list():
    assert shadow_merge([1], [2, 3, 4]) == [1, 2, 3, 4]


def test_empty_left_list():
    assert shadow_merge([], [1, 2, 3]) == [1, 2, 3]


def test_duplicates_are_preserved():
    assert shadow_merge([1, 1, 2], [1, 3, 3]) == [1, 1, 1, 2, 3, 3]