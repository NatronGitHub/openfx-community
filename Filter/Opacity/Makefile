PLUGINNAME = Opacity

PLUGINOBJECTS = \
    $(PLUGINNAME).o \
    MagickPlugin.o

SRCDIR = ../..

RESOURCES = \
    $(SRCDIR)/COPYING \
    README.md

include $(SRCDIR)/Makefile.master

VPATH += $(SRCDIR)/Common/Magick

CXXFLAGS  += \
    -I$(SRCDIR)/Common/Magick \
    $(MAGICK_CXXFLAGS)
LINKFLAGS += \
    $(MAGICK_LINKFLAGS)

