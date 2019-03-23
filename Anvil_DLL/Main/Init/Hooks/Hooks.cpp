#include "Hooks.h"

#include <d3dx9.h>
#include <iostream>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../Interfaces/Interfaces.h"
#include "../../Tools/Utilitys/Patternscaning.h"

#include "../../../Gui/ImGui/imgui.h"
#include "../../../Gui/ImGui/imgui_impl_dx9.h"
#include "../../../Gui/ImGui/imgui_impl_win32.h"
#include "../../../Gui/Gui.h"

namespace Hooks 
{
    Tools::VirtualMethodTableHook pDirectXDevice_Hooked;

    HRESULT __stdcall EndScene_Hook(IDirect3DDevice9 * pDevice) 
    {
        using fEndScene_t = HRESULT(__stdcall*)(IDirect3DDevice9 *);
        fEndScene_t EndScene_Original = (fEndScene_t)pDirectXDevice_Hooked.GetOriginal(ENDSCENE_INDEX);  // Save The Original Function

        Gui::Initialize(pDevice);
        Gui::Render();

        return EndScene_Original(pDevice);
    };

    void Initialize(void)
    {
        pDirectXDevice_Hooked.Init((void*)Interfaces::pDirectXDevice);

        pDirectXDevice_Hooked.Hook(EndScene_Hook, ENDSCENE_INDEX);
    }

    void ShutDown(void)
    {
        pDirectXDevice_Hooked.UnhookAll();
    }
}
