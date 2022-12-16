# My HK Library

This repository can be used as a template for creating other HK packages.
It contains all the necessary files and information for:
- integration in HK installation framework,
- basic dependencies with ToolFrameworkCore and WCSim,
- Continuous Integration and Docker support,
- package exportation via CMake.

Note that the CI of this template are not guaranteed to work if used outside the hyperk organisation.

## Defining your own repo

Below, we assume you have already install ``hk-pilot`` and the dependencies you plan to use in your future package:
as currently implemented, the ``myhklib`` relies on ToolFrameworkCore and WCSim (and their dependencies).
Therefore, make sure you have them installed!

To create a new repo:
- use the "Use this template" button, instead of forking and choose the name of your package e.g. `mypackage`,
- change the project name in ``CMakeLists.txt`` to `mypackage`,
- change the `self._package_name` in ``hkinstall.py`` to `mypackage` (same for the name of the class),
- rename the `myhklibConfig.cmake` to e.g. `mypackageConfig.cmake`,
- start a first compilation using ``hkp install mypackage``
- if successful, you can start editing the source code (add more source files, applications...) and the CMake files.

## How does CMake work here?

We rely on CMake macros defined by the `hk-pilot` and we recommend not to introduce new ones that could prevent the expected integration in HK installation framework like installing files elsewhere, removing the `install` target.
If there is a feature you wish you had, please contact the HK software dev team.

As this template package is intended for the dev of ToolFrameworkCore tools, we have implemented three folders:
- `DataModel`: containing the DataModel and some utilities
- `UserTools`: containing all the tools useable in ToolFrameworkCore,
- `src`: containing the applications.

You can change this structure as you see fit: especially, if you don't need ToolFrameworkCore, you can remove the DataModel and UserTools folders.
You can also add more folders containing source code (or just more source files). 
For this:
- add the files in e.g. a `src` folder
- add the folder in the main ``CMakeLists.txt`` file using the `add_subdirectory` instruction
- add a `CMakeLists.txt` file similar to the one in `DataModel` folder. In this file:
  - add the name of the files in the `SRC` and `HEADERS` variables,
  - change the folder in the `include_directoris` instruction
  - change the name of the ``TARGET`` library,
- try the compilation!

## Continuous Integration

If you'd like to use the Continuous Integration, you would need to :
- have the new repo in the hyperk organisation (otherwise you can not access hyperk resources correctly). If so, you would have to ask a hyperk organisation owner to create the repo for you!
- ask a hyperk owner to add the repository to the allowed repositories: https://github.com/orgs/hyperk/packages/container/hk-meta-externals/settings
- add a SSH key in the `Actions secrets` for this repo