# Copyright (C) 2007-2012 LuaDist.
# Created by Peter Drahoš
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

project ( concrrentlua C )
cmake_minimum_required ( VERSION 2.8 )
include ( cmake/dist.cmake )
include ( lua )

# Build
install_lua_module ( cldaemon src/cldaemon/cldaemon.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def )
install_lua_module ( cltime src/cltime/cltime.c ${CMAKE_CURRENT_SOURCE_DIR}/src/cldaemon/cldaemon.def )

# Install all files and documentation
install_lua_executable ( clpmd src/clpmd/clpmd )
install_example ( samples/ )
install_test ( test/ )
install_doc ( doc/ )
install_data ( README LICENSE )

# Not using macros, instead using direct install
install ( DIRECTORY src/concurrent DESTINATION ${INSTALL_LMOD} COMPONENT Runtime 
  PATTERN "Makefile" EXCLUDE )
