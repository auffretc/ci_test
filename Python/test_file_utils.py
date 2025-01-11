import os
import unittest
import tempfile
import file_utils

class TestFileUtils(unittest.TestCase):
    """file_utils unit testing."""
    def setUp(self):
        """Test fixture setup: called before each test."""
        _, self.file_first_name = tempfile.mkstemp()
        _, self.file_second_name = tempfile.mkstemp()
        _, self.file_not_found = tempfile.mkstemp()

        with open(self.file_first_name, "w+") as file_first_id:
            file_first_id.write("") # create file with an empty content

        with open(self.file_second_name, "w+") as file_second_id:
            file_second_id.write("foo") # create file with "foo" in it

        os.remove(self.file_not_found)

    def tearDown(self):
        """Test fixture teardown: called after each test."""
        os.remove(self.file_first_name)
        os.remove(self.file_second_name)
    
    def testAreSame(self):
        """Test case that verifies the files are identical."""
        assert not file_utils.diff(self.file_first_name, self.file_first_name), "similarity not detected"
    
    def testAreDifferent(self):
        """Test case that verifies the file are not identical."""
        assert file_utils.diff(self.file_first_name, self.file_second_name), "difference not detected"

    def testFirstFileNotFound(self):
        """Test case that verifies the first file is not found."""
        with self.assertRaises(FileNotFoundError):
            file_utils.diff(self.file_not_found, self.file_second_name)

    def testSecondFileNotFound(self):
        """Test case that verifies the second file is not found."""
        with self.assertRaises(FileNotFoundError):
            file_utils.diff(self.file_first_name, self.file_not_found)


if __name__ == "__main__":
    unittest.main(warnings="ignore")
