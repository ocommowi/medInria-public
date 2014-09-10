/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractDiffusionProcess.h>
#include <medAbstractData.h>

#include <%1PluginExport.h>

class %1Private;

class %2PLUGIN_EXPORT %1 : public medAbstractDiffusionProcess
{
    Q_OBJECT
    
public:
    %1();
    virtual ~%1();
    
    virtual QString identifier() const;
    virtual QString description() const;
    
    static bool registered();
    
    //! Input data to the plugin is set through here
    void setInputImage(medAbstractData *data);

    // Methods to set parameters can be defined here,
    // they should then be called in the toolbox setProcessParameters method

public slots:
            
    //! Method to actually start the filter
    int update();
    
    //! The output will be available through here
    medAbstractData *output();

private:
    %1Private *d;
};

dtkAbstractProcess *create();


