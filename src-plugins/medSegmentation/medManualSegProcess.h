/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractProcess.h>
#include <medAbstractSegmentationProcess.h>
#include <medAbstractData.h>
#include <medAlgorithmPaintToolbox.h>

#include <medSegmentationPluginExport.h>

class medManualSegProcessPrivate;

class MEDVIEWSEGMENTATIONPLUGIN_EXPORT medManualSegProcess : public medAbstractSegmentationProcess
{
    Q_OBJECT

public:
    medManualSegProcess(medAbstractProcess *parent = NULL);
    virtual ~medManualSegProcess();

    static bool registered ();

    virtual medToolBox* toolbox();

public:
    virtual int update ();
    QList<medAbstractParameter*> parameters();
    bool isInteractive() const;

private:
     medManualSegProcessPrivate *d;
};

dtkAbstractProcess * createmedManualSegProcess();
