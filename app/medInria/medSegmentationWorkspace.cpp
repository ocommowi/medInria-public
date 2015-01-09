/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medSegmentationWorkspace.h>

#include <dtkCore/dtkAbstractProcessFactory.h>

#include <medSegmentationSelectorToolBox.h>
#include <medSegmentationAbstractToolBox.h>

#include <medAbstractView.h>

#include <medProgressionStack.h>
#include <medTabbedViewContainers.h>
#include <medViewContainer.h>
#include <medWorkspaceFactory.h>
#include <medToolBoxFactory.h>
#include <medViewEventFilter.h>
#include <medViewContainerManager.h>
#include <medDataManager.h>
#include <medJobManager.h>
#include <medMetaDataKeys.h>
#include <medViewParameterGroup.h>
#include <medLayerParameterGroup.h>
#include <medProcessSelectorToolBox.h>

#include <medAbstractFilteringProcess.h>
#include <medAbstractSegmentationProcess.h>
#include <medAbstractProcess.h>
#include <medTriggerParameter.h>
#include <medViewContainerSplitter.h>
#include <medAbstractData.h>
#include <medAbstractLayeredView.h>

#include <dtkLog/dtkLog.h>

#include <stdexcept>

//#include <medFilteringWorkspace.h>
//#include <medFilteringAbstractToolBox.h>
//#include <medAbstractFilteringProcess.h>

class medSegmentationWorkspacePrivate
{
public:
    // Give values to items without a constructor.
   // medSegmentationWorkspacePrivate() // : segmentationToolBox(NULL)
   // {}

    medSegmentationSelectorToolBox *segmentationToolBoxManu;
    medSegmentationSelectorToolBox *segmentationToolBoxSemiAuto;

    dtkSmartPointer <medAbstractSegmentationProcess> processSemiAuto;
    dtkSmartPointer <medAbstractSegmentationProcess> processManu;
};


medSegmentationWorkspace::medSegmentationWorkspace(QWidget * parent /* = NULL */ ) :
medAbstractWorkspace(parent), d(new medSegmentationWorkspacePrivate)
{
    QString titleManu = "Manual Segmentation";
    d->segmentationToolBoxManu = new medSegmentationSelectorToolBox(parent,titleManu);

    //connect(d->segmentationToolBoxManu, SIGNAL(installEventFilterRequest(medViewEventFilter*)),this, SLOT(addViewEventFilter(medViewEventFilter*)));
    connect(d->segmentationToolBoxManu, SIGNAL(success()),this,SLOT(onSuccess()));

    // Always have a parent.
    if (!parent)
        throw (std::runtime_error ("Must have a parent widget"));

    this->addToolBox(d->segmentationToolBoxManu);

    QStringList implementations = dtkAbstractProcessFactory::instance()->implementations("ManualSegmentation");
    d->segmentationToolBoxManu->setAvailableProcesses(implementations);

    medViewParameterGroup *viewGroup1 = new medViewParameterGroup("View Group 1", this, this->identifier());
    viewGroup1->setLinkAllParameters(true);
    viewGroup1->removeParameter("DataList");

    medLayerParameterGroup *layerGroup1 = new medLayerParameterGroup("Layer Group 1", this, this->identifier());
    layerGroup1->setLinkAllParameters(true);

    //connect(this->tabbedViewContainers(), SIGNAL(containersSelectedChanged()), d->segmentationToolBoxManu, SIGNAL(inputChanged()));
    connect(d->segmentationToolBoxManu, SIGNAL(processSelected(QString)), this, SLOT(setupProcessManu(QString)));



    QString titleSemi = "Semi-Automatic Segmentation";
    d->segmentationToolBoxSemiAuto = new medSegmentationSelectorToolBox(parent,titleSemi);

    // Always have a parent.
    if (!parent)
        throw (std::runtime_error ("Must have a parent widget"));

    this->addToolBox(d->segmentationToolBoxSemiAuto);

    QStringList implementations2 = dtkAbstractProcessFactory::instance()->implementations("SemiAutomaticSeg");
    d->segmentationToolBoxSemiAuto->setAvailableProcesses(implementations2);


    medViewParameterGroup *viewGroup2 = new medViewParameterGroup("View Group 2", this, this->identifier());
    viewGroup2->setLinkAllParameters(true);
    viewGroup2->removeParameter("DataList");

    medLayerParameterGroup *layerGroup2 = new medLayerParameterGroup("Layer Group 2", this, this->identifier());
    layerGroup2->setLinkAllParameters(true);

    connect(d->segmentationToolBoxSemiAuto, SIGNAL(processSelected(QString)), this, SLOT(setupProcess(QString)));


}

void medSegmentationWorkspace::setupTabbedViewContainer()
{
    if (!tabbedViewContainers()->count()) {
        this->tabbedViewContainers()->addContainerInTab(this->name());
    }
    this->tabbedViewContainers()->unlockTabs();
}

medSegmentationWorkspace::~medSegmentationWorkspace(void)
{
    delete d;
    d = NULL;
}

medSegmentationSelectorToolBox * medSegmentationWorkspace::segmentationTooboxManu()
{
    return d->segmentationToolBoxManu;
}

medSegmentationSelectorToolBox * medSegmentationWorkspace::segmentationTooboxSemiAuto()
{
    return d->segmentationToolBoxSemiAuto;
}

void medSegmentationWorkspace::addViewEventFilter( medViewEventFilter * filter)
{
    foreach(QUuid uuid, this->tabbedViewContainers()->containersSelected())
    {
        medViewContainer *container = medViewContainerManager::instance()->container(uuid);
        if(!container)
            return;
        filter->installOnView(container->view());
    }
}

//TODO: not tested yet
void medSegmentationWorkspace::onSuccess()
{
    //medAbstractData * output = d->segmentationToolBoxManu->currentToolBox()->processOutput();
    //medDataManager::instance()->importData(output);

    //medAbstractData * outputSemiAuto = d->segmentationToolBoxSemiAuto->currentToolBox()->processOutput();
    //medDataManager::instance()->importData(outputSemiAuto);
}


void medSegmentationWorkspace::setupProcess(QString process)
{
    medAbstractProcess *temp = d->processSemiAuto;
    d->processSemiAuto = dynamic_cast<medAbstractSegmentationProcess*>(dtkAbstractProcessFactory::instance()->create(process));
    if(d->processSemiAuto)
    {
        d->segmentationToolBoxSemiAuto->setProcessToolbox(d->processSemiAuto->toolbox());
        connect(d->processSemiAuto->runParameter(), SIGNAL(triggered()), this, SLOT(startProcess()));
        this->tabbedViewContainers()->setSplitter(0, d->processSemiAuto->viewContainerSplitter());
    }

    if(d->processSemiAuto && temp)
    {
        d->processSemiAuto->retrieveInputs(temp);
    }

    delete temp;
}

void medSegmentationWorkspace::setupProcessManu(QString process)
{
    medAbstractProcess *temp = d->processManu;
    d->processManu = dynamic_cast<medAbstractSegmentationProcess*>(dtkAbstractProcessFactory::instance()->create(process));
    if(d->processManu)
    {
        d->segmentationToolBoxManu->setProcessToolbox(d->processManu->toolbox());
        connect(d->processManu->runParameter(), SIGNAL(triggered()), this, SLOT(startProcessManu()));

        connect(this->tabbedViewContainers(), SIGNAL(containersSelectedChanged()), d->processManu, SIGNAL(inputChanged()));
        connect(d->processManu, SIGNAL(installEventFilterRequest(medViewEventFilter*)),this, SLOT(addViewEventFilter(medViewEventFilter*)));

    }

    if(d->processManu && temp)
    {
        d->processManu->retrieveInputs(temp);
    }

    delete temp;
}

bool medSegmentationWorkspace::isUsable()
{
    medToolBoxFactory * tbFactory = medToolBoxFactory::instance();
    return (tbFactory->toolBoxesFromCategory("segmentation").size()!=0);
}

void medSegmentationWorkspace::startProcess()
{
    if(!d->processSemiAuto)
        return;

    d->segmentationToolBoxSemiAuto->setEnabled(false);

    medRunnableProcess *runProcess = new medRunnableProcess(d->processSemiAuto, d->processSemiAuto->name());
    connect (runProcess, SIGNAL (success()),this,SLOT(enableSelectorToolBox()));
    connect (runProcess, SIGNAL (failure()),this,SLOT(enableSelectorToolBox()));

    runProcess->start();
}

void medSegmentationWorkspace::startProcessManu()
{
    if(!d->processManu)
        return;

    d->segmentationToolBoxManu->setEnabled(false);

    medRunnableProcess *runProcess = new medRunnableProcess(d->processManu, d->processManu->name());
    connect (runProcess, SIGNAL (success()),this,SLOT(enableSelectorToolBoxManu()));
    connect (runProcess, SIGNAL (failure()),this,SLOT(enableSelectorToolBoxManu()));

    runProcess->start();
}

void medSegmentationWorkspace::enableSelectorToolBox()
{
    d->segmentationToolBoxSemiAuto->setEnabled(true);
}

void medSegmentationWorkspace::enableSelectorToolBoxManu()
{
    d->segmentationToolBoxManu->setEnabled(true);
}

