#ifndef HPDESKTOPBUILDER_H
#define HPDESKTOPBUILDER_H
#include "desktopbuilder.hpp"

class HpDesktopBuilder: public DesktopBuilder
{
    void buildMonitor();
    void buildKeyboard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
};


#endif