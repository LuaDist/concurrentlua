# Copyright (C) 2007-2012 LuaDist.
# Created by Peter Drahoš
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

PROJECT(concrrentlua C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
INCLUDE(cmake/dist.cmake)
INCLUDE(lua)

# Build
INSTALL_LUA_MODULE(cldaemon src/cldaemon/cldaemon.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def)
INSTALL_LUA_MODULE(cltime src/cltime/cltime.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def)

# Install all files and documentation
INSTALL_LUA_EXECUTABLE( clpmd src/clpmd/clpmd )
INSTALL_EXAMPLE ( samples/ )
INSTALL_TEST ( test/ )
INSTALL_DOC ( doc/ )
INSTALL_DATA ( README LICENSE )

# Not using macros, instead using direct install
INSTALL (DIRECTORY src/concurrent DESTINATION ${INSTALL_LMOD} COMPONENT Runtime PATTERN "Makefile" EXCLUDE)
