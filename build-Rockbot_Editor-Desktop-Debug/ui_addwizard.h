/********************************************************************************
** Form generated from reading UI file 'addwizard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIZARD_H
#define UI_ADDWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include <QtGui/QWizard>
#include <QtGui/QWizardPage>
#include "npcpreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_addWizard
{
public:
    QWizardPage *wizardPageSelect;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWizardPage *wizardPageNPC;
    QLabel *label_4;
    npcPreviewArea *npcPreviewAreaWidget;
    QLabel *label_9;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *NpcName;
    QLabel *label_3;
    QSpinBox *NpcHP;
    QLabel *label_8;
    QComboBox *npcListCombobox;
    QLabel *label_10;
    QSpinBox *npcGraphicSizeWSpin;
    QSpinBox *npcGraphicSizeHSpin;
    QWizardPage *wizardPageMAP;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QWizardPage *wizardPageFinish;
    QLabel *label_6;

    void setupUi(QWizard *addWizard)
    {
        if (addWizard->objectName().isEmpty())
            addWizard->setObjectName(QString::fromUtf8("addWizard"));
        addWizard->resize(571, 371);
        wizardPageSelect = new QWizardPage();
        wizardPageSelect->setObjectName(QString::fromUtf8("wizardPageSelect"));
        wizardPageSelect->setTitle(QString::fromUtf8(""));
        wizardPageSelect->setSubTitle(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(wizardPageSelect);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 197, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        addWizard->addPage(wizardPageSelect);
        wizardPageNPC = new QWizardPage();
        wizardPageNPC->setObjectName(QString::fromUtf8("wizardPageNPC"));
        label_4 = new QLabel(wizardPageNPC);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 121, 16));
        npcPreviewAreaWidget = new npcPreviewArea(wizardPageNPC);
        npcPreviewAreaWidget->setObjectName(QString::fromUtf8("npcPreviewAreaWidget"));
        npcPreviewAreaWidget->setGeometry(QRect(280, 20, 281, 231));
        label_9 = new QLabel(wizardPageNPC);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 0, 101, 16));
        layoutWidget = new QWidget(wizardPageNPC);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 22, 271, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        NpcName = new QLineEdit(layoutWidget);
        NpcName->setObjectName(QString::fromUtf8("NpcName"));

        gridLayout->addWidget(NpcName, 0, 1, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        NpcHP = new QSpinBox(layoutWidget);
        NpcHP->setObjectName(QString::fromUtf8("NpcHP"));
        NpcHP->setValue(5);

        gridLayout->addWidget(NpcHP, 1, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        npcListCombobox = new QComboBox(layoutWidget);
        npcListCombobox->setObjectName(QString::fromUtf8("npcListCombobox"));

        gridLayout->addWidget(npcListCombobox, 2, 2, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 0, 1, 2);

        npcGraphicSizeWSpin = new QSpinBox(layoutWidget);
        npcGraphicSizeWSpin->setObjectName(QString::fromUtf8("npcGraphicSizeWSpin"));
        npcGraphicSizeWSpin->setMinimum(16);
        npcGraphicSizeWSpin->setMaximum(64);

        gridLayout->addWidget(npcGraphicSizeWSpin, 3, 2, 1, 1);

        npcGraphicSizeHSpin = new QSpinBox(wizardPageNPC);
        npcGraphicSizeHSpin->setObjectName(QString::fromUtf8("npcGraphicSizeHSpin"));
        npcGraphicSizeHSpin->setGeometry(QRect(100, 210, 86, 21));
        npcGraphicSizeHSpin->setMinimum(16);
        npcGraphicSizeHSpin->setMaximum(64);
        addWizard->addPage(wizardPageNPC);
        wizardPageMAP = new QWizardPage();
        wizardPageMAP->setObjectName(QString::fromUtf8("wizardPageMAP"));
        layoutWidget_2 = new QWidget(wizardPageMAP);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 20, 187, 48));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_7 = new QLabel(wizardPageMAP);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 121, 16));
        addWizard->addPage(wizardPageMAP);
        wizardPageFinish = new QWizardPage();
        wizardPageFinish->setObjectName(QString::fromUtf8("wizardPageFinish"));
        label_6 = new QLabel(wizardPageFinish);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 20, 141, 16));
        addWizard->addPage(wizardPageFinish);

        retranslateUi(addWizard);

        QMetaObject::connectSlotsByName(addWizard);
    } // setupUi

    void retranslateUi(QWizard *addWizard)
    {
        addWizard->setWindowTitle(QApplication::translate("addWizard", "Wizard", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addWizard", "Select Object Type:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("addWizard", "Fill NPC information:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("addWizard", "Graphic Preview", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addWizard", "Name:", 0, QApplication::UnicodeUTF8));
        NpcName->setText(QApplication::translate("addWizard", "My NPC", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("addWizard", "Hit Points:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("addWizard", "Graphic:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("addWizard", "Graphic Size: ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("addWizard", "Name", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("addWizard", "Fill Map information:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("addWizard", "Click finish to add the object:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addWizard: public Ui_addWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIZARD_H
