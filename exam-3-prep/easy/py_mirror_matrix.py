#Write a function that mirrors a 2D matrix horizontally by reversing each row.

def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    for row in matrix:
        row.reverse()
    return matrix
