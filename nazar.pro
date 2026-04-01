QT += widgets
CONFIG += c++17
TARGET = nazar
TEMPLATE = app

SOURCES += \
    src/main.cpp

RESOURCES += \
    resources.qrc

 DISTFILES += nazar.svg

# Compiler/linker flags
QMAKE_CXXFLAGS += -Wall -Wextra -Werror
