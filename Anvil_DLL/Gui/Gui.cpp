#include "Gui.h"

#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

namespace Gui
{
    using WNDPROC = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
    WNDPROC WndProc_Original;

    LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return CallWindowProc(WndProc_Original, hWnd, uMsg, wParam, lParam);
    }

    bool Initialize(IDirect3DDevice9 * pDevice)
    {
        static bool Initialized = false;
        if (Initialized == false) 
        {
            Initialized = true;
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();

            ImGui_ImplWin32_Init(FindWindowA(NULL, "Counter-Strike: Global Offensive"));
            ImGui_ImplDX9_Init(pDevice);
            WndProc_Original = (WNDPROC)SetWindowLongPtr(FindWindowA(NULL, "Counter-Strike: Global Offensive"), GWL_WNDPROC, (LONG_PTR)WndProc);
        }
        return false;
    }

    void Render(void)
    {
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    }
}

