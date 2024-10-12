import unittest
import doctest
import sys

class ldmodule_tests(unittest.TestCase):
    def runTest(self):
        try:
            import ldpymod
        except ImportError as e:
            self.fail(str(e))

