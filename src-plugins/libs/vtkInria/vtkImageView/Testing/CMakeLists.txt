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

set(KIT ${PROJECT_NAME})

set(${PROJECT_NAME}Tests
  vtkImageViewTest1.cxx
  vtkImageViewTest2.cxx
  vtkImageViewTest3.cxx
  SynchronizedViews3Test.cxx
  )

create_test_sourcelist(Tests ${KIT}CxxTests.cxx
  ${${PROJECT_NAME}Tests}
  )

add_executable(${KIT}CxxTests 
  ${Tests}
  )

target_link_libraries(${KIT}CxxTests 
  ${PROJECT_NAME}
  vtkRendering 
  vtkImaging
  )

foreach (test ${${PROJECT_NAME}Tests})
  get_filename_component(TName ${test} NAME_WE)
  add_test(${TName} ${CXX_TEST_PATH}/${KIT}CxxTests ${TName}) 
endforeach() 
