TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Functions.cpp \
        character.cpp \
        chest.cpp \
        enemy.cpp \
        item.cpp \
        main.cpp \
        playerclass.cpp \
        room.cpp \
        weapon.cpp
        INCLUDEPATH += "C:/SFML-2.5.1/include"
        LIBS += -L"C:/SFML-2.5.1/lib"
        CONFIG(debug, debug|release){
            LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        } else {
            LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
        }

        HEADERS += \
    Functions.h \
            character.h \
    chest.h \
            enemy.h \
    item.h \
            playerclass.h \
            room.h \
    weapon.h
