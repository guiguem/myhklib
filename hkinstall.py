from hkpilot.utils.cmake import CMake


class MyHKLib(CMake):

    def __init__(self, path):
        super().__init__(path)
        self._package_name = "MyHKLib"
        self._package_version = "2.4.0"
