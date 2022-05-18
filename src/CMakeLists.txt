######################
#   Core             #
######################
# If there were other libraries in this package on which this library depends, then they would be put in this variable
set(PACKAGE_LIBS )

set (HEADERS
        hello.h
        )

set (SOURCES
        hello.cpp
        )

#configure_file( PThetaVersion.cxx.in ${CMAKE_CURRENT_BINARY_DIR}/PThetaVersion.cxx )

##################################################

## no headers since LinkDef only contains std objects
#set(dict_headers
#        TIntervalList.h
#        )
#
#set(CORE_LINKDEF_HEADERFILE LinkDef/CoreLinkDef.h)
#set(CORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/libPTCore_rdict.pcm)
#set(CORE_DICT_ROOTMAPFILE ${CMAKE_CURRENT_BINARY_DIR}/libPTCore.rootmap)
#set(sources ${sources} ${CMAKE_CURRENT_BINARY_DIR}/G__PTCore.cxx)

#ROOT_GENERATE_DICTIONARY(G__PTCore ${dict_headers} LINKDEF ${CORE_LINKDEF_HEADERFILE})
#pbuilder_install_files(${LIB_INSTALL_DIR} ${CORE_DICT_PCMFILE} ${CORE_DICT_ROOTMAPFILE})

# ###########
# # Library #
# ###########

pbuilder_library(
        TARGET MyHKLib
        SOURCES ${SOURCES}
        PROJECT_LIBRARIES ${PACKAGE_LIBS}
        PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
        PRIVATE_EXTERNAL_LIBRARIES ${PRIVATE_EXT_LIBS}
)

pbuilder_install_headers(${HEADERS})
