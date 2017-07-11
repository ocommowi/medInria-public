################################################################################
#
# medInria
#
# Copyright (c) INRIA 2013 - 2014. All rights reserved.
# See LICENSE.txt for details.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
################################################################################

set(TARGET_NAME medVTKSimpleViewer)

## #############################################################################
## Find required
## #############################################################################

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

## #############################################################################
## List sources
## #############################################################################

list_source_files(${TARGET_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}
  vtkDataManagement
  vtkImageView
  vtkVisuManagement
  vtkVisuManagement/lut
  vtkWidgetsAddOn
  )

list_header_directories_to_include(${TARGET_NAME}
  ${${TARGET_NAME}_HEADERS}
  )

## #############################################################################
## add library
## #############################################################################

add_library(${TARGET_NAME} SHARED
  ${${TARGET_NAME}_CFILES}
  )

## #############################################################################
## include directories
## #############################################################################

target_include_directories(${TARGET_NAME}
  PUBLIC
  ${${TARGET_NAME}_INCLUDE_DIRS}
  )

## #############################################################################
## Link
## #############################################################################

target_link_libraries(${TARGET_NAME}
    Qt5::Core
    Qt5::Widgets
    medCoreLegacy
    ITKIOImageBase
    ITKIOBMP
    ITKIOLSM
    ITKIOJPEG
    ITKIOPNG
    ITKIOVTK
    ITKIOGDCM
    ITKIOGE
    ITKNrrdIO
    ITKIONRRD
    ITKIOMeta
    ITKIONIFTI
    ITKIOGIPL
    ITKIOHDF5
    ITKIOBioRad
    ITKIOStimulate
    ${ITKIOPhilipsREC_LIBRARIES}
    ITKIOMRC
    ${ITKReview_LIBRARIES} #TODO Get rid of this ASAP
    vtkCommonCore
    vtkCommonSystem
    vtkImagingColor
    vtkImagingGeneral
    vtkImagingHybrid
    vtkIOCore
    vtkIOExportOpenGL2
    vtkIOGeometry
    vtkIOImage
    vtkIOLegacy
    vtkIOXML
    vtkRenderingAnnotation
    vtkRenderingCore
    vtkRenderingOpenGL2
    vtkRenderingGL2PSOpenGL2
    vtkRenderingVolumeOpenGL2
    vtkRenderingContextOpenGL2
    vtkInteractionWidgets
    vtkInteractionStyle
    vtkFiltersExtraction
    vtkFiltersModeling
    vtkImagingStencil
    vtkFiltersGeometry
    vtksys
  )

## #############################################################################
## install
## #############################################################################

set_lib_install_rules(${TARGET_NAME}
  ${${TARGET_NAME}_HEADERS}
  )
