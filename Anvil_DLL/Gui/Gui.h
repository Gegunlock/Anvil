#pragma once

#include <d3d9.h>

namespace Gui 
{
    void Initialize(IDirect3DDevice9 * pDevice);
    void Render(IDirect3DDevice9 * pDevice);
}