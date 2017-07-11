/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medVTKSimpleViewPlugin.h>

#include <medVTKSimpleView.h>
#include <medVTKSimpleViewNavigator.h>

#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// medVTKSimpleViewPluginPrivate
// /////////////////////////////////////////////////////////////////

class medVTKSimpleViewPluginPrivate
{
public:
    // Class variables go here.
};

// /////////////////////////////////////////////////////////////////
// medVTKSimpleViewPlugin
// /////////////////////////////////////////////////////////////////

medVTKSimpleViewPlugin::medVTKSimpleViewPlugin(QObject *parent) :
    dtkPlugin(parent), d(new medVTKSimpleViewPluginPrivate)
{

}

medVTKSimpleViewPlugin::~medVTKSimpleViewPlugin()
{
    delete d;
    d = NULL;
}

bool medVTKSimpleViewPlugin::initialize()
{
    if (!medVTKSimpleView::registered()) { dtkWarn() << "Unable to register medVTKSimpleView type"; }

    if (!medVTKSimpleViewNavigator::registered()) { dtkWarn() << "Unable to register medVTKSimpleViewNavigator type"; }

    return true;
}

bool medVTKSimpleViewPlugin::uninitialize()
{
    return true;
}

QString medVTKSimpleViewPlugin::name() const
{
    return "medVTKSimpleViewPlugin";
}

QString medVTKSimpleViewPlugin::contact() const
{
    return "medinria team";
}

QStringList medVTKSimpleViewPlugin::authors() const
{
    QStringList list;
    list << QString::fromUtf8("rdebroiz");
    return list;
}

QStringList medVTKSimpleViewPlugin::contributors() const
{
    QStringList list;
    list << "rdebroiz";

    return list;
}

QString medVTKSimpleViewPlugin::version() const
{
    return MEDVTKSIMPLEVIEWPLUGIN_VERSION;
}

QString medVTKSimpleViewPlugin::description() const
{
    return tr("View Plugin\n<br/>"
              "Bring a view based on medVtkinria");
}

QStringList medVTKSimpleViewPlugin::tags() const
{
    return QStringList() << "medVtk" << "view";
}

QStringList medVTKSimpleViewPlugin::types() const
{
    return QStringList() << medVTKSimpleView::s_identifier();
}

//TODO What is it for - RDE
//Q_EXPORT_PLUGIN2(medVTKSimpleViewPlugin, medVTKSimpleViewPlugin)
