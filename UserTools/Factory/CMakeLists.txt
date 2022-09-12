file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

pbuilder_library(
        TARGET Factory
        SOURCES ${SRC}
        PROJECT_LIBRARIES DummyTool
        PUBLIC_EXTERNAL_LIBRARIES hk-ToolFrameworkCore::ToolFrameworkCore
        PRIVATE_EXTERNAL_LIBRARIES ${PRIVATE_EXT_LIBS}
)

pbuilder_install_headers(${HEADERS})
