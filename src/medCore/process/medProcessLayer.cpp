/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medProcessLayer.h>

#include <medAbstractSubtractImageProcessPlugin.h>

namespace medProcessLayer
{
namespace pluginManager
{
    void initialize(const QString& path)
    {
        QString realpath=path;
        if (path.isEmpty())
        {

            // Use settings to get plugins location.
//                dtkLinearAlgebraSparseSettings linear_algebra_sparse_settings;
//                linear_algebra_sparse_settings.beginGroup("linear-algebra-sparse");
//                realpath = linear_algebra_sparse_settings.value("plugins").toString();
//                linear_algebra_sparse_settings.endGroup();
        }
        medProcessLayer::arithmeticalOperation::addImage::initialize(realpath);
        medProcessLayer::arithmeticalOperation::subtractImage::initialize(realpath);
        medProcessLayer::arithmeticalOperation::multiplyImage::initialize(realpath);
        medProcessLayer::arithmeticalOperation::divideImage::initialize(realpath);
    }
}


namespace arithmeticalOperation
{
    namespace addImage
    {
        namespace _private
        {
            medAbstractAddImageProcessPluginManager manager;
            medAbstractAddImageProcessPluginFactory factory;
        }

        medAbstractAddImageProcessPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        medAbstractAddImageProcessPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        void initialize(const QString& path)
        {
            pluginManager().initialize(path);
        }
    }
    namespace subtractImage
    {
        namespace _private
        {
            medAbstractSubtractImageProcessPluginManager manager;
            medAbstractSubtractImageProcessPluginFactory factory;
        }

        medAbstractSubtractImageProcessPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        medAbstractSubtractImageProcessPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        void initialize(const QString& path)
        {
            pluginManager().initialize(path);
        }
    }
    namespace multiplyImage
    {
        namespace _private
        {
            medAbstractMultiplyImageProcessPluginManager manager;
            medAbstractMultiplyImageProcessPluginFactory factory;
        }

        medAbstractMultiplyImageProcessPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        medAbstractMultiplyImageProcessPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        void initialize(const QString& path)
        {
            pluginManager().initialize(path);
        }
    }
    namespace divideImage
    {
        namespace _private
        {
            medAbstractDivideImageProcessPluginManager manager;
            medAbstractDivideImageProcessPluginFactory factory;
        }

        medAbstractDivideImageProcessPluginManager& pluginManager(void)
        {
            return _private::manager;
        }

        medAbstractDivideImageProcessPluginFactory& pluginFactory(void)
        {
            return _private::factory;
        }

        void initialize(const QString& path)
        {
            pluginManager().initialize(path);
        }
    }
}

}// end of medProcessLayer

