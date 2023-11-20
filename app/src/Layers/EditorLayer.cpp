#include "EditorLayer.h"

EditorLayer::EditorLayer()
{

}

void EditorLayer::OnConstruction()
{

}

void EditorLayer::OnEvent(az::Event& e)
{
	az::EventDispatcher dispatcher(e);
}


void EditorLayer::OnUIRender()
{
	ImGui::Begin("Tools");
	m_ToolsPanel.Render();
	ImGui::End();
	
	ImGui::Begin("Build");
	static char filename[30] = "project.st";
	ImGui::InputText("filepath",filename,30);
	if(ImGui::Button("Save As"))
		m_Viewport.SaveAs(filename);
	ImGui::End();

	ImGui::Begin("Viewport");
	ImGui::BeginChild("viewport_child");
	m_Viewport.Render();
	ImGui::EndChild();
	if(ImGui::BeginDragDropTarget()) // Drag drop on the whole window
    {
        if(const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("TOOL_ITEM"))
        {
            const char* data = (const char*)payload->Data;
            az::Log::Info("data: {0}",data);
			m_Viewport.PushData(data,payload->DataSize);
        }
        ImGui::EndDragDropTarget();
    }
	ImGui::End();

	ImGui::Begin("Properties");
	m_Viewport.RenderProperties();
	ImGui::End();

	ImGui::Begin("Widget View");
	for(int i = 0; i<m_Viewport.GetWidgetList().size();i++)
	{
		ViewportWidget& widget = m_Viewport.GetWidgetList()[i];
		if(ImGui::Button(widget.name.c_str())) m_Viewport.selectedItem = i;	//ImGui::Text("%s",widget.name.c_str());
		ImGui::SameLine();
		if(ImGui::ArrowButton((widget.name+"_arrowbtn").c_str(),ImGuiDir_Left))
			m_Viewport.Remove(i);

	}
	ImGui::End();
	
}
