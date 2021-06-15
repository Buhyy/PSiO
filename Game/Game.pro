TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        character.cpp \
        enemy.cpp \
        item.cpp \
        main.cpp \
        playerclass.cpp \
        room.cpp
        INCLUDEPATH += "C:/SFML-2.5.1/include"
        LIBS += -L"C:/SFML-2.5.1/lib"
        CONFIG(debug, debug|release){
            LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        } else {
            LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
        }

        HEADERS += \
            character.h \
            enemy.h \
    item.h \
            playerclass.h \
            room.h
