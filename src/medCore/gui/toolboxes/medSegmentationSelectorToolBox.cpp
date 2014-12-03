/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medSegmentationSelectorToolBox.h>

#include <medToolBoxFactory.h>
#include <medToolBoxTab.h>
#include <medSegmentationAbstractToolBox.h>
#include <medToolBoxHeader.h>
#include <medViewEventFilter.h>

#include <QtGui>


class medSegmentationSelectorToolBoxPrivate
{
public:
};

medSegmentationSelectorToolBox::medSegmentationSelectorToolBox(QWidget *parent,QString title) :
    medProcessSelectorToolBox(parent),
    d(new medSegmentationSelectorToolBoxPrivate)
{
    this->setTitle(title);

//    connect(toolbox, SIGNAL(installEventFilterRequest(medViewEventFilter*)),
//                  this, SIGNAL(installEventFilterRequest(medViewEventFilter*)),
//                  Qt::UniqueConnection);
}

medSegmentationSelectorToolBox::~medSegmentationSelectorToolBox(void)
{
    delete d;
    d = NULL;
}
