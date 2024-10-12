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

class ldobject_tests(unittest.TestCase):
    def runTest(self):
        import ldpymod

        o = ldpymod.LinuxDaysObj()

        with self.assertRaises(TypeError):
            o.area("abc")
        with self.assertRaises(TypeError):
            o.area(["2, 2, 3"])

        self.assertEqual(o.area([(2, 2, 3)]), 1.984313483298443)
        self.assertEqual(o.area([(3, 2, 4)]), 2.9047375096555625)
        self.assertEqual(o.area([(2, 2, 3), (3, 2, 4)]), 4.889050992954005)
        self.assertEqual(o.area([(2, 2, 3), (3, 2, 4)], 10, 10, 10), 48890.50992954006)

