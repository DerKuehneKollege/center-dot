#ifndef SETTINGSDATA_H
#define SETTINGSDATA_H

#include <QColor>

struct SettingsData {
    int    xPosition;
    int    yPosition;
    int    crosshairSize;
    QColor contourColor;
    QColor fillColor;
};

#endif // SETTINGSDATA_H
