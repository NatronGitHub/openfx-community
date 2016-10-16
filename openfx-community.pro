OTHER_FILES += \
            Makefile \
            Makefile.master \
            LICENSE \
            README.md \
            Bundle/Makefile \
            Color/Looks/Info.plist \
            Color/Looks/net.fxarena.openfx.Looks.xml \
            Color/Looks/Makefile \
            Color/Looks/README.md \
            Filter/Opacity/Makefile \
            Filter/Opacity/README.md \
            Filter/CannyEdge/Makefile \
            Filter/CannyEdge/README.md
INCLUDEPATH += . \
            Common/Magick \
            Common/OpenFX-SupportExt \
            Common/OpenFX/Support/include \
            Common/OpenFX/include \
            Common/OpenFX/Support/Plugins/include \
            Common/OpenFX/Support/Library \
            /usr/local/magick7/include/ImageMagick-7 \
            /usr/include \
            /usr/include/libxml2
HEADERS += \
            Common/Magick/MagickPlugin.h
SOURCES += \
            Common/Magick/MagickPlugin.cpp \
            Color/Looks/Looks.cpp \
            Filter/Opacity/Opacity.cpp \
            Filter/CannyEdge/CannyEdge.cpp
