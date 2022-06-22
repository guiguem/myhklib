# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)


set(PROJECT_NAME myhklib)

list(APPEND CMAKE_MODULE_PATH
        $ENV{HK_PILOT_DIR}/cmake
        )
include(GetVersionGit)
MESSAGE("Preparing project ${PROJECT_NAME} version ${${PROJECT_NAME}_GIT_TAG}" )
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})
include(HKPackageBuilder)
hkbuilder_prepare_project()

find_package(MyHKDep  REQUIRED)
list( APPEND PUBLIC_EXT_LIBS MyHKDep::MyHKDep)

include_directories(BEFORE
        ${PROJECT_SOURCE_DIR}/src/library
        )

add_subdirectory(src)

pbuilder_component_install_and_export(
        COMPONENT Library
        LIBTARGETS myhklib
)
