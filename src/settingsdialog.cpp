#include <QColorDialog>
#include <QDebug>

#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

void SettingsDialog::setSettingsData(SettingsData &settingsData)
{
    this->settingsData = settingsData;

    // update position view
    ui.xEdit->setText(QString::number(settingsData.xPosition));
    ui.yEdit->setText(QString::number(settingsData.yPosition));

    // update crosshair size view
    ui.crosshairSizeSlider->setValue(settingsData.crosshairSize);

    // update contour color view
    if (this->settingsData.contourColor.isValid()) {
        QPalette palette = ui.contourColorBox->palette();
        palette.setColor(backgroundRole(), this->settingsData.contourColor);
        ui.contourColorBox->setPalette(palette);
    }

    // update fill color view
    if (this->settingsData.fillColor.isValid()) {
        QPalette palette = ui.fillColorBox->palette();
        palette.setColor(backgroundRole(), this->settingsData.fillColor);
        ui.fillColorBox->setPalette(palette);
    }
}

SettingsData SettingsDialog::getSettingsData()
{
    return this->settingsData;
}

void SettingsDialog::on_xEdit_textEdited(const QString &arg1)
{
    bool validIntEntered = false;
    int newXvalue = arg1.toInt(&validIntEntered);

    if (validIntEntered) {
        settingsData.xPosition = newXvalue;
    } else {
        ui.xEdit->setText(QString::number(settingsData.xPosition));
    }
}


void SettingsDialog::on_yEdit_textEdited(const QString &arg1)
{
    bool validIntEntered = false;
    int newYvalue = arg1.toInt(&validIntEntered);

    if (validIntEntered) {
        settingsData.yPosition = newYvalue;
    } else {
        ui.yEdit->setText(QString::number(settingsData.yPosition));
    }
}

void SettingsDialog::on_rightBtn_clicked()
{
    settingsData.xPosition++;
    ui.xEdit->setText(QString::number(settingsData.xPosition));
}

void SettingsDialog::on_leftBtn_clicked()
{
    settingsData.xPosition--;
    ui.xEdit->setText(QString::number(settingsData.xPosition));
}

void SettingsDialog::on_downBtn_clicked()
{
    settingsData.yPosition++;
    ui.yEdit->setText(QString::number(settingsData.yPosition));
}

void SettingsDialog::on_upBtn_clicked()
{
    settingsData.yPosition--;
    ui.yEdit->setText(QString::number(settingsData.yPosition));
}

void SettingsDialog::on_crosshairSizeSlider_valueChanged(int value)
{
    qDebug() << "Crosshair size value changed to" << value;

    if (value >=1 && value <= 10) {
        ui.crosshairSizeValueLbl->setText(QString::number(value) + " px");
        settingsData.crosshairSize = value;
    }
}

void SettingsDialog::on_selectContourColorBtn_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    if (color.isValid()) {
        settingsData.contourColor = color;

        QPalette palette = ui.contourColorBox->palette();
        palette.setColor(backgroundRole(), color);
        ui.contourColorBox->setPalette(palette);
    }
}

void SettingsDialog::on_selectFillColorBtn_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if (color.isValid()) {
        settingsData.fillColor = color;

        QPalette palette = ui.fillColorBox->palette();
        palette.setColor(backgroundRole(), color);
        ui.fillColorBox->setPalette(palette);
    }
}

void SettingsDialog::on_buttonBox_accepted()
{
    qDebug() << "Settings submitted";
}
