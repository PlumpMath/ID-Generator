# set version
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "3")
SET(COMPLETE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
SET(PROJECT_VERSION ${COMPLETE_VERSION})
PROJECT(idgen${PROJECT_VERSION})

###########################################################
# CMake setting

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

SET(CMAKE_COLOR_MAKEFILE ON)

#############################################################
# user-changeable settings which can be used to customize
# layout of ID Generator installation
# (default values are platform-specific)

SET (IDGEN_BIN_SUBDIR     ${DEFAULT_BIN_SUBDIR}     CACHE STRING "Subdirectory where executables will be installed")

# mark *_SUBDIR variables as advanced as this is not something
# that an average user would use
MARK_AS_ADVANCED (IDGEN_BIN_SUBDIR)

# full paths for the installation
SET (IDGEN_BIN_DIR     ${IDGEN_BIN_SUBDIR})




###########################################################
# process subdirs

SUBDIRS(src)

#############################################################
# install stuff

#INSTALL (TARGETS idgen RUNTIME DESTINATION bin)
