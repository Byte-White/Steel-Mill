#include "Tools.h"

ToolsPanel::ToolsPanel()
{

}

void ToolsPanel::Render()
{
    ImGui::Button("Text");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "Text";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }

    ImGui::Button("Button");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "Button";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }

    ImGui::Button("IntInput");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "FloatInput";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }
    
    ImGui::Button("FloatInput");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "FloatInput";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }
    ImGui::Button("DoubleInput");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "DoubleInput";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }
    
    ImGui::Button("TextInput");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "TextInput";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }

    ImGui::Button("ColorPicker");
    if(ImGui::BeginDragDropSource())
    {
        const char* data = "ColorPicker";
        ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
        ImGui::EndDragDropSource();
    }
    // ImGui::Button("Image");
    // if(ImGui::BeginDragDropSource())
    // {
    //     const char* data = "Image";
    //     ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
    //     ImGui::EndDragDropSource();
    // }

    // ImGui::Button("DragFloat");
    // if(ImGui::BeginDragDropSource())
    // {
    //     const char* data = "DragFloat";
    //     ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
    //     ImGui::EndDragDropSource();
    // }

    // ImGui::Button("DragInt");
    // if(ImGui::BeginDragDropSource())
    // {
    //     const char* data = "DragInt";
    //     ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
    //     ImGui::EndDragDropSource();
    // }

    // ImGui::Button("ColorEdit");
    // if(ImGui::BeginDragDropSource())
    // {
    //     const char* data = "ColorEdit";
    //     ImGui::SetDragDropPayload("TOOL_ITEM",data,strlen(data));
    //     ImGui::EndDragDropSource();
    // }
}