#######################################################################
#
# medInria
#
# Copyright (c) INRIA 2013. All rights reserved.
# See LICENSE.txt for details.
# 
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#######################################################################

project(dtkItkLogForwarder)

# find dtk
find_package(dtk REQUIRED)
include(${dtk_USE_FILE})

# find itk
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(DTKLOGFORWARDER_HEADERS
  itkLogForwarder.h
  dtkItkLogForwarderExport.h)

set(DTKLOGFORWARDER_SOURCES
  itkLogForwarder.cpp)

add_library(${PROJECT_NAME} SHARED
  ${DTKLOGFORWARDER_HEADERS}
  ${DTKLOGFORWARDER_SOURCES})

target_link_libraries(${PROJECT_NAME}
  dtkCore dtkLog
  ${ITK_LIBRARIES}
  ${QT_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
