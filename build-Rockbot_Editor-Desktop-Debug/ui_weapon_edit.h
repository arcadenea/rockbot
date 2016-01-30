/********************************************************************************
** Form generated from reading UI file 'weapon_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPON_EDIT_H
#define UI_WEAPON_EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weapon_edit
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_4;
    QComboBox *weapon_select_combo;
    QLabel *label_21;
    QLabel *label_24;
    QComboBox *weapon_projectile_type;
    QLineEdit *weapon_name;
    QLabel *label_25;
    QSpinBox *weapon_damage;

    void setupUi(QWidget *weapon_edit)
    {
        if (weapon_edit->objectName().isEmpty())
            weapon_edit->setObjectName(QString::fromUtf8("weapon_edit"));
        weapon_edit->resize(826, 433);
        gridLayout = new QGridLayout(weapon_edit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_20 = new QLabel(weapon_edit);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_7->addWidget(label_20, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_4, 4, 0, 1, 1);

        weapon_select_combo = new QComboBox(weapon_edit);
        weapon_select_combo->setObjectName(QString::fromUtf8("weapon_select_combo"));

        gridLayout_7->addWidget(weapon_select_combo, 0, 1, 1, 1);

        label_21 = new QLabel(weapon_edit);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_7->addWidget(label_21, 1, 0, 1, 1);

        label_24 = new QLabel(weapon_edit);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_7->addWidget(label_24, 2, 0, 1, 1);

        weapon_projectile_type = new QComboBox(weapon_edit);
        weapon_projectile_type->setObjectName(QString::fromUtf8("weapon_projectile_type"));

        gridLayout_7->addWidget(weapon_projectile_type, 2, 1, 1, 1);

        weapon_name = new QLineEdit(weapon_edit);
        weapon_name->setObjectName(QString::fromUtf8("weapon_name"));
        weapon_name->setMaxLength(30);

        gridLayout_7->addWidget(weapon_name, 1, 1, 1, 1);

        label_25 = new QLabel(weapon_edit);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_7->addWidget(label_25, 3, 0, 1, 1);

        weapon_damage = new QSpinBox(weapon_edit);
        weapon_damage->setObjectName(QString::fromUtf8("weapon_damage"));
        weapon_damage->setMinimum(1);

        gridLayout_7->addWidget(weapon_damage, 3, 1, 1, 1);


        gridLayout->addLayout(gridLayout_7, 0, 0, 1, 1);


        retranslateUi(weapon_edit);

        QMetaObject::connectSlotsByName(weapon_edit);
    } // setupUi

    void retranslateUi(QWidget *weapon_edit)
    {
        weapon_edit->setWindowTitle(QApplication::translate("weapon_edit", "Form", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("weapon_edit", "Weapon:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("weapon_edit", "Name:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("weapon_edit", "Projectile Type:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("weapon_edit", "Damage:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weapon_edit: public Ui_weapon_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPON_EDIT_H
