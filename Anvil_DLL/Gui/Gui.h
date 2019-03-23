#pragma once

#include <d3d9.h>

namespace Gui 
{
    bool Initialize(IDirect3DDevice9 * pDevice);
    void Render(void);
}