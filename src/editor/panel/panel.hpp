#pragma once
#include <string>

class PanelEditor {
private:
    static int counter; 
    int id;             
    std::string tag;
    bool open=false;
public:

    PanelEditor(std::string tag) : tag(tag) {
        id = counter++;
    }

    virtual ~PanelEditor() = default; 
    virtual void onUpdate() {}

    void setOpen(bool open) {
        this->open = open;
    }

    bool isOpen() {
        return open;
    }
};
