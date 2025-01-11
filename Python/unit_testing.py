import unittest

class TestExample(unittest.TestCase):
    """Unit test example."""
    def setUp(self):
        """Test fixture setup: called just before each test case."""
        print("\n\tHello from setUp !")

    def tearDown(self):
        """Test fixture teardown: called just after each test case."""
        print("\tHello from tearDown !")

    def testAdd(self): # any test case name has to start with "test"
        """Test case that verifies calculation is correct."""
        assert 1 + 1 == 2, "wrong calculation"
        print("\t\tHello from testAdd !")
        
    def testDivisionByZero(self):
        """Test case that verifies an exception is raised."""
        with self.assertRaises(ZeroDivisionError):
            1 / 0
        print("\t\tHello from testDivisionByZero !")
