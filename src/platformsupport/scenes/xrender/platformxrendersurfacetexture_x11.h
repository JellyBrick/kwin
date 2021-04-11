/*
    SPDX-FileCopyrightText: 2021 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "surfaceitem_x11.h"

#include <xcb/render.h>

namespace KWin
{

class KWIN_EXPORT PlatformXrenderSurfaceTextureX11 : public PlatformSurfaceTexture
{
public:
    explicit PlatformXrenderSurfaceTextureX11(SurfaceTextureX11 *texture);
    ~PlatformXrenderSurfaceTextureX11() override;

    bool isValid() const override;

    bool create();
    xcb_render_picture_t picture() const;

private:
    SurfaceTextureX11 *m_texture;
    xcb_render_picture_t m_picture = XCB_RENDER_PICTURE_NONE;
};

} // namespace KWin
