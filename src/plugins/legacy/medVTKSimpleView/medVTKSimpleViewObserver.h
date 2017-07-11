/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <vtkCommand.h>

#include <medVTKSimpleViewPluginExport.h>

class medVTKSimpleView;
class vtkImageView2D;
class vtkImageView3D;

class MEDVTKSIMPLEVIEWPLUGIN_EXPORT medVTKSimpleViewObserver : public vtkCommand
{

public:

    static medVTKSimpleViewObserver* New()
    {
        return new medVTKSimpleViewObserver;
    }

    void setView (medVTKSimpleView *view);

    inline void   lock()
    {
        this->m_locked = true;
    }
    inline void unlock()
    {
        this->m_locked = false;
    }

    void Execute (vtkObject *caller, unsigned long event, void *callData);


protected:
    medVTKSimpleViewObserver();
    ~medVTKSimpleViewObserver();

private:
    bool m_locked;
    medVTKSimpleView *m_view;
    vtkImageView2D *view2d;
    vtkImageView3D *view3d;
};
