/********************************************************************************
** Form generated from reading UI file 'dialogobjectedit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOBJECTEDIT_H
#define UI_DIALOGOBJECTEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "npcpreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_DialogObjectEdit
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *NpcName;
    QLabel *label_10;
    QSpinBox *npcGraphicSizeSpin_h;
    QLabel *label;
    QComboBox *objectListCombobox;
    QSpinBox *npcGraphicSizeSpin_w;
    QLabel *label_2;
    QLabel *label_8;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBoxType;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QSpinBox *spinBox_timer;
    QSpinBox *spinBox_limit;
    QSpinBox *spinBox_speed;
    QLabel *label_7;
    QCheckBox *checkBox;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    npcPreviewArea *npcPreviewAreaWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpinBox *spinBox;

    void setupUi(QDialog *DialogObjectEdit)
    {
        if (DialogObjectEdit->objectName().isEmpty())
            DialogObjectEdit->setObjectName(QString::fromUtf8("DialogObjectEdit"));
        DialogObjectEdit->resize(781, 406);
        gridWidget = new QWidget(DialogObjectEdit);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 0, 800, 400));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridWidget->setMinimumSize(QSize(800, 0));
        gridWidget->setMaximumSize(QSize(800, 400));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalWidget = new QWidget(gridWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, 20, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 20);
        NpcName = new QLineEdit(horizontalWidget);
        NpcName->setObjectName(QString::fromUtf8("NpcName"));

        gridLayout->addWidget(NpcName, 0, 1, 1, 2);

        label_10 = new QLabel(horizontalWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 2);

        npcGraphicSizeSpin_h = new QSpinBox(horizontalWidget);
        npcGraphicSizeSpin_h->setObjectName(QString::fromUtf8("npcGraphicSizeSpin_h"));
        npcGraphicSizeSpin_h->setMinimum(8);
        npcGraphicSizeSpin_h->setMaximum(64);
        npcGraphicSizeSpin_h->setValue(16);

        gridLayout->addWidget(npcGraphicSizeSpin_h, 3, 2, 1, 1);

        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        objectListCombobox = new QComboBox(horizontalWidget);
        objectListCombobox->setObjectName(QString::fromUtf8("objectListCombobox"));

        gridLayout->addWidget(objectListCombobox, 1, 2, 1, 1);

        npcGraphicSizeSpin_w = new QSpinBox(horizontalWidget);
        npcGraphicSizeSpin_w->setObjectName(QString::fromUtf8("npcGraphicSizeSpin_w"));
        npcGraphicSizeSpin_w->setMinimum(8);
        npcGraphicSizeSpin_w->setMaximum(64);
        npcGraphicSizeSpin_w->setValue(16);

        gridLayout->addWidget(npcGraphicSizeSpin_w, 2, 2, 1, 1);

        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_8 = new QLabel(horizontalWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(horizontalWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 1);

        comboBoxType = new QComboBox(horizontalWidget);
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));

        gridLayout->addWidget(comboBoxType, 4, 2, 1, 1);

        label_6 = new QLabel(horizontalWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_5 = new QLabel(horizontalWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        spinBox_timer = new QSpinBox(horizontalWidget);
        spinBox_timer->setObjectName(QString::fromUtf8("spinBox_timer"));
        spinBox_timer->setMaximum(99999);

        gridLayout->addWidget(spinBox_timer, 5, 2, 1, 1);

        spinBox_limit = new QSpinBox(horizontalWidget);
        spinBox_limit->setObjectName(QString::fromUtf8("spinBox_limit"));
        spinBox_limit->setMaximum(99999);

        gridLayout->addWidget(spinBox_limit, 7, 2, 1, 1);

        spinBox_speed = new QSpinBox(horizontalWidget);
        spinBox_speed->setObjectName(QString::fromUtf8("spinBox_speed"));
        spinBox_speed->setMaximum(99999);

        gridLayout->addWidget(spinBox_speed, 6, 2, 1, 1);

        label_7 = new QLabel(horizontalWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        checkBox = new QCheckBox(horizontalWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 8, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        verticalWidget = new QWidget(horizontalWidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalWidget->setMaximumSize(QSize(16777215, 400));
        verticalWidget->setStyleSheet(QString::fromUtf8("border: 1px solid green;"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 1, -1, -1);
        verticalWidget_2 = new QWidget(verticalWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        sizePolicy1.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy1);
        verticalWidget_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        verticalLayout_2 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(verticalWidget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 334, 305));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setAutoFillBackground(false);
        npcPreviewAreaWidget = new npcPreviewArea(scrollAreaWidgetContents);
        npcPreviewAreaWidget->setObjectName(QString::fromUtf8("npcPreviewAreaWidget"));
        npcPreviewAreaWidget->setGeometry(QRect(0, 0, 181, 171));
        npcPreviewAreaWidget->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(verticalWidget_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(verticalWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(label_4);

        spinBox = new QSpinBox(verticalWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(5);
        spinBox->setMaximum(9999);
        spinBox->setValue(20);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(verticalWidget);


        gridLayout_2->addWidget(horizontalWidget, 0, 0, 1, 1);


        retranslateUi(DialogObjectEdit);

        QMetaObject::connectSlotsByName(DialogObjectEdit);
    } // setupUi

    void retranslateUi(QDialog *DialogObjectEdit)
    {
        DialogObjectEdit->setWindowTitle(QApplication::translate("DialogObjectEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        NpcName->setText(QApplication::translate("DialogObjectEdit", "My Object", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DialogObjectEdit", "Graphic Width: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogObjectEdit", "Graphic Height:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogObjectEdit", "Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogObjectEdit", "Graphic:", 0, QApplication::UnicodeUTF8));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("DialogObjectEdit", "Moving Platform (up/down)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Moving platform (left/right)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Disapearing Block", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Energy Tank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Weapons Tank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Energy Pill (big)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Weapons Pill (big)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Enegy Pill (small)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Weapons Pill (small)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "1 UP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Faller Platform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogObjectEdit", "Flyier Platform", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("DialogObjectEdit", "Type:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogObjectEdit", "Timer:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogObjectEdit", "Limit:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogObjectEdit", "Speed:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("DialogObjectEdit", "CheckBox", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogObjectEdit", "Duration:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogObjectEdit: public Ui_DialogObjectEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOBJECTEDIT_H
