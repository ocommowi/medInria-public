/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractDivideImageProcess.h>

class medItkDivideImageProcessPrivate;

class MEDINRIA_EXPORT medItkDivideImageProcess: public medAbstractDivideImageProcess
{
public:
    medItkDivideImageProcess(QObject* parent = NULL);
    ~medItkDivideImageProcess();

    virtual void run();
    virtual void cancel();

    virtual medProcessDetails details() const;

private:
    template <class inputType> void  _run();

private:
    medItkDivideImageProcessPrivate *d;
};

inline medAbstractDivideImageProcess* medItkDivideImageProcessCreator(void)
{
    return new medItkDivideImageProcess();
}
