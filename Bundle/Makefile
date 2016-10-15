PLUGINNAME = Community

PLUGINOBJECTS = \
Looks.o \
Opacity.o \
MagickPlugin.o \
ChannelMath.o \
INK.o

SRCDIR = ..

RESOURCES = \
$(SRCDIR)/Color/Looks/net.fxarena.openfx.Looks.png \
$(SRCDIR)/Color/Looks/net.fxarena.openfx.Looks.svg \
$(SRCDIR)/Color/Looks/net.fxarena.openfx.Looks.xml \
$(SRCDIR)/Color/ChannelMath/com.casanico.ChannelMath.png \
$(SRCDIR)/Color/ChannelMath/com.casanico.ChannelMath.svg \
$(SRCDIR)/Keyer/INK/com.casanico.INK.png \
$(SRCDIR)/Keyer/INK/com.casanico.INK.svg \
$(SRCDIR)/COPYING \
$(SRCDIR)/README.md

include $(SRCDIR)/Makefile.master

VPATH += \
$(SRCDIR)/Common/Magick \
$(SRCDIR)/Color/Looks \
$(SRCDIR)/Color/Opacity \
$(SRCDIR)/Color/ChannelMath \
$(SRCDIR)/Keyer/INK

CXXFLAGS += \
-I$(SRCDIR)/Common/Magick \
$(MAGICK_CXXFLAGS) \
$(CURL_CXXFLAGS) \
$(XML_CXXFLAGS)

LINKFLAGS += \
$(MAGICK_LINKFLAGS) \
$(CURL_LINKFLAGS) \
$(XML_LINKFLAGS)

