/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractMorphomathOperationProcess.h>

#include <dtkCore>

#include <medCoreExport.h>

class medAbstractOpeningImageProcess: public medAbstractMorphomathOperationProcess
{
    Q_OBJECT
public:
    medAbstractOpeningImageProcess(QObject *parent): medAbstractMorphomathOperationProcess(parent) {}
};

DTK_DECLARE_OBJECT        (medAbstractOpeningImageProcess*)
DTK_DECLARE_PLUGIN        (medAbstractOpeningImageProcess, MEDCORE_EXPORT)
DTK_DECLARE_PLUGIN_FACTORY(medAbstractOpeningImageProcess, MEDCORE_EXPORT)
DTK_DECLARE_PLUGIN_MANAGER(medAbstractOpeningImageProcess, MEDCORE_EXPORT)
