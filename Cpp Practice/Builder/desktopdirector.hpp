#ifndef DESKTOPDIRECTOR_H
#define DESKTOPDIRECTOR_H
#include "desktopbuilder.hpp"

class DesktopDirector
{
private:
    DesktopBuilder *desktopBuilder;
public:
    DesktopDirector(DesktopBuilder *pdesktopBuilder){
        desktopBuilder = pdesktopBuilder;
    };

    Desktop* getDesktop(){
        return desktopBuilder->getDesktop();
    }

    Desktop* BuilderDesktop(){
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMotherBoard();
        desktopBuilder->buildMouse();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildRam();
        desktopBuilder->buildSpeaker();
        return desktopBuilder->getDesktop();
    }
};

#endif