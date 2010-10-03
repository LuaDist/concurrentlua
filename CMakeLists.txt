# Copyright (C) 2007-2009 LuaDist.
# Created by Peter Drahoš
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

PROJECT(concrrentlua C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
INCLUDE(dist.cmake)

# Build
ADD_LUA_MODULE(cldaemon src/cldaemon/cldaemon.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def)
ADD_LUA_MODULE(cltime src/cltime/cltime.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def)

# Install all files and documentation
INSTALL (TARGETS cldaemon cltime DESTINATION ${INSTALL_CMOD})
INSTALL (PROGRAMS src/clpmd/clpmd DESTINATION ${INSTALL_BIN})
INSTALL (DIRECTORY src/concurrent DESTINATION ${INSTALL_LMOD} PATTERN "Makefile" EXCLUDE)
INSTALL (DIRECTORY samples/ DESTINATION ${INSTALL_EXAMPLE})
INSTALL (DIRECTORY test/ DESTINATION ${INSTALL_TEST})
INSTALL (DIRECTORY doc/ DESTINATION ${INSTALL_DOC})
INSTALL (FILES README LICENSE NEWS DESTINATION ${INSTALL_DATA})

