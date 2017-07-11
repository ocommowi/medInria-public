#pragma once
#include <medVTKSimpleViewerExport.h>

#include <vtkCommand.h>
#include <vtkSetGet.h>
#include <vtkObjectFactory.h>

class vtkVolumeMapper;

class MEDVTKSIMPLEVIEWER_EXPORT vtkImageView3DCroppingBoxCallback: public vtkCommand
{

public:
    static vtkImageView3DCroppingBoxCallback* New()
    { return new vtkImageView3DCroppingBoxCallback; }

    virtual void Execute ( vtkObject *caller, unsigned long event, void*vtkNotUsed(callData) );

    void SetVolumeMapper (vtkVolumeMapper* mapper)
    {
        this->VolumeMapper = mapper;
    }
    vtkVolumeMapper* GetVolumeMapper (void) const
    {
        return this->VolumeMapper;
    }


protected:
    vtkImageView3DCroppingBoxCallback()
    {
        this->VolumeMapper = 0;
    }
    ~vtkImageView3DCroppingBoxCallback(){};

private:
    vtkVolumeMapper* VolumeMapper;
};
