######################
#   exe             #
######################
# If there were other libraries in this package on which this library depends, then they would be put in this variable
set(PACKAGE_LIBS
        myhklib
        )

set (SOURCES
        main.cxx
        )

# ###########
# # Library #
# ###########

pbuilder_executables(
        SOURCES ${SOURCES}
        PROJECT_LIBRARIES ${PACKAGE_LIBS}
        PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
        PRIVATE_EXTERNAL_LIBRARIES ${PRIVATE_EXT_LIBS}
)

