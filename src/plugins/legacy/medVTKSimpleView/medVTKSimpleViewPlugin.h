/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <dtkCoreSupport/dtkPlugin.h>

#include <medVTKSimpleViewPluginExport.h>

class medVTKSimpleViewPluginPrivate;

class MEDVTKSIMPLEVIEWPLUGIN_EXPORT medVTKSimpleViewPlugin : public dtkPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "fr.inria.medVTKSimpleViewPlugin" FILE "medVTKSimpleViewPlugin.json")
    Q_INTERFACES(dtkPlugin)

public:
    medVTKSimpleViewPlugin(QObject *parent = 0);
    ~medVTKSimpleViewPlugin();

    virtual bool initialize();
    virtual bool uninitialize();

    virtual QString name() const;
    virtual QString description() const;
    virtual QString version() const;

    virtual QStringList authors() const;
    virtual QString contact() const;
    virtual QStringList contributors() const;


    virtual QStringList tags() const;
    virtual QStringList types() const;

private:
    medVTKSimpleViewPluginPrivate *d;
};


