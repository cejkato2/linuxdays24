import unittest
import doctest
import sys

class ldmodule_tests(unittest.TestCase):
    def runTest(self):
        try:
            import ldpymod
        except ImportError as e:
            self.fail(str(e))

        self.assertEqual(ldpymod.hello(), ("Hello world!", 1234))

        self.assertEqual(ldpymod.FMT_JSON, 2)

        exc = ldpymod.GeneralError()
        exc2 = ldpymod.SpecificError()

        try:
            raise exc2
        except ldpymod.GeneralError:
            pass


