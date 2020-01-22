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
#include "../../Tools/VMT/VmtHook.h"

#include "../../../Features/Features.h"

#include "../../Settings.h"

#include <iostream>

const int ENDSCENE_INDEX = 42;
const int RESET_INDEX = 16;
const int CREATEMOVE_INDEX = 24;
const int LOCKCURSOR_INDEX = 67;

namespace Hooks 
{
    Tools::VmtHook pDirectXDevice_Hooked;
    Tools::VmtHook pClientMode_Hooked;
    Tools::VmtHook pSurface_Hooked;

    // pDirectXDevice ==================================================================================================

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
        ImGui_ImplDX9_CreateDeviceObjects();

        return  oReset(pDevice, pPresentationParameters);
    }

    // pClientMode =====================================================================================================

    bool __stdcall hkCreateMove(float SampleTime, SDK::CUserCmd* UserCmd)  // 24
    {
        using fCreateMove_t = bool(__stdcall*)(float, SDK::CUserCmd*);
        fCreateMove_t oCreateMove = (fCreateMove_t) pClientMode_Hooked.GetOriginal(CREATEMOVE_INDEX);

        SDK::IClientEntity* ClientEntity = (Interfaces::pEntityList->GetClientEntity(Interfaces::pEngine->GetLocalPlayer()));

        Features::Bunnyhop(ClientEntity, UserCmd);

        return oCreateMove(SampleTime, UserCmd);
    }

    // pSurface =========================================================================================================

    void __fastcall hkLockCursor(void* Self)  // 67
    {
        using fLockCursor_t = void(__fastcall*)(void*);
        fLockCursor_t oLockCursor = (fLockCursor_t)pSurface_Hooked.GetOriginal(LOCKCURSOR_INDEX);

        if (Config::Gui::Toggle) 
        {
            Interfaces::pSurface->UnlockCursor();
            Interfaces::pInputSystem->ResetInputState();
            return;
        }

        oLockCursor(Self);
    }

    //==================================================================================================================

    void Initialize(void)
    {
        // Initalize Vmt Hooks
        pDirectXDevice_Hooked.Init((void*)Interfaces::pDirectXDevice);
        pClientMode_Hooked.Init((void*)Interfaces::pClientMode);
        pSurface_Hooked.Init((void*)Interfaces::pSurface);

        // Function Hooks
        pDirectXDevice_Hooked.Hook(hkEndScene, ENDSCENE_INDEX);
        pDirectXDevice_Hooked.Hook(hkReset, RESET_INDEX);

        pClientMode_Hooked.Hook(hkCreateMove, CREATEMOVE_INDEX);

        pSurface_Hooked.Hook(hkLockCursor, LOCKCURSOR_INDEX);
    }

    void ShutDown(void)
    {
        pDirectXDevice_Hooked.UnhookAll();
        pClientMode_Hooked.UnhookAll();
        pSurface_Hooked.UnhookAll();
    }
}
