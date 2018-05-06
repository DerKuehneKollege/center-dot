#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QObject>
#include <QDialog>

#include "ui_settings.h"
#include "settingsdata.h"

class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = 0);
    void setSettingsData(SettingsData &settingsData);
    SettingsData getSettingsData();

signals:

public slots:

private slots:
    void on_selectContourColorBtn_clicked();
    void on_selectFillColorBtn_clicked();
    void on_crosshairSizeSlider_valueChanged(int value);
    void on_buttonBox_accepted();

    void on_xEdit_textEdited(const QString &arg1);

    void on_yEdit_textEdited(const QString &arg1);

    void on_upBtn_clicked();

    void on_leftBtn_clicked();

    void on_downBtn_clicked();

    void on_rightBtn_clicked();

private:
    Ui::SettingsDialog ui;
    SettingsData settingsData;
};

#endif // SETTINGSDIALOG_H
