#include "desktop.hpp"
#include <iostream>
using namespace std;

void Desktop::setMonitor(string pMonitor)
{
    monitor = pMonitor;
}

void Desktop::setKeyboard(string pKeyboard)
{
    keyboard = pKeyboard;
}

void Desktop::setMouse(string pMouse)
{
    mouse = pMouse;
}

void Desktop::setSpeaker(string pSpeaker)
{
    speaker = pSpeaker;
}

void Desktop::setRam(string pRam)
{
    ram = pRam;
}

void Desktop::setProcessor(string pProcessor)
{
    processor = pProcessor;
}

void Desktop::setMotherBoard(string pMotherBoard)
{
    motherBoard = pMotherBoard;
}

void Desktop::showSpecs()
{
    cout <<"--------------------------------------------------------------------"<<endl;
    cout<<"Monitor " << monitor <<endl;
    cout<<"Keyboard " << keyboard <<endl;
    cout<<"Mouse " << mouse <<endl;
    cout<<"Speaker " << speaker <<endl;
    cout<<"Ram " << ram <<endl;
    cout<<"Processor " << processor <<endl;
    cout<<"MotherBoard " << motherBoard <<endl;
    cout <<"--------------------------------------------------------------------"<<endl;
}
