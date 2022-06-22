# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME MyHKLib)
set(PROJECT_VERSION 2.4.0)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

list(APPEND CMAKE_MODULE_PATH
        $ENV{HK_PILOT_DIR}/cmake
        $ENV{HK_PILOT_DIR}/../myhkdep/install-Darwin_arm64-gcc_13.1.6-python_3.9.13/lib/cmake/MyHKDep
        )
include(HKPackageBuilder)



hkbuilder_prepare_project()

find_package(MyHKDep HINTS $ENV{HK_PILOT_DIR}/../myhkdep/install-Darwin_arm64-gcc_13.1.6-python_3.9.13/lib/cmake/MyHKDep REQUIRED)

include_directories(BEFORE
        ${MyHKDep_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/src
        )

add_subdirectory(src)

pbuilder_component_install_and_export(
        COMPONENT Library
        LIBTARGETS MyHKLib
)
