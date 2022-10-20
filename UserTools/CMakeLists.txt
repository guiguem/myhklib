
include_directories(BEFORE
        ${PROJECT_SOURCE_DIR}/UserTools
        ${PROJECT_SOURCE_DIR}/UserTools/Factory
        ${PROJECT_SOURCE_DIR}/UserTools/DummyTool
        ${PROJECT_SOURCE_DIR}/UserTools/WCSimTool
        )

# Some hack to build the ToolChain library whose source files exist in the ToolFrameworkCore library
set (TOOLCHAIN_SRC ${ToolFrameworkCore_SRC_DIR}/ToolChain.cpp)
pbuilder_library(
        TARGET ToolChain
        SOURCES ${TOOLCHAIN_SRC}
        PROJECT_LIBRARIES Factory DataModel
        PUBLIC_EXTERNAL_LIBRARIES ToolFrameworkCore::ToolFrameworkCore
        PRIVATE_EXTERNAL_LIBRARIES ${PRIVATE_EXT_LIBS}
)
# End of hack

add_subdirectory(DummyTool)
add_subdirectory(Factory)
add_subdirectory(WCSimTool)

pbuilder_component_install_and_export(
        COMPONENT Library
        LIBTARGETS DataModel DummyTool WCSimTool Factory ToolChain
)