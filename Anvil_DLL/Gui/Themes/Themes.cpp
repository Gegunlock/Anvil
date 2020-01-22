#include "Themes.h"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

void Gui::LoadDefaultTheme(void) 
{
    ImGuiStyle& Style = ImGui::GetStyle();

    Style.Alpha = 1.0f;
    Style.WindowPadding = ImVec2(8, 8);
    Style.WindowRounding = 0.0f;
    Style.WindowBorderSize = 1.0f;
    Style.WindowMinSize = ImVec2(32, 32);
    Style.WindowTitleAlign = ImVec2(0.5f, 0.5f);

    ImGui::StyleColorsClassic(&Style);
}
