/*
    SPDX-FileCopyrightText: 2021 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "item.h"

namespace KWin
{

class SurfaceTexture;

/**
 * The SurfaceItem class represents a surface with some contents.
 */
class KWIN_EXPORT SurfaceItem : public Item
{
    Q_OBJECT

public:
    QPointF mapToWindow(const QPointF &point) const;
    virtual QPointF mapToBuffer(const QPointF &point) const = 0;

    virtual QRegion shape() const;
    virtual QRegion opaque() const;

    void addDamage(const QRegion &region);
    void resetDamage();
    QRegion damage() const;

    SurfaceTexture *texture() const;
    SurfaceTexture *previousTexture() const;

    void referencePreviousTexture();
    void unreferencePreviousTexture();

protected:
    explicit SurfaceItem(Scene::Window *window, Item *parent = nullptr);

    virtual SurfaceTexture *createTexture() = 0;
    void preprocess() override;

    void discardTexture();
    void updateTexture();

    QRegion m_damage;
    QScopedPointer<SurfaceTexture> m_texture;
    QScopedPointer<SurfaceTexture> m_previousTexture;
    int m_referenceTextureCounter = 0;

    friend class Scene::Window;
};

class KWIN_EXPORT PlatformSurfaceTexture
{
public:
    virtual ~PlatformSurfaceTexture();

    virtual bool isValid() const = 0;
};

class KWIN_EXPORT SurfaceTexture : public QObject
{
    Q_OBJECT

public:
    explicit SurfaceTexture(PlatformSurfaceTexture *platformTexture, QObject *parent = nullptr);

    PlatformSurfaceTexture *platformTexture() const;

    bool hasAlphaChannel() const;
    QSize size() const;
    QRect contentsRect() const;

    bool isDiscarded() const;
    void markAsDiscarded();

    virtual void create() = 0;
    virtual void update();

    virtual bool isValid() const = 0;

protected:
    QSize m_size;
    QRect m_contentsRect;
    bool m_hasAlphaChannel = false;

private:
    QScopedPointer<PlatformSurfaceTexture> m_platformTexture;
    bool m_isDiscarded = false;
};

} // namespace KWin
