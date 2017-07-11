/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#ifdef WIN32
 #if defined (medVTKSimpleViewer_EXPORTS)
  #define MEDVTKSIMPLEVIEWER_EXPORT __declspec( dllexport )
 #else
  #define MEDVTKSIMPLEVIEWER_EXPORT __declspec( dllimport )
 #endif
#else
    #define MEDVTKSIMPLEVIEWER_EXPORT
#endif



