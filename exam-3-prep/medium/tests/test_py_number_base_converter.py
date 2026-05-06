from ..py_number_base_converter import number_base_converter


class TestNumberBaseConverter:
    """Test cases for number_base_converter function"""
    
    def test_binary_to_decimal(self):
        """Test converting binary to decimal"""
        assert number_base_converter("1010", 2, 10) == "10"
    
    def test_hex_to_decimal(self):
        """Test converting hexadecimal to decimal"""
        assert number_base_converter("FF", 16, 10) == "255"
    
    def test_decimal_to_hex(self):
        """Test converting decimal to hexadecimal"""
        assert number_base_converter("255", 10, 16) == "FF"
    
    def test_decimal_to_binary(self):
        """Test converting decimal to binary"""
        assert number_base_converter("123", 10, 2) == "1111011"
    
    def test_base36_to_decimal(self):
        """Test converting base36 to decimal"""
        assert number_base_converter("Z", 36, 10) == "35"
    
    def test_decimal_to_base36(self):
        """Test converting decimal to base36"""
        assert number_base_converter("35", 10, 36) == "Z"
    
    def test_invalid_base_too_low(self):
        """Test error handling for base below 2"""
        assert number_base_converter("123", 1, 10) == "ERROR"
    
    def test_invalid_digit_for_base(self):
        """Test error handling for invalid digit in given base"""
        assert number_base_converter("G", 16, 10) == "ERROR"
