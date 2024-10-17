# About this repository

This project contains supplementary materials for my LinuxDays 2024 presentation. It is a brief tutorial for Python extensions written in C/C++.
This repo contains example source codes of a Python module called `ldpymod`.

For the purpose of the presentation, there are several git branches:

* [`01_module`](https://github.com/cejkato2/linuxdays24/tree/01_module) - simple empty Python module written in C
* [`02_function`](https://github.com/cejkato2/linuxdays24/tree/02_function) - Python module with example function `hello()`
* [`03_consts`](https://github.com/cejkato2/linuxdays24/tree/03_consts) - defined named constants of integer type
* [`04_exceptions`](https://github.com/cejkato2/linuxdays24/tree/04_exceptions) - two exception object (one is inherited)
* [`05_object`](https://github.com/cejkato2/linuxdays24/tree/05_object) - Python object
* [`06_object_func`](https://github.com/cejkato2/linuxdays24/tree/06_object_func) - adding methods into the Python object


# Requirements

Python:

- build
- tox
- pytest
- setuptools
- wheel

Environment:

- python-devel (or equivalent)
- compiler

# Build

```
python3 -m build
```

# Installation (example)

```
pip3 install ./dist/ldpymod-0.1-cp312-cp312-linux_x86_64.whl

```

# Content of the repository

* MANIFEST.in - what belongs into package (needed due to header files)
* pyproject.toml - how to build and pack (and test) the package
* src/* - source codes
* docs/* - configuration for sphinx
* linuxdays24-presentation - helpers for the presentation and evaluation
