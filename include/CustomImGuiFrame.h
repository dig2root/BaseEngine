#include "ImGuiFrame.h"

class CustomImGuiFrame : public ImGuiFrame {
public:
	virtual void Update() override;

private:
	float clear_color[3] = { .0f, .0f, .0f };
	void change_clear_color(float r, float g, float b);
};