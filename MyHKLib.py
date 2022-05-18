from hkpilot.utils.cmake import CMake

import inspect
import os


class MyHKLib(CMake):
    _package_name = "MyHKLib"
    _package_version = "2.4.0"

    def __init__(self):
        self._path = os.path.relpath(inspect.getfile(self.__class__))
