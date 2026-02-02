#pragma once
#include "../../panel.hpp"

class Terminal : public PanelEditor {
public:
    Terminal() : PanelEditor("Terminal") {}
    void onUpdate();
};