/*
    SPDX-FileCopyrightText: 2021 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "platformopenglsurfacetexture_wayland.h"

#include <epoxy/egl.h>

namespace KWin
{

class AbstractEglBackend;

class KWIN_EXPORT BasicEGLSurfaceTextureWayland : public PlatformOpenGLSurfaceTextureWayland
{
public:
    BasicEGLSurfaceTextureWayland(OpenGLBackend *backend, SurfaceTextureWayland *pixmap);
    ~BasicEGLSurfaceTextureWayland() override;

    AbstractEglBackend *backend() const;

    bool create() override;
    void update(const QRegion &region) override;

private:
    bool loadShmTexture(KWaylandServer::BufferInterface *buffer);
    void updateShmTexture(KWaylandServer::BufferInterface *buffer, const QRegion &region);
    bool loadEglTexture(KWaylandServer::BufferInterface *buffer);
    void updateEglTexture(KWaylandServer::BufferInterface *buffer);
    bool loadDmabufTexture(KWaylandServer::BufferInterface *buffer);
    void updateDmabufTexture(KWaylandServer::BufferInterface *buffer);
    EGLImageKHR attach(KWaylandServer::BufferInterface *buffer);
    void destroy();

    enum class BufferType {
        None,
        Shm,
        DmaBuf,
        Egl,
    };

    EGLImageKHR m_image = EGL_NO_IMAGE_KHR;
    BufferType m_bufferType = BufferType::None;
    GLuint m_textureId = 0;
};

} // namespace KWin
