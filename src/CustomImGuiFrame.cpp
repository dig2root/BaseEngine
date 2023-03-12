#include "CustomImGuiFrame.h"
#include "glad/glad.h"

void CustomImGuiFrame::Update() {

	static float f = 0.0f;
	static int counter = 0;

	ImGui::Begin("CustomImGui Hello, world!");              // Create a window called "Hello, world!" and append into it.
	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

	bool clear_color_changed = ImGui::ColorEdit3("clear color", (float*)clear_color); // Edit 3 floats representing a color

	if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	ImGui::End();

	if (clear_color_changed) {
		change_clear_color(clear_color[0], clear_color[1], clear_color[2]);
	}
}

void CustomImGuiFrame::change_clear_color(float r, float g, float b) {
	glClearColor(r, g, b, 1.00f);
}