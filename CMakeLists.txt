# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME MyHKLib)
set(PROJECT_VERSION 2.4.0)


project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

set(default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

list(APPEND CMAKE_MODULE_PATH
        $ENV{HK_PILOT_DIR}/cmake
        )
include(PackageBuilder)

pbuilder_prepare_project()

include_directories(BEFORE
        ${PROJECT_SOURCE_DIR}/src
        )

add_subdirectory(src)

pbuilder_component_install_and_export(
        COMPONENT Library
        LIBTARGETS MyHKLib
)

#configure_file(this_myhklib.sh.in this_myhklib.sh)
#pbuilder_install_files(${BIN_INSTALL_DIR} ${CMAKE_CURRENT_BINARY_DIR}/this_ptheta.sh)

configure_file(${PROJECT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake @ONLY)
pbuilder_do_package_config()

add_custom_target(install_${PROJECT_NAME}
        "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install
        COMMENT "Installing ${PROJECT_NAME}")
