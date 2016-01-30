/********************************************************************************
** Form generated from reading UI file 'dialognpcedit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNPCEDIT_H
#define UI_DIALOGNPCEDIT_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "npcpreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_DialogNPCEdit
{
public:
    QGridLayout *gridLayout_3;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *NpcName;
    QLabel *label_10;
    QSpinBox *npcGraphicSizeSpin_h;
    QSpinBox *NpcHP;
    QLabel *label;
    QComboBox *npcListCombobox;
    QSpinBox *npcGraphicSizeSpin_w;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QCheckBox *checkBoxCanShoot;
    QLabel *label_5;
    QComboBox *comboBoxIA;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBoxShieldType;
    QLabel *label_6;
    QCheckBox *isBossCheckbox;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QSpinBox *speed_spin;
    QSpinBox *range_spin;
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
    QComboBox *frameTypeCombo;

    void setupUi(QDialog *DialogNPCEdit)
    {
        if (DialogNPCEdit->objectName().isEmpty())
            DialogNPCEdit->setObjectName(QString::fromUtf8("DialogNPCEdit"));
        DialogNPCEdit->resize(1018, 698);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogNPCEdit->sizePolicy().hasHeightForWidth());
        DialogNPCEdit->setSizePolicy(sizePolicy);
        DialogNPCEdit->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(DialogNPCEdit);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridWidget = new QWidget(DialogNPCEdit);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalWidget = new QWidget(gridWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        sizePolicy1.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy1);
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

        gridLayout->addWidget(label_10, 3, 0, 1, 2);

        npcGraphicSizeSpin_h = new QSpinBox(horizontalWidget);
        npcGraphicSizeSpin_h->setObjectName(QString::fromUtf8("npcGraphicSizeSpin_h"));
        npcGraphicSizeSpin_h->setMinimum(8);
        npcGraphicSizeSpin_h->setMaximum(128);
        npcGraphicSizeSpin_h->setValue(16);

        gridLayout->addWidget(npcGraphicSizeSpin_h, 4, 2, 1, 1);

        NpcHP = new QSpinBox(horizontalWidget);
        NpcHP->setObjectName(QString::fromUtf8("NpcHP"));
        NpcHP->setValue(5);

        gridLayout->addWidget(NpcHP, 1, 2, 1, 1);

        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        npcListCombobox = new QComboBox(horizontalWidget);
        npcListCombobox->setObjectName(QString::fromUtf8("npcListCombobox"));

        gridLayout->addWidget(npcListCombobox, 2, 2, 1, 1);

        npcGraphicSizeSpin_w = new QSpinBox(horizontalWidget);
        npcGraphicSizeSpin_w->setObjectName(QString::fromUtf8("npcGraphicSizeSpin_w"));
        npcGraphicSizeSpin_w->setMinimum(8);
        npcGraphicSizeSpin_w->setMaximum(128);
        npcGraphicSizeSpin_w->setValue(16);

        gridLayout->addWidget(npcGraphicSizeSpin_w, 3, 2, 1, 1);

        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_8 = new QLabel(horizontalWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        checkBoxCanShoot = new QCheckBox(horizontalWidget);
        checkBoxCanShoot->setObjectName(QString::fromUtf8("checkBoxCanShoot"));

        gridLayout->addWidget(checkBoxCanShoot, 5, 0, 1, 1);

        label_5 = new QLabel(horizontalWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        comboBoxIA = new QComboBox(horizontalWidget);
        comboBoxIA->setObjectName(QString::fromUtf8("comboBoxIA"));

        gridLayout->addWidget(comboBoxIA, 7, 2, 1, 1);

        buttonBox = new QDialogButtonBox(horizontalWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 12, 2, 1, 1);

        comboBoxShieldType = new QComboBox(horizontalWidget);
        comboBoxShieldType->setObjectName(QString::fromUtf8("comboBoxShieldType"));

        gridLayout->addWidget(comboBoxShieldType, 6, 2, 1, 1);

        label_6 = new QLabel(horizontalWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        isBossCheckbox = new QCheckBox(horizontalWidget);
        isBossCheckbox->setObjectName(QString::fromUtf8("isBossCheckbox"));

        gridLayout->addWidget(isBossCheckbox, 11, 0, 1, 1);

        label_7 = new QLabel(horizontalWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 1);

        label_9 = new QLabel(horizontalWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        speed_spin = new QSpinBox(horizontalWidget);
        speed_spin->setObjectName(QString::fromUtf8("speed_spin"));
        speed_spin->setMinimum(1);
        speed_spin->setMaximum(8);
        speed_spin->setValue(2);

        gridLayout->addWidget(speed_spin, 8, 2, 1, 1);

        range_spin = new QSpinBox(horizontalWidget);
        range_spin->setObjectName(QString::fromUtf8("range_spin"));
        range_spin->setMinimum(48);
        range_spin->setMaximum(320);
        range_spin->setValue(106);

        gridLayout->addWidget(range_spin, 9, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        verticalWidget = new QWidget(horizontalWidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalWidget->setStyleSheet(QString::fromUtf8("border: 1px solid green;"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 1, -1, -1);
        verticalWidget_2 = new QWidget(verticalWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        sizePolicy.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy);
        verticalWidget_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        verticalLayout_2 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(verticalWidget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 434, 558));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setAutoFillBackground(false);
        npcPreviewAreaWidget = new npcPreviewArea(scrollAreaWidgetContents);
        npcPreviewAreaWidget->setObjectName(QString::fromUtf8("npcPreviewAreaWidget"));
        npcPreviewAreaWidget->setGeometry(QRect(0, 0, 651, 581));
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

        frameTypeCombo = new QComboBox(verticalWidget);
        frameTypeCombo->setObjectName(QString::fromUtf8("frameTypeCombo"));

        verticalLayout->addWidget(frameTypeCombo);


        horizontalLayout_2->addWidget(verticalWidget);


        gridLayout_2->addWidget(horizontalWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(gridWidget, 0, 0, 1, 1);


        retranslateUi(DialogNPCEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNPCEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNPCEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogNPCEdit);
    } // setupUi

    void retranslateUi(QDialog *DialogNPCEdit)
    {
        DialogNPCEdit->setWindowTitle(QApplication::translate("DialogNPCEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        NpcName->setText(QApplication::translate("DialogNPCEdit", "My NPC", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DialogNPCEdit", "Graphic Width: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNPCEdit", "Graphic Height:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogNPCEdit", "Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogNPCEdit", "Graphic:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogNPCEdit", "Hit Points:", 0, QApplication::UnicodeUTF8));
        checkBoxCanShoot->setText(QApplication::translate("DialogNPCEdit", "Can Shoot", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogNPCEdit", "*IA Type:", 0, QApplication::UnicodeUTF8));
        comboBoxShieldType->clear();
        comboBoxShieldType->insertItems(0, QStringList()
         << QApplication::translate("DialogNPCEdit", "no shield", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "full shield", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "front shield", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        label_6->setText(QApplication::translate("DialogNPCEdit", "Shield:", 0, QApplication::UnicodeUTF8));
        isBossCheckbox->setText(QApplication::translate("DialogNPCEdit", "Is Boss", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogNPCEdit", "Speed:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DialogNPCEdit", "Range:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogNPCEdit", "Duration:", 0, QApplication::UnicodeUTF8));
        frameTypeCombo->clear();
        frameTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("DialogNPCEdit", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_STAND", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_WALK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_JUMP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_TELEPORT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_JUMP_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_WALK_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_HIT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_STAIRS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_STAIRS_SEMI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_STAIRS_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_STAIRS_MOVE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_TROW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_TURN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_MOVE_SEMI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_WALK_AIR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_INTRO", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogNPCEdit", "ANIM_SPECIAL_ATTACK", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class DialogNPCEdit: public Ui_DialogNPCEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNPCEDIT_H
