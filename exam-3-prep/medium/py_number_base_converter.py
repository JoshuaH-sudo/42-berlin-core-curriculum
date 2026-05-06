# Write a function that converts a number from one base to another.
# Support bases from 2 to 36 inclusive, using digits 0-9 and letters A-Z for values 10-35.
# Return "ERROR" for invalid inputs (base, digits)

def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    # Validate bases
    if from_base < 2 or from_base > 36 or to_base < 2 or to_base > 36:
        return "ERROR"
    
    # Validate that all digits are valid for the from_base
    try:
        for digit in number.upper():
            if base.index(digit) >= from_base:
                return "ERROR"
    except ValueError:
        return "ERROR"
    
    # Convert from from_base to decimal
    decimal = 0
    for i, digit in enumerate(number.upper()[::-1]):
        decimal += base.index(digit) * (from_base ** i)
    
    # Convert from decimal to to_base
    if decimal == 0:
        return "0"
    
    result = ''
    while decimal > 0:
        result = base[decimal % to_base] + result
        decimal //= to_base
    
    return result

if __name__ == "__main__":
    print(number_base_converter("1101", 2, 16))