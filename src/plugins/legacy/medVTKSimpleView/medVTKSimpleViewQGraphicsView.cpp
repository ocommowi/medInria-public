/*=========================================================================

 medInria

 Copyright (c) INRIA 2013. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medVTKSimpleViewQGraphicsView.h>

#include <QVTKGraphicsItem.h>
#include <QGraphicsView>
#include <dtkLog>

class medVTKSimpleViewQGraphicsViewPrivate
{
public:
    QVTKGraphicsItem *vtkItem;
};


medVTKSimpleViewQGraphicsView::medVTKSimpleViewQGraphicsView(QWidget *parent):
    d(new medVTKSimpleViewQGraphicsViewPrivate)
{
    this->setAcceptDrops(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setCursor(QCursor(Qt::CrossCursor));
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    d->vtkItem = NULL;
}


medVTKSimpleViewQGraphicsView::~medVTKSimpleViewQGraphicsView()
{
    delete d;
    d = NULL;
}

void medVTKSimpleViewQGraphicsView::setQVtkGraphicsItem(QVTKGraphicsItem *vtkItem)
{
    d->vtkItem = vtkItem;
}

QVTKGraphicsItem* medVTKSimpleViewQGraphicsView::qVtkGraphicsItem() const
{
    return d->vtkItem;
}

void medVTKSimpleViewQGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    if(d->vtkItem)
        d->vtkItem->resize(event->size());
}

void medVTKSimpleViewQGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    QWidget::dragEnterEvent(event);
}

void medVTKSimpleViewQGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    QWidget::dragMoveEvent(event);
}

void medVTKSimpleViewQGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    QWidget::dragLeaveEvent(event);
}

void medVTKSimpleViewQGraphicsView::dropEvent(QDropEvent *event)
{
    QWidget::dropEvent(event);
}

void medVTKSimpleViewQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QWidget::mousePressEvent(event);
}

void medVTKSimpleViewQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    QWidget::mouseMoveEvent(event);
}

void medVTKSimpleViewQGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    QWidget::mouseReleaseEvent(event);
}
