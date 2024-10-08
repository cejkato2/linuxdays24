from setuptools import setup, Extension
import os

SRC_PATH = os.path.relpath(os.path.join(os.path.dirname(__file__), ".", "src"))

name = 'ldpymod'
version = '0.0.1'
release = version
description = 'Python extension for linuxdays.'
long_description = 'The pytrap module is a native Python extension that allows for writing NEMEA modules in Python.'
author = 'Tomas Cejka'
author_email = 'cejkat@cesnet.cz'
maintainer = 'Tomas Cejka'
maintainer_email = 'cejkat@cesnet.cz'

ldpymodmodule = Extension('ldpymod',
                    sources = ['src/ldpymod.c', 'src/object.c'],
                    libraries = [])

try:
    from sphinx.setup_command import BuildDoc
    cmdclass = {'build_sphinx': BuildDoc}
    command_options = {'build_sphinx': {
               'project': ('setup.py', name),
               'version': ('setup.py', version),
               'release': ('setup.py', release),
               'source_dir': ('setup.py', 'docs'),
               'build_dir': ('setup.py', 'dist/doc/')}
               }
except:
    cmdclass = {}
    command_options = {}

setup(name = name,
       version = version,
       description = description,
       long_description = long_description,
       author = author,
       author_email = author_email,
       maintainer = maintainer,
       maintainer_email = maintainer_email,
       url = 'https://github.com/cejkato2/ldpymod',
       license = 'BSD',
       test_suite = "test",
       platforms = ["Linux"],
       classifiers = [
              'Development Status :: 4 - Beta',
              'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
              'Operating System :: POSIX :: Linux',
              'Programming Language :: C',
              'Programming Language :: Python :: 3',
              'Programming Language :: Python :: 3.6',
              'Programming Language :: Python :: Implementation :: CPython',
              'Topic :: Software Development :: Libraries',
       ],
       ext_modules = [ldpymodmodule],
       packages = ["ldpymod"],
       package_dir={ "": SRC_PATH, },
       # sphinx:
       cmdclass=cmdclass,
       # these are optional and override conf.py settings
       command_options=command_options,
       )


