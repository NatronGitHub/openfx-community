PLUGINNAME = CannyEdge

PLUGINOBJECTS = \
    $(PLUGINNAME).o \
    MagickPlugin.o

SRCDIR = ../..

RESOURCES = \
    net.fxarena.openfx.$(PLUGINNAME).png \
    net.fxarena.openfx.$(PLUGINNAME).svg \
    $(SRCDIR)/COPYING \
    README.md

include $(SRCDIR)/Makefile.master

VPATH += $(SRCDIR)/Common/Magick

CXXFLAGS  += \
    -I$(SRCDIR)/Common/Magick \
    $(MAGICK_CXXFLAGS)
LINKFLAGS += \
    $(MAGICK_LINKFLAGS)

