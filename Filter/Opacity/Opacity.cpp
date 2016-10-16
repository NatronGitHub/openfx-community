/*
 * Opacity
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

#define kPluginName "Opacity"
#define kPluginGrouping "Filter"
#define kPluginIdentifier "net.fxarena.openfx.Opacity"
#define kPluginDescription "Adjust image opacity using ImageMagick."
#define kPluginVersionMajor 1
#define kPluginVersionMinor 0

#define kSupportsTiles 0
#define kSupportsMultiResolution 1
#define kSupportsRenderScale 1
#define kRenderThreadSafety eRenderFullySafe
#define kHostFrameThreading false
#define kHostMasking true
#define kHostMixing true

#define kParamOpacity "opacity"
#define kParamOpacityLabel "Opacity"
#define kParamOpacityHint "Opacity amount."
#define kParamOpacityDefault 1

class OpacityPlugin
    : public MagickPluginHelper<kSupportsRenderScale>
{
public:
    OpacityPlugin(OfxImageEffectHandle handle)
        : MagickPluginHelper<kSupportsRenderScale>(handle)
        , _opacity(0)
    {
        _opacity = fetchDoubleParam(kParamOpacity);
        assert(_opacity);
    }

    virtual void render(const OFX::RenderArguments &args, Magick::Image &image) OVERRIDE FINAL
    {
        double amount;
        _opacity->getValueAtTime(args.time, amount);
        if (amount < 1.0) {
            image.evaluate(Magick::AlphaChannel, Magick::MultiplyEvaluateOperator, amount);
        }
    }
private:
    DoubleParam *_opacity;
};

mDeclarePluginFactory(OpacityPluginFactory, {}, {});

void OpacityPluginFactory::describe(ImageEffectDescriptor &desc)
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

void OpacityPluginFactory::describeInContext(ImageEffectDescriptor &desc, ContextEnum context)
{
    OFX::PageParamDescriptor *page = OpacityPlugin::describeInContextBegin(desc, context);
    {
        DoubleParamDescriptor *param = desc.defineDoubleParam(kParamOpacity);
        param->setLabel(kParamOpacityLabel);
        param->setHint(kParamOpacityHint);
        param->setRange(0, 1);
        param->setDisplayRange(0, 1);
        param->setDefault(kParamOpacityDefault);
        if (page) {
            page->addChild(*param);
        }
    }
    OpacityPlugin::describeInContextEnd(desc, context, page);
}

OFX::ImageEffect*
OpacityPluginFactory::createInstance(OfxImageEffectHandle handle, ContextEnum /*context*/)
{
    return new OpacityPlugin(handle);
}

static OpacityPluginFactory p(kPluginIdentifier, kPluginVersionMajor, kPluginVersionMinor);
mRegisterPluginFactoryInstance(p)

OFXS_NAMESPACE_ANONYMOUS_EXIT
