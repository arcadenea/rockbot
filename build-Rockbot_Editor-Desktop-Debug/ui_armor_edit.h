/********************************************************************************
** Form generated from reading UI file 'armor_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMOR_EDIT_H
#define UI_ARMOR_EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_armor_edit
{
public:
    QGridLayout *gridLayout_2;
    QComboBox *p2_arm_comboBox;
    QComboBox *p4_legs_comboBox;
    QComboBox *p4_body_comboBox;
    QComboBox *p3_legs_comboBox;
    QLabel *label;
    QComboBox *p2_legs_comboBox;
    QComboBox *p2_body_comboBox;
    QComboBox *p1_body_comboBox;
    QComboBox *p1_arm_comboBox;
    QLabel *label_6;
    QComboBox *p3_body_comboBox;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_2;
    QComboBox *p3_arm_comboBox;
    QLabel *label_4;
    QComboBox *p1_legs_comboBox;
    QComboBox *p4_arm_comboBox;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *armor_edit)
    {
        if (armor_edit->objectName().isEmpty())
            armor_edit->setObjectName(QString::fromUtf8("armor_edit"));
        armor_edit->resize(554, 365);
        gridLayout_2 = new QGridLayout(armor_edit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        p2_arm_comboBox = new QComboBox(armor_edit);
        p2_arm_comboBox->setObjectName(QString::fromUtf8("p2_arm_comboBox"));

        gridLayout_2->addWidget(p2_arm_comboBox, 2, 3, 1, 1);

        p4_legs_comboBox = new QComboBox(armor_edit);
        p4_legs_comboBox->setObjectName(QString::fromUtf8("p4_legs_comboBox"));

        gridLayout_2->addWidget(p4_legs_comboBox, 4, 5, 1, 1);

        p4_body_comboBox = new QComboBox(armor_edit);
        p4_body_comboBox->setObjectName(QString::fromUtf8("p4_body_comboBox"));

        gridLayout_2->addWidget(p4_body_comboBox, 3, 5, 1, 1);

        p3_legs_comboBox = new QComboBox(armor_edit);
        p3_legs_comboBox->setObjectName(QString::fromUtf8("p3_legs_comboBox"));

        gridLayout_2->addWidget(p3_legs_comboBox, 4, 4, 1, 1);

        label = new QLabel(armor_edit);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        p2_legs_comboBox = new QComboBox(armor_edit);
        p2_legs_comboBox->setObjectName(QString::fromUtf8("p2_legs_comboBox"));

        gridLayout_2->addWidget(p2_legs_comboBox, 4, 3, 1, 1);

        p2_body_comboBox = new QComboBox(armor_edit);
        p2_body_comboBox->setObjectName(QString::fromUtf8("p2_body_comboBox"));

        gridLayout_2->addWidget(p2_body_comboBox, 3, 3, 1, 1);

        p1_body_comboBox = new QComboBox(armor_edit);
        p1_body_comboBox->setObjectName(QString::fromUtf8("p1_body_comboBox"));

        gridLayout_2->addWidget(p1_body_comboBox, 3, 2, 1, 1);

        p1_arm_comboBox = new QComboBox(armor_edit);
        p1_arm_comboBox->setObjectName(QString::fromUtf8("p1_arm_comboBox"));

        gridLayout_2->addWidget(p1_arm_comboBox, 2, 2, 1, 1);

        label_6 = new QLabel(armor_edit);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 4, 1, 1);

        p3_body_comboBox = new QComboBox(armor_edit);
        p3_body_comboBox->setObjectName(QString::fromUtf8("p3_body_comboBox"));

        gridLayout_2->addWidget(p3_body_comboBox, 3, 4, 1, 1);

        label_3 = new QLabel(armor_edit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 4, 1, 1, 1);

        label_5 = new QLabel(armor_edit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 3, 1, 1);

        label_7 = new QLabel(armor_edit);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 5, 1, 1);

        label_2 = new QLabel(armor_edit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 3, 1, 1, 1);

        p3_arm_comboBox = new QComboBox(armor_edit);
        p3_arm_comboBox->setObjectName(QString::fromUtf8("p3_arm_comboBox"));

        gridLayout_2->addWidget(p3_arm_comboBox, 2, 4, 1, 1);

        label_4 = new QLabel(armor_edit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        p1_legs_comboBox = new QComboBox(armor_edit);
        p1_legs_comboBox->setObjectName(QString::fromUtf8("p1_legs_comboBox"));

        gridLayout_2->addWidget(p1_legs_comboBox, 4, 2, 1, 1);

        p4_arm_comboBox = new QComboBox(armor_edit);
        p4_arm_comboBox->setObjectName(QString::fromUtf8("p4_arm_comboBox"));

        gridLayout_2->addWidget(p4_arm_comboBox, 2, 5, 1, 1);

        label_8 = new QLabel(armor_edit);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 3, 1, 1);


        retranslateUi(armor_edit);

        QMetaObject::connectSlotsByName(armor_edit);
    } // setupUi

    void retranslateUi(QWidget *armor_edit)
    {
        armor_edit->setWindowTitle(QApplication::translate("armor_edit", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("armor_edit", "Arm:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("armor_edit", "Player 3", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("armor_edit", "Legs:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("armor_edit", "Player 2", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("armor_edit", "Player 4", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("armor_edit", "Body:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_8->setText(QApplication::translate("armor_edit", "Player 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class armor_edit: public Ui_armor_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMOR_EDIT_H
