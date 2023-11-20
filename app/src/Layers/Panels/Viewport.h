#pragma once
#include "Tools.h"
#include "Appazoid/Appazoid.h"
#include <vector>

enum class WidgetType
{
    None = 0,
    
    //Text
    Text,
    ColorText,
    DisabledText,
    WrapText,

    //Buttons
    Button,
    ButtonImage,
    
    //Images
    Image,

    //Sliders
    DragFloat,
    DragFloat2,
    DragFloat3,
    
    DragInt,
    DragInt2,
    DragInt3,
    
    // Editors and pickers
    ColorEdit3,
    ColorEdit4,
    ColorPicker3,
    ColorPicker4,


    //Inputs
    IntInput,
    FloatInput,
    DoubleInput,
    TextInput
    //Trees

    //Selectables

    //List Boxes

    //Data Plotting
};

struct ViewportWidget 
{
    std::string name;
    WidgetType type;
    int x,y;
    bool sameline = false;
    float color[4];
    
};

class Viewport
{
    std::vector<ViewportWidget> m_WidgetList;
    public:
    int selectedItem = -1;
    Viewport();
    void Render();
    void RenderProperties();
    std::vector<ViewportWidget>& GetWidgetList() { return m_WidgetList; }
    void Remove(const int& i);
    void PushData(const char* name, size_t size);
    void SaveAs(string filename);
};