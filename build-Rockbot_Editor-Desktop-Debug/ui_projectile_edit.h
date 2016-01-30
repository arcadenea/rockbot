/********************************************************************************
** Form generated from reading UI file 'projectile_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTILE_EDIT_H
#define UI_PROJECTILE_EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "projectilepreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_projectile_edit
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_10;
    QLineEdit *name;
    QLabel *label_26;
    QLabel *label_28;
    QComboBox *graphic_filename;
    QComboBox *trajectory;
    QLabel *label_27;
    QLabel *label_29;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    projectilePreviewArea *projectilePreviewAreaWidget;
    QComboBox *projectileList_combo;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *projectileDestructibleCheckBox;
    QLabel *label_33;
    QSpinBox *projectileHitPointsSpinBox;
    QHBoxLayout *horizontalLayout;
    QSpinBox *img_w;
    QLabel *label_31;
    QSpinBox *img_h;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *max_shots;
    QLabel *label_3;
    QSpinBox *speed;
    QLabel *label_4;
    QSpinBox *damage;
    QLabel *label_2;

    void setupUi(QWidget *projectile_edit)
    {
        if (projectile_edit->objectName().isEmpty())
            projectile_edit->setObjectName(QString::fromUtf8("projectile_edit"));
        projectile_edit->resize(766, 466);
        gridLayout = new QGridLayout(projectile_edit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));

        gridLayout->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, -1, -1, 0);
        name = new QLineEdit(projectile_edit);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMaxLength(30);

        gridLayout_10->addWidget(name, 3, 1, 1, 1);

        label_26 = new QLabel(projectile_edit);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_10->addWidget(label_26, 3, 0, 1, 1);

        label_28 = new QLabel(projectile_edit);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_10->addWidget(label_28, 5, 0, 1, 1);

        graphic_filename = new QComboBox(projectile_edit);
        graphic_filename->setObjectName(QString::fromUtf8("graphic_filename"));

        gridLayout_10->addWidget(graphic_filename, 4, 1, 1, 1);

        trajectory = new QComboBox(projectile_edit);
        trajectory->setObjectName(QString::fromUtf8("trajectory"));

        gridLayout_10->addWidget(trajectory, 5, 1, 1, 1);

        label_27 = new QLabel(projectile_edit);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_10->addWidget(label_27, 4, 0, 1, 1);

        label_29 = new QLabel(projectile_edit);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_10->addWidget(label_29, 13, 0, 1, 1);

        scrollArea_3 = new QScrollArea(projectile_edit);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea_3->sizePolicy().hasHeightForWidth());
        scrollArea_3->setSizePolicy(sizePolicy);
        scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_3->setWidgetResizable(false);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 434, 558));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents_3->setAutoFillBackground(true);
        projectilePreviewAreaWidget = new projectilePreviewArea(scrollAreaWidgetContents_3);
        projectilePreviewAreaWidget->setObjectName(QString::fromUtf8("projectilePreviewAreaWidget"));
        projectilePreviewAreaWidget->setGeometry(QRect(0, 0, 651, 581));
        projectilePreviewAreaWidget->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_10->addWidget(scrollArea_3, 13, 1, 1, 1);

        projectileList_combo = new QComboBox(projectile_edit);
        projectileList_combo->setObjectName(QString::fromUtf8("projectileList_combo"));

        gridLayout_10->addWidget(projectileList_combo, 2, 1, 1, 1);

        label_32 = new QLabel(projectile_edit);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_10->addWidget(label_32, 10, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        projectileDestructibleCheckBox = new QCheckBox(projectile_edit);
        projectileDestructibleCheckBox->setObjectName(QString::fromUtf8("projectileDestructibleCheckBox"));

        horizontalLayout_2->addWidget(projectileDestructibleCheckBox);

        label_33 = new QLabel(projectile_edit);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_2->addWidget(label_33);

        projectileHitPointsSpinBox = new QSpinBox(projectile_edit);
        projectileHitPointsSpinBox->setObjectName(QString::fromUtf8("projectileHitPointsSpinBox"));
        projectileHitPointsSpinBox->setMinimum(1);

        horizontalLayout_2->addWidget(projectileHitPointsSpinBox);


        gridLayout_10->addLayout(horizontalLayout_2, 10, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        img_w = new QSpinBox(projectile_edit);
        img_w->setObjectName(QString::fromUtf8("img_w"));
        img_w->setMinimum(1);
        img_w->setValue(16);

        horizontalLayout->addWidget(img_w);

        label_31 = new QLabel(projectile_edit);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout->addWidget(label_31);

        img_h = new QSpinBox(projectile_edit);
        img_h->setObjectName(QString::fromUtf8("img_h"));
        img_h->setMinimum(1);
        img_h->setValue(16);

        horizontalLayout->addWidget(img_h);


        gridLayout_10->addLayout(horizontalLayout, 7, 1, 1, 1);

        label_30 = new QLabel(projectile_edit);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_10->addWidget(label_30, 7, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 6, -1, -1);
        max_shots = new QSpinBox(projectile_edit);
        max_shots->setObjectName(QString::fromUtf8("max_shots"));

        horizontalLayout_4->addWidget(max_shots);

        label_3 = new QLabel(projectile_edit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        speed = new QSpinBox(projectile_edit);
        speed->setObjectName(QString::fromUtf8("speed"));

        horizontalLayout_4->addWidget(speed);

        label_4 = new QLabel(projectile_edit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        damage = new QSpinBox(projectile_edit);
        damage->setObjectName(QString::fromUtf8("damage"));

        horizontalLayout_4->addWidget(damage);


        gridLayout_10->addLayout(horizontalLayout_4, 11, 1, 1, 1);

        label_2 = new QLabel(projectile_edit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_10->addWidget(label_2, 11, 0, 1, 1);


        gridLayout->addLayout(gridLayout_10, 1, 0, 1, 1);


        retranslateUi(projectile_edit);

        QMetaObject::connectSlotsByName(projectile_edit);
    } // setupUi

    void retranslateUi(QWidget *projectile_edit)
    {
        projectile_edit->setWindowTitle(QApplication::translate("projectile_edit", "Form", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("projectile_edit", "No Name", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("projectile_edit", "Name: ", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("projectile_edit", "Trajectory Type:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("projectile_edit", "Image File:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("projectile_edit", "Preview:", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("projectile_edit", "Destructible:", 0, QApplication::UnicodeUTF8));
        projectileDestructibleCheckBox->setText(QString());
        label_33->setText(QApplication::translate("projectile_edit", "Hit Points (HP):", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("projectile_edit", "Image Height:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("projectile_edit", "Image Widht:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("projectile_edit", "Speed:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("projectile_edit", "Damage:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("projectile_edit", "Max Shots:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class projectile_edit: public Ui_projectile_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTILE_EDIT_H
