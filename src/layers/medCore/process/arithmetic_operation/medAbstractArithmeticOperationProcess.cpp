/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medAbstractArithmeticOperationProcess.h>

#include <medAbstractImageData.h>
#include <medAbstractImageView.h>
#include <medDataManager.h>
#include <medToolBox.h>
#include <medViewContainerSplitter.h>
#include <medViewContainer.h>

class medAbstractArithmeticOperationProcessPrivate
{
public:
    medAbstractImageData *input1;
    medAbstractImageData *input2;
    medAbstractImageData *output;
};

medAbstractArithmeticOperationProcess::medAbstractArithmeticOperationProcess(QObject *parent): medAbstractProcess(parent),
    d(new medAbstractArithmeticOperationProcessPrivate)
{
    d->input1 = NULL;
    d->input2 = NULL;
    d->output = NULL;
}

medAbstractArithmeticOperationProcess::~medAbstractArithmeticOperationProcess()
{

}

void medAbstractArithmeticOperationProcess::setInput1(medAbstractImageData *data)
{
    d->input1 = data;
}

medAbstractImageData* medAbstractArithmeticOperationProcess::input1() const
{
    return d->input1;
}


void medAbstractArithmeticOperationProcess::setInput2(medAbstractImageData *data)
{
    d->input2 = data;
}

medAbstractImageData* medAbstractArithmeticOperationProcess::input2() const
{
    return d->input2;
}

void medAbstractArithmeticOperationProcess::setOutput(medAbstractImageData *data)
{
    d->output = data;
}

medAbstractImageData* medAbstractArithmeticOperationProcess::output() const
{
    return d->output;
}

