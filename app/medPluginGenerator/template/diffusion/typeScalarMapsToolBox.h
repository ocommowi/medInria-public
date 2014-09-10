/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medDiffusionAbstractToolBox.h>
#include <%1PluginExport.h>

class %1ToolBoxPrivate;

class %2PLUGIN_EXPORT %1ToolBox : public medDiffusionScalarMapsAbstractToolBox
{
    Q_OBJECT
    MED_TOOLBOX_INTERFACE("%1",
                          "TODO Description",
                          << "diffusion-scalar-maps")
    
public:
    %1ToolBox(QWidget *parent = 0);
    ~%1ToolBox();
        
    static bool registered();
    dtkPlugin * plugin();

    virtual QString processName();
    virtual void setProcessParameters(medAbstractDiffusionProcess *process);
        
public slots:
    void requestProcess(QString mapRequested);
    void exampleRequestSlot();

private:
    %1ToolBoxPrivate *d;
};


