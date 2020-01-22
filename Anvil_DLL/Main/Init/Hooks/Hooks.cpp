#include "Hooks.h"

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../../../Gui/ImGui/imgui.h"
#include "../../../Gui/ImGui/imgui_impl_dx9.h"
#include "../../../Gui/ImGui/imgui_impl_win32.h"
#include "../../../Gui/Gui.h"

#include "../Interfaces/Interfaces.h"
#include "../../../SDK/Misc/UserCmd.h"
#include "../../Tools/VMT/VMTableHook.h"

#include <iostream>

namespace Hooks 
{
    const int ENDSCENE_INDEX = 42;
    const int RESET_INDEX = 16;
    const int CREATEMOVE_INDEX = 24;

    Tools::VirtualMethodTableHook pDirectXDevice_Hooked;
    Tools::VirtualMethodTableHook pClientMode_Hooked;

    //==================================================================================================================

    HRESULT __stdcall hkEndScene(IDirect3DDevice9 * pDevice)  // 42
    {
        using fEndScene_t = HRESULT(__stdcall*)(IDirect3DDevice9 *);
        fEndScene_t oEndScene = (fEndScene_t)pDirectXDevice_Hooked.GetOriginal(ENDSCENE_INDEX);

        Gui::Initialize(pDevice);
        Gui::Render(pDevice);

        return oEndScene(pDevice);
    }
     
    HRESULT __stdcall hkReset(IDirect3DDevice9 * pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)  // 16
    {
        using fReset_t = HRESULT(__stdcall*)(IDirect3DDevice9 *, D3DPRESENT_PARAMETERS*);
        fReset_t oReset = (fReset_t)pDirectXDevice_Hooked.GetOriginal(RESET_INDEX);

        ImGui_ImplDX9_InvalidateDeviceObjects();
        HRESULT Return = oReset(pDevice, pPresentationParameters);
        ImGui_ImplDX9_CreateDeviceObjects();

        return Return;
    }

    //==================================================================================================================

    bool __stdcall hkCreateMove(float SampleTime, SDK::CUserCmd* UserCmd) 
    {
        using fCreateMove_t = bool(__stdcall*)(float, SDK::CUserCmd*);
        fCreateMove_t oCreateMove = (fCreateMove_t) pClientMode_Hooked.GetOriginal(CREATEMOVE_INDEX);

        std::cout << "x: 0"<< " | " << "y: " << UserCmd->viewangles.y << " | " << "z: " << UserCmd->viewangles.z << std::endl;

        return oCreateMove(SampleTime, UserCmd);
    }

    //==================================================================================================================

    void Initialize(void)
    {
        // Initalize Object Hooks
        pDirectXDevice_Hooked.Init((void*)Interfaces::pDirectXDevice);
        pClientMode_Hooked.Init((void*)Interfaces::pClientMode);

        // Function Hooks
        pDirectXDevice_Hooked.Hook(hkEndScene, ENDSCENE_INDEX);
        pDirectXDevice_Hooked.Hook(hkReset, RESET_INDEX);

        pClientMode_Hooked.Hook(hkCreateMove, CREATEMOVE_INDEX);
    }

    void ShutDown(void)
    {
        pDirectXDevice_Hooked.UnhookAll();
        pClientMode_Hooked.UnhookAll();
    }
}
