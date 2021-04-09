/*
    KWin - the KDE window manager
    This file is part of the KDE project.

    SPDX-FileCopyrightText: 2013 Martin Gräßlin <mgraesslin@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "qpainterbackend.h"
#include "platformqpaintersurfacetexture_internal.h"
#include "platformqpaintersurfacetexture_wayland.h"
#include <logging.h>

#include <QtGlobal>

namespace KWin
{

QPainterBackend::QPainterBackend()
    : m_failed(false)
{
}

QPainterBackend::~QPainterBackend()
{
}

PlatformSurfaceTexture *QPainterBackend::createPlatformSurfaceTextureInternal(SurfaceTextureInternal *texture)
{
    return new PlatformQPainterSurfaceTextureInternal(this, texture);
}

PlatformSurfaceTexture *QPainterBackend::createPlatformSurfaceTextureWayland(SurfaceTextureWayland *texture)
{
    return new PlatformQPainterSurfaceTextureWayland(this, texture);
}

void QPainterBackend::screenGeometryChanged(const QSize &size)
{
    Q_UNUSED(size)
}

void QPainterBackend::setFailed(const QString &reason)
{
    qCWarning(KWIN_QPAINTER) << "Creating the QPainter backend failed: " << reason;
    m_failed = true;
}

}
