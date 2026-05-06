from easy.py_mirror_matrix import mirror_matrix


def test_mirror_matrix_3x2():
    assert mirror_matrix([[1, 2, 3], [4, 5, 6]]) == [[3, 2, 1], [6, 5, 4]]

def test_mirror_matrix_2x3():
    assert mirror_matrix([[1, 2], [3, 4], [5, 6]]) == [[2, 1], [4, 3], [6, 5]]

def test_mirror_matrix_single_element():
    assert mirror_matrix([[7]]) == [[7]]

def test_mirror_matrix_single_row():
    assert mirror_matrix([[1, 2, 3, 4]]) == [[4, 3, 2, 1]]

def test_mirror_matrix_negative_numbers():
    assert mirror_matrix([[-1, -2], [-3, -4]]) == [[-2, -1], [-4, -3]]
