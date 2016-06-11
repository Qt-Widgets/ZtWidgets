isEmpty(ZTWIDGETS_INSTALL_PATH) {
    error(ZTWIDGETS_INSTALL_PATH not set!)
}

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Werror

TEMPLATE = lib

TARGET = $$qtLibraryTarget($$TARGET)

INCLUDEPATH += include

CONFIG(debug, debug|release) {
    target.path = $$ZTWIDGETS_INSTALL_PATH/debug
} else {
    target.path = $$ZTWIDGETS_INSTALL_PATH/release
}

message($$TARGET will be installed in $$target.path)
INSTALLS += target

SOURCES += src/colorpicker.cpp \
    src/colorwidgetbase.cpp \
    src/colorhexedit.cpp \
    src/colordisplay.cpp \
    src/huesaturationwheel.cpp \
    src/abstractcolorcomponentslider.cpp \
    src/horizontalcolorcomponentslider.cpp \
    src/verticalcolorcomponentslider.cpp

HEADERS += include/ZtWidgets/colorpicker.h \
    include/ZtWidgets/colorwidgetbase.h \
    include/ZtWidgets/colorhexedit.h \
    include/ZtWidgets/colordisplay.h \
    include/ZtWidgets/huesaturationwheel.h \
    include/ZtWidgets/abstractcolorcomponentslider.h \
    include/ZtWidgets/horizontalcolorcomponentslider.h \
    include/ZtWidgets/verticalcolorcomponentslider.h
