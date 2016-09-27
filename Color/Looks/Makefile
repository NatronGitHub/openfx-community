PLUGINNAME = Looks

PLUGINOBJECTS = \
    $(PLUGINNAME).o \
    MagickPlugin.o

SRCDIR = ../..

RESOURCES = \
    net.fxarena.openfx.$(PLUGINNAME).png \
    net.fxarena.openfx.$(PLUGINNAME).svg \
    net.fxarena.openfx.$(PLUGINNAME).xml

include $(SRCDIR)/Makefile.master

VPATH += $(SRCDIR)/Common/Magick

CXXFLAGS  += \
    -I$(SRCDIR)/Common/Magick \
    $(MAGICK_CXXFLAGS) \
    $(CURL_CXXFLAGS) \
    $(XML_CXXFLAGS)
LINKFLAGS += \
    $(MAGICK_LINKFLAGS) \
    $(CURL_LINKFLAGS) \
    $(XML_LINKFLAGS)

