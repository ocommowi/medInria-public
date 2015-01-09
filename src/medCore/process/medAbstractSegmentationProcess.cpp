/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include "medAbstractSegmentationProcess.h"

#include <medAbstractImageData.h>

medAbstractSegmentationProcess::medAbstractSegmentationProcess(medAbstractProcess *parent): medAbstractProcess(parent)
{
    medProcessInput<medAbstractData> *input = new medProcessInput<medAbstractData>("MRI Image 1", false, NULL);
    this->appendInput( input );

    medProcessInput<medAbstractData> *input2 = new medProcessInput<medAbstractData>("MRI Image 3", false, NULL);
    this->appendInput( input2 );

    medProcessInput<medAbstractData> *input3 = new medProcessInput<medAbstractData>("MRI Image 2", false, NULL);
    this->appendInput( input3 );


    //this->appendOutput( new medProcessOutput<medAbstractData>("Seg Output 1", NULL));
}

bool medAbstractSegmentationProcess::isInteractive() const
{
    return true;
}
