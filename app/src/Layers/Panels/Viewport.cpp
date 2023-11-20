#include "Viewport.h"
#include <vector>
#include <fstream>

WidgetType GetTypeByName(std::string name)
{
    if(name == "Text") return WidgetType::Text;
    else if(name == "Button") return WidgetType::Button;
    else if(name == "IntInput") return WidgetType::IntInput;
    else if(name == "FloatInput") return WidgetType::FloatInput;
    else if(name == "DoubleInput") return WidgetType::DoubleInput;
    else if(name == "TextInput") return WidgetType::TextInput;
    else if(name == "ColorPicker") return WidgetType::ColorPicker4;
    //else if(name == "Image") return WidgetType::Image;
    //else if(name == "DragFloat") return WidgetType::DragFloat;
    //else if(name == "DragInt") return WidgetType::DragInt;
    //else if(name == "ColorEdit") return WidgetType::ColorEdit4;
}

Viewport::Viewport()
{
    
}

void Viewport::Render()
{
    for(auto& widget : m_WidgetList)
    {
        switch (widget.type)
        {
        case WidgetType::Text:
                ImGui::Text(widget.name.c_str());
            break;
        case WidgetType::Button:
                ImGui::Button(widget.name.c_str());
            break;
        case WidgetType::IntInput:
                //ImGui::InputInt("int input",nullptr);
        default:
                ImGui::TextColored(ImVec4(1.0f,0.f,0.f,1.f),"ERROR!");
            break;
        }
    }
}

void Viewport::RenderProperties()
{
    if(this->selectedItem!=-1)
    {
        auto& widget = m_WidgetList[selectedItem];
        char n[25];
        strncpy(n,widget.name.c_str(),25);
        ImGui::InputText("name",n,25);
        widget.name = strcmp(n,"")?n:"(no name)";
    }
    else
    {
        ImGui::TextDisabled("(select an object)");
    }
}

void Viewport::PushData(const char* name, size_t size)
{
    ViewportWidget widget;
    widget.name = name;
    widget.type = GetTypeByName(widget.name);
    m_WidgetList.push_back(widget);
}

void Viewport::Remove(const int& i)
{
    if(i>=m_WidgetList.size())
    {
        APPAZOID_ERROR("Out of bound!");
        return;
    }
    m_WidgetList.erase(m_WidgetList.begin()+i);
}

void Viewport::SaveAs(string filename)
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        APPAZOID_ERROR("Bad File");
        return;
    }
    file<<"window(\"Example Window\");\n";
    
    for(auto& widget : m_WidgetList)
    {
        switch(widget.type)
        {
            case WidgetType::Text:
            file<<"text(\""<< widget.name <<"\");\n";
            break;
            case WidgetType::Button:
            file<<"button(\""<< widget.name <<"\");\n";
            break;
        }
    }
    file.close();
}