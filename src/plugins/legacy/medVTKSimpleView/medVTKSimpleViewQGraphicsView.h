/*=========================================================================

 medInria

 Copyright (c) INRIA 2013. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <QGraphicsView>
#include <medVTKSimpleViewPluginExport.h>

class QVTKGraphicsItem;

class medVTKSimpleViewQGraphicsViewPrivate;
class MEDVTKSIMPLEVIEWPLUGIN_EXPORT medVTKSimpleViewQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    medVTKSimpleViewQGraphicsView(QWidget * parent = NULL);
    virtual ~medVTKSimpleViewQGraphicsView();

    void setQVtkGraphicsItem(QVTKGraphicsItem *vtkItem);
    QVTKGraphicsItem* qVtkGraphicsItem() const;
    

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    medVTKSimpleViewQGraphicsViewPrivate *d;

};
