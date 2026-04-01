QT += widgets
CONFIG += c++17
TARGET = nazar
TEMPLATE = app

SOURCES += \
    src/main.cpp

RESOURCES += \
    resources.qrc

CONFIG += lrelease embed_translations
LRELEASE_DIR=.
QM_FILES_RESOURCE_PREFIX=/po

DISTFILES += nazar.svg
# Translations
TRANSLATIONS = $$files(po/*.ts)

# Compiler/linker flags
QMAKE_CXXFLAGS += -Wall -Wextra -Werror
