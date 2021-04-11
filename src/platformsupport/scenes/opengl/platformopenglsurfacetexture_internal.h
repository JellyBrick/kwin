/*
    SPDX-FileCopyrightText: 2021 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "platformopenglsurfacetexture.h"

namespace KWin
{

class KWIN_EXPORT PlatformOpenGLSurfaceTextureInternal : public PlatformOpenGLSurfaceTexture
{
public:
    PlatformOpenGLSurfaceTextureInternal(OpenGLBackend *backend, SurfaceTextureInternal *pixmap);

protected:
    SurfaceTextureInternal *m_pixmap;
};

} // namespace KWin
