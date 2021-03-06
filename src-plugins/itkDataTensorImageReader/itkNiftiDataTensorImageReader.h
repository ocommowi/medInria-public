/*=========================================================================

 medInria

 Copyright (c) INRIA 2013. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <itkDataTensorImageReaderBase.h>
#include <itkDataTensorImageReaderPluginExport.h>

class ITKDATATENSORIMAGEREADERPLUGIN_EXPORT itkNiftiDataTensorImageReader: public itkDataTensorImageReaderBase {
    Q_OBJECT
	
public:

    itkNiftiDataTensorImageReader();
    virtual ~itkNiftiDataTensorImageReader();
	
    virtual QString identifier()  const;
    virtual QString description() const;
	
    static bool registered();	

private:

    static const char ID[];
};

dtkAbstractDataReader *createItkNiftiDataTensorImageReader();


