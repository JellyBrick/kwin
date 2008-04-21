/********************************************************************
 KWin - the KDE window manager
 This file is part of the KDE project.

 Copyright (C) 2008 Cédric Borgese <cedric.borgese@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#ifndef KWIN_WOBBLY_CONFIG_H
#define KWIN_WOBBLY_CONFIG_H

#define KDE3_SUPPORT
#include <kcmodule.h>
#undef KDE3_SUPPORT

#include "ui_wobblywindows_config.h"

class KActionCollection;

namespace KWin
{

class WobblyWindowsEffectConfig : public KCModule
{
    Q_OBJECT
public:
    explicit WobblyWindowsEffectConfig(QWidget* parent = 0, const QVariantList& args = QVariantList());
    ~WobblyWindowsEffectConfig();

public slots:
    virtual void save();
    virtual void load();
    virtual void defaults();

private:
    enum GridFilter
    {
        NoFilter,
        FourRingLinearMean,
        HeightRingLinearMean,
        MeanWithMean,
        MeanWithMedian
    };

private slots:

    void slotSpStiffness(double);
    void slotSlStiffness(int);
    void slotSpDrag(double);
    void slotSlDrag(int);
    void slotSpMovFactor(double);
    void slotSlMovFactor(int);

    void slotGridParameterSelected(int);
    void slotRbNone(bool);
    void slotRbFourRingMean(bool);
    void slotRbHeightRingMean(bool);
    void slotRbMeanMean(bool);
    void slotRbMeanMedian(bool);

    void slotSpMinVel(double);
    void slotSlMinVel(int);
    void slotSpMaxVel(double);
    void slotSlMaxVel(int);
    void slotSpStopVel(double);
    void slotSlStopVel(int);
    void slotSpMinAcc(double);
    void slotSlMinAcc(int);
    void slotSpMaxAcc(double);
    void slotSlMaxAcc(int);
    void slotSpStopAcc(double);
    void slotSlStopAcc(int);

private:
    Ui::WobblyWindowsEffectConfigForm m_ui;

    GridFilter velocityFilter;
    GridFilter accelerationFilter;
};

} // namespace

#endif
