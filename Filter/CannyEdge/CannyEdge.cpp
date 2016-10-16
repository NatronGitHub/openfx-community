/*
 * CannyEdge
 * Copyright (C) 2016 INRIA & Ole-André Rodlie
 *
 * This plugin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * this plugin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the plugin.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
*/

#include "MagickPlugin.h"

using namespace OFX;
OFXS_NAMESPACE_ANONYMOUS_ENTER

#define kPluginName "CannyEdge"
#define kPluginGrouping "Filter"
#define kPluginIdentifier "net.fxarena.openfx.CannyEdge"
#define kPluginDescription "The Canny edge detector is an edge detection operator that uses a multi-stage algorithm to detect a wide range of edges in images."
#define kPluginVersionMajor 1
#define kPluginVersionMinor 0

#define kSupportsTiles 0
#define kSupportsMultiResolution 1
#define kSupportsRenderScale 1
#define kRenderThreadSafety eRenderFullySafe
#define kHostFrameThreading false
#define kHostMasking true
#define kHostMixing true

#define kParamRadius "radius"
#define kParamRadiusLabel "Radius"
#define kParamRadiusHint "Radius"
#define kParamRadiusDefault 0.0

#define kParamSigma "sigma"
#define kParamSigmaLabel "Sigma"
#define kParamSigmaHint "Sigma"
#define kParamSigmaDefault 1.0

#define kParamLowerPercent "lowerPercent"
#define kParamLowerPercentLabel "Lower Percent"
#define kParamLowerPercentHint "Lower Percent"
#define kParamLowerPercentDefault 0.01

#define kParamUpperPercent "upperPercent"
#define kParamUpperPercentLabel "Upper Percent"
#define kParamUpperPercentHint "Upper Percent"
#define kParamUpperPercentDefault 0.1

class CannyEdgePlugin
    : public MagickPluginHelper<kSupportsRenderScale>
{
public:
    CannyEdgePlugin(OfxImageEffectHandle handle)
        : MagickPluginHelper<kSupportsRenderScale>(handle)
        , _radius(0)
        , _sigma(0)
        , _lower(0)
        , _upper(0)
    {
        _radius = fetchDoubleParam(kParamRadius);
        _sigma = fetchDoubleParam(kParamSigma);
        _lower = fetchDoubleParam(kParamLowerPercent);
        _upper = fetchDoubleParam(kParamUpperPercent);
        assert(_radius && _sigma && _lower && _upper);
    }

    virtual void render(const OFX::RenderArguments &args, Magick::Image &image) OVERRIDE FINAL
    {
        double radius, sigma, lowerP, upperP;
        _radius->getValueAtTime(args.time, radius);
        _sigma->getValueAtTime(args.time, sigma);
        _lower->getValueAtTime(args.time, lowerP);
        _upper->getValueAtTime(args.time, upperP);
        image.cannyEdge(radius, sigma, lowerP, upperP);
    }
private:
    DoubleParam *_radius;
    DoubleParam *_sigma;
    DoubleParam *_lower;
    DoubleParam *_upper;
};

mDeclarePluginFactory(CannyEdgePluginFactory, {}, {});

void CannyEdgePluginFactory::describe(ImageEffectDescriptor &desc)
{
    desc.setLabel(kPluginName);
    desc.setPluginGrouping(kPluginGrouping);
    desc.setPluginDescription(kPluginDescription);
    desc.addSupportedContext(eContextGeneral);
    desc.addSupportedContext(eContextFilter);
    desc.addSupportedBitDepth(eBitDepthFloat);
    desc.setSupportsTiles(kSupportsTiles);
    desc.setSupportsMultiResolution(kSupportsMultiResolution);
    desc.setRenderThreadSafety(kRenderThreadSafety);
    desc.setHostFrameThreading(kHostFrameThreading);
    desc.setHostMaskingEnabled(kHostMasking);
    desc.setHostMixingEnabled(kHostMixing);
}

void CannyEdgePluginFactory::describeInContext(ImageEffectDescriptor &desc, ContextEnum context)
{
    OFX::PageParamDescriptor *page = CannyEdgePlugin::describeInContextBegin(desc, context);
    {
        DoubleParamDescriptor *param = desc.defineDoubleParam(kParamRadius);
        param->setLabel(kParamRadiusLabel);
        param->setHint(kParamRadiusHint);
        param->setRange(0, 100);
        param->setDisplayRange(0, 25);
        param->setDefault(kParamRadiusDefault);
        if (page) {
            page->addChild(*param);
        }
    }
    {
        DoubleParamDescriptor *param = desc.defineDoubleParam(kParamSigma);
        param->setLabel(kParamSigmaLabel);
        param->setHint(kParamSigmaHint);
        param->setRange(0, 100);
        param->setDisplayRange(0, 10);
        param->setDefault(kParamSigmaDefault);
        if (page) {
            page->addChild(*param);
        }
    }
    {
        DoubleParamDescriptor *param = desc.defineDoubleParam(kParamLowerPercent);
        param->setLabel(kParamLowerPercentLabel);
        param->setHint(kParamLowerPercentHint);
        param->setRange(0, 100);
        param->setDisplayRange(0, 1);
        param->setDefault(kParamLowerPercentDefault);
        if (page) {
            page->addChild(*param);
        }
    }
    {
        DoubleParamDescriptor *param = desc.defineDoubleParam(kParamUpperPercent);
        param->setLabel(kParamUpperPercentLabel);
        param->setHint(kParamUpperPercentHint);
        param->setRange(0, 100);
        param->setDisplayRange(0, 1);
        param->setDefault(kParamUpperPercentDefault);
        if (page) {
            page->addChild(*param);
        }
    }
    CannyEdgePlugin::describeInContextEnd(desc, context, page);
}

OFX::ImageEffect*
CannyEdgePluginFactory::createInstance(OfxImageEffectHandle handle, ContextEnum /*context*/)
{
    return new CannyEdgePlugin(handle);
}

static CannyEdgePluginFactory p(kPluginIdentifier, kPluginVersionMajor, kPluginVersionMinor);
mRegisterPluginFactoryInstance(p)

OFXS_NAMESPACE_ANONYMOUS_EXIT
