/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *dialogLayout;
    QLabel *crosshairSizeLbl;
    QHBoxLayout *crosshairSizeHbox;
    QSlider *crosshairSizeSlider;
    QLabel *crosshairSizeValueLbl;
    QLabel *contourColorLbl;
    QHBoxLayout *contourColorHbox;
    QFrame *contourColorBox;
    QPushButton *selectContourColorBtn;
    QLabel *fillColorLbl;
    QHBoxLayout *fillColorHbox;
    QFrame *fillColorBox;
    QPushButton *selectFillColorBtn;
    QLabel *positionLbl;
    QHBoxLayout *positionHbox;
    QLabel *xLbl;
    QLineEdit *xEdit;
    QLabel *yLbl;
    QLineEdit *yEdit;
    QGridLayout *dpadGridLayout;
    QSpacerItem *dpadLeftSpacer;
    QSpacerItem *dpadRightSpacer;
    QToolButton *upBtn;
    QToolButton *leftBtn;
    QToolButton *rightBtn;
    QToolButton *downBtn;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(SettingsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dialogLayout = new QFormLayout();
        dialogLayout->setObjectName(QStringLiteral("dialogLayout"));
        crosshairSizeLbl = new QLabel(SettingsDialog);
        crosshairSizeLbl->setObjectName(QStringLiteral("crosshairSizeLbl"));

        dialogLayout->setWidget(3, QFormLayout::LabelRole, crosshairSizeLbl);

        crosshairSizeHbox = new QHBoxLayout();
        crosshairSizeHbox->setObjectName(QStringLiteral("crosshairSizeHbox"));
        crosshairSizeSlider = new QSlider(SettingsDialog);
        crosshairSizeSlider->setObjectName(QStringLiteral("crosshairSizeSlider"));
        crosshairSizeSlider->setMinimum(1);
        crosshairSizeSlider->setMaximum(10);
        crosshairSizeSlider->setOrientation(Qt::Horizontal);
        crosshairSizeSlider->setTickPosition(QSlider::TicksBelow);
        crosshairSizeSlider->setTickInterval(1);

        crosshairSizeHbox->addWidget(crosshairSizeSlider);

        crosshairSizeValueLbl = new QLabel(SettingsDialog);
        crosshairSizeValueLbl->setObjectName(QStringLiteral("crosshairSizeValueLbl"));

        crosshairSizeHbox->addWidget(crosshairSizeValueLbl);


        dialogLayout->setLayout(3, QFormLayout::FieldRole, crosshairSizeHbox);

        contourColorLbl = new QLabel(SettingsDialog);
        contourColorLbl->setObjectName(QStringLiteral("contourColorLbl"));
        contourColorLbl->setFrameShadow(QFrame::Sunken);

        dialogLayout->setWidget(4, QFormLayout::LabelRole, contourColorLbl);

        contourColorHbox = new QHBoxLayout();
        contourColorHbox->setObjectName(QStringLiteral("contourColorHbox"));
        contourColorBox = new QFrame(SettingsDialog);
        contourColorBox->setObjectName(QStringLiteral("contourColorBox"));
        contourColorBox->setAutoFillBackground(true);
        contourColorBox->setFrameShape(QFrame::Box);
        contourColorBox->setFrameShadow(QFrame::Plain);

        contourColorHbox->addWidget(contourColorBox);

        selectContourColorBtn = new QPushButton(SettingsDialog);
        selectContourColorBtn->setObjectName(QStringLiteral("selectContourColorBtn"));

        contourColorHbox->addWidget(selectContourColorBtn);


        dialogLayout->setLayout(4, QFormLayout::FieldRole, contourColorHbox);

        fillColorLbl = new QLabel(SettingsDialog);
        fillColorLbl->setObjectName(QStringLiteral("fillColorLbl"));

        dialogLayout->setWidget(5, QFormLayout::LabelRole, fillColorLbl);

        fillColorHbox = new QHBoxLayout();
        fillColorHbox->setObjectName(QStringLiteral("fillColorHbox"));
        fillColorBox = new QFrame(SettingsDialog);
        fillColorBox->setObjectName(QStringLiteral("fillColorBox"));
        fillColorBox->setAutoFillBackground(true);
        fillColorBox->setFrameShape(QFrame::Box);
        fillColorBox->setFrameShadow(QFrame::Plain);

        fillColorHbox->addWidget(fillColorBox);

        selectFillColorBtn = new QPushButton(SettingsDialog);
        selectFillColorBtn->setObjectName(QStringLiteral("selectFillColorBtn"));

        fillColorHbox->addWidget(selectFillColorBtn);


        dialogLayout->setLayout(5, QFormLayout::FieldRole, fillColorHbox);

        positionLbl = new QLabel(SettingsDialog);
        positionLbl->setObjectName(QStringLiteral("positionLbl"));

        dialogLayout->setWidget(0, QFormLayout::LabelRole, positionLbl);

        positionHbox = new QHBoxLayout();
        positionHbox->setObjectName(QStringLiteral("positionHbox"));
        xLbl = new QLabel(SettingsDialog);
        xLbl->setObjectName(QStringLiteral("xLbl"));

        positionHbox->addWidget(xLbl);

        xEdit = new QLineEdit(SettingsDialog);
        xEdit->setObjectName(QStringLiteral("xEdit"));

        positionHbox->addWidget(xEdit);

        yLbl = new QLabel(SettingsDialog);
        yLbl->setObjectName(QStringLiteral("yLbl"));

        positionHbox->addWidget(yLbl);

        yEdit = new QLineEdit(SettingsDialog);
        yEdit->setObjectName(QStringLiteral("yEdit"));

        positionHbox->addWidget(yEdit);


        dialogLayout->setLayout(0, QFormLayout::FieldRole, positionHbox);

        dpadGridLayout = new QGridLayout();
        dpadGridLayout->setObjectName(QStringLiteral("dpadGridLayout"));
        dpadLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        dpadGridLayout->addItem(dpadLeftSpacer, 2, 0, 1, 1);

        dpadRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        dpadGridLayout->addItem(dpadRightSpacer, 2, 4, 1, 1);

        upBtn = new QToolButton(SettingsDialog);
        upBtn->setObjectName(QStringLiteral("upBtn"));
        upBtn->setMinimumSize(QSize(25, 25));
        upBtn->setMaximumSize(QSize(30, 16777215));
        upBtn->setArrowType(Qt::UpArrow);

        dpadGridLayout->addWidget(upBtn, 0, 2, 1, 1);

        leftBtn = new QToolButton(SettingsDialog);
        leftBtn->setObjectName(QStringLiteral("leftBtn"));
        leftBtn->setMinimumSize(QSize(25, 25));
        leftBtn->setMaximumSize(QSize(30, 16777215));
        leftBtn->setArrowType(Qt::LeftArrow);

        dpadGridLayout->addWidget(leftBtn, 2, 1, 1, 1);

        rightBtn = new QToolButton(SettingsDialog);
        rightBtn->setObjectName(QStringLiteral("rightBtn"));
        rightBtn->setMinimumSize(QSize(25, 25));
        rightBtn->setMaximumSize(QSize(30, 16777215));
        rightBtn->setArrowType(Qt::RightArrow);

        dpadGridLayout->addWidget(rightBtn, 2, 3, 1, 1);

        downBtn = new QToolButton(SettingsDialog);
        downBtn->setObjectName(QStringLiteral("downBtn"));
        downBtn->setMinimumSize(QSize(25, 25));
        downBtn->setMaximumSize(QSize(30, 16777215));
        downBtn->setArrowType(Qt::DownArrow);

        dpadGridLayout->addWidget(downBtn, 4, 2, 1, 1);


        dialogLayout->setLayout(1, QFormLayout::FieldRole, dpadGridLayout);


        verticalLayout_2->addLayout(dialogLayout);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", 0));
        crosshairSizeLbl->setText(QApplication::translate("SettingsDialog", "Crosshair size:", 0));
        crosshairSizeValueLbl->setText(QApplication::translate("SettingsDialog", "3 px", 0));
        contourColorLbl->setText(QApplication::translate("SettingsDialog", "Contour color:", 0));
        selectContourColorBtn->setText(QApplication::translate("SettingsDialog", "Select...", 0));
        fillColorLbl->setText(QApplication::translate("SettingsDialog", "Fill color:", 0));
        selectFillColorBtn->setText(QApplication::translate("SettingsDialog", "Select...", 0));
        positionLbl->setText(QApplication::translate("SettingsDialog", "Position:", 0));
        xLbl->setText(QApplication::translate("SettingsDialog", "x:", 0));
        yLbl->setText(QApplication::translate("SettingsDialog", "y:", 0));
        upBtn->setText(QApplication::translate("SettingsDialog", "...", 0));
        leftBtn->setText(QApplication::translate("SettingsDialog", "...", 0));
        rightBtn->setText(QApplication::translate("SettingsDialog", "...", 0));
        downBtn->setText(QApplication::translate("SettingsDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
