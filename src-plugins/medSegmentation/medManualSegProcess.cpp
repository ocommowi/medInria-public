/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medManualSegProcess.h>
#include <dtkCore/dtkAbstractProcessFactory.h>

#include <itkImage.h>
#include <itkCommand.h>
#include <itkExceptionObject.h>

#include <medMetaDataKeys.h>
#include <medAbstractDataFactory.h>
#include <medToolBoxFactory.h>
#include <medAlgorithmPaintToolbox.h>

class medManualSegProcessPrivate
{
public:
    medAlgorithmPaintToolbox *toolbox;
};


medManualSegProcess::medManualSegProcess(medAbstractProcess *parent):
    medAbstractSegmentationProcess(parent), d(new medManualSegProcessPrivate)
{
    d->toolbox = new medAlgorithmPaintToolbox;
    connect(this, SIGNAL(inputChanged()), d->toolbox, SLOT(updateMouseInteraction()));
    connect(d->toolbox, SIGNAL(installEventFilterRequest(medViewEventFilter*)), this, SIGNAL(installEventFilterRequest(medViewEventFilter*)));
}

medManualSegProcess::~medManualSegProcess()
{
    delete d;
}

medToolBox* medManualSegProcess::toolbox()
{
    return d->toolbox;
}

//-------------------------------------------------------------------------------------------

bool medManualSegProcess::registered()
{
    return dtkAbstractProcessFactory::instance()->registerProcessType("medManualSegProcess", createmedManualSegProcess, "ManualSegmentation");
}

//-------------------------------------------------------------------------------------------

QList<medAbstractParameter*> medManualSegProcess::parameters()
{
    return QList<medAbstractParameter*>();
}

//-------------------------------------------------------------------------------------------

int medManualSegProcess::update()
{
}

bool medManualSegProcess::isInteractive() const
{
    return false;
}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractProcess * createmedManualSegProcess()
{
    return new medManualSegProcess;
}
