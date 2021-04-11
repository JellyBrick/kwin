/*
    SPDX-FileCopyrightText: 2021 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "surfaceitem.h"

namespace KWin
{

/**
 * The SurfaceItemInternal class represents an internal surface in the scene.
 */
class KWIN_EXPORT SurfaceItemInternal : public SurfaceItem
{
    Q_OBJECT

public:
    explicit SurfaceItemInternal(Scene::Window *window, Item *parent = nullptr);

    QPointF mapToBuffer(const QPointF &point) const override;
    QRegion shape() const override;

private Q_SLOTS:
    void handleBufferGeometryChanged(Toplevel *toplevel, const QRect &old);

protected:
    SurfaceTexture *createTexture() override;
};

class KWIN_EXPORT SurfaceTextureInternal final : public SurfaceTexture
{
    Q_OBJECT

public:
    explicit SurfaceTextureInternal(SurfaceItemInternal *item, QObject *parent = nullptr);

    QOpenGLFramebufferObject *fbo() const;
    QImage image() const;

    void create() override;
    void update() override;
    bool isValid() const override;

private:
    SurfaceItemInternal *m_item;
    QSharedPointer<QOpenGLFramebufferObject> m_fbo;
    QImage m_rasterBuffer;
};

} // namespace KWin
