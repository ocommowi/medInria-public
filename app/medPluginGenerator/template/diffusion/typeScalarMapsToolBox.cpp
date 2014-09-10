/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <%1.h>
#include <%1ToolBox.h>

#include <QtGui>

#include <dtkCore/dtkSmartPointer.h>
#include <medAbstractData.h>
#include <medAbstractImageData.h>

#include <medToolBoxFactory.h>
#include <medPluginManager.h>

class %1ToolBoxPrivate
{
public:
    // Here come parameter values that will be used in setProcessParameters

    // TO DO : this holds the map name that was requested
    QString mapRequested;
};

%1ToolBox::%1ToolBox(QWidget *parent) : medDiffusionAbstractToolBox(parent), d(new %1ToolBoxPrivate)
{
    QWidget *widget = new QWidget(this);

    // Create here your toolbox layout and widgets

    QPushButton *exampleButton = new QPushButton(widget,"Example map");
    exampleButton->setToolTip(tr("Example map"));
    exampleButton->setIconSize (QSize (50, 50));
    exampleButton->setFixedSize (60, 60);

    connect(exampleButton,SIGNAL(clicked()).this,SLOT(exampleRequestSlot()));

    QGridLayout *exampleLayout = new QGridLayout (widget);
    exampleLayout->addWidget (exampleButton,  0, 0);

    this->addWidget(widget);

    //Set default process parameters as well
}

%1ToolBox::~%1ToolBox()
{
    delete d;
    d = 0;
}

bool %1ToolBox::registered()
{
    return medToolBoxFactory::instance()->registerToolBox<%1ToolBox>();
}

dtkPlugin* %1ToolBox::plugin()
{
    medPluginManager* pm = medPluginManager::instance();
    dtkPlugin* plugin = pm->plugin ( "%1Plugin" );
    return plugin;
}

void %1ToolBox::processName()
{
    return "%1";
}

void %1ToolBox::setProcessParameters(medAbstractDiffusionProcess *process)
{
    %1 *castProcess = dynamic_cast <%1 *> (process);

    if (!castProcess)
        return;

    //TO DO : set the process parameters from locally stored values
}

void %1ToolBox::exampleRequestSlot()
{
    this->requestProcess("Example map");
}

void %1ToolBox::requestProcess(QString mapRequested)
{
    d->mapRequested = mapRequested;
    emit processStartRequested();
}
