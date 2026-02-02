#pragma once
#include "../../panel.hpp"

class Viewport : public PanelEditor {
private:
    bool isWindowActive;
public:
    Viewport() : PanelEditor("Viewport") {}
    void onUpdate();
    
    bool getiswindowActive();
};