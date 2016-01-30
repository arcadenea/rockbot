/********************************************************************************
** Form generated from reading UI file 'object_tab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECT_TAB_H
#define UI_OBJECT_TAB_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "npcpreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_object_tab
{
public:
    QGridLayout *gridLayout;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_14;
    QGridLayout *gridLayout_13;
    QLabel *label_56;
    QLabel *label_60;
    QComboBox *graphicfile_combo;
    QLabel *label_63;
    QSpinBox *graphic_w;
    QComboBox *type_combo;
    QLabel *label_59;
    QLabel *label_58;
    QLabel *label_52;
    QSpinBox *limit;
    QSpinBox *speed;
    QSpinBox *timer;
    QCheckBox *animate_on_active_checkbox;
    QCheckBox *animation_loop_checkbox;
    QLineEdit *name;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpinBox *graphic_h;
    QCheckBox *animation_reverse_checkbox;
    QLabel *label_4;
    QLabel *label;
    QComboBox *objectlist_combo;
    QLabel *label_62;
    QLabel *label_61;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_9;
    QWidget *verticalWidget_3;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    npcPreviewArea *object_preview_area;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_64;
    QSpinBox *frame_duration_spinbox;

    void setupUi(QWidget *object_tab)
    {
        if (object_tab->objectName().isEmpty())
            object_tab->setObjectName(QString::fromUtf8("object_tab"));
        object_tab->resize(815, 471);
        gridLayout = new QGridLayout(object_tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalWidget_2 = new QWidget(object_tab);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy);
        horizontalWidget_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_14 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_14->setContentsMargins(-1, -1, 20, -1);
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(-1, -1, -1, 20);
        label_56 = new QLabel(horizontalWidget_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_13->addWidget(label_56, 5, 0, 1, 1);

        label_60 = new QLabel(horizontalWidget_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_13->addWidget(label_60, 6, 0, 1, 1);

        graphicfile_combo = new QComboBox(horizontalWidget_2);
        graphicfile_combo->setObjectName(QString::fromUtf8("graphicfile_combo"));

        gridLayout_13->addWidget(graphicfile_combo, 3, 2, 1, 1);

        label_63 = new QLabel(horizontalWidget_2);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_13->addWidget(label_63, 8, 0, 1, 1);

        graphic_w = new QSpinBox(horizontalWidget_2);
        graphic_w->setObjectName(QString::fromUtf8("graphic_w"));
        graphic_w->setMinimum(8);
        graphic_w->setMaximum(999);
        graphic_w->setValue(16);

        gridLayout_13->addWidget(graphic_w, 4, 2, 1, 1);

        type_combo = new QComboBox(horizontalWidget_2);
        type_combo->setObjectName(QString::fromUtf8("type_combo"));

        gridLayout_13->addWidget(type_combo, 6, 2, 1, 1);

        label_59 = new QLabel(horizontalWidget_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_13->addWidget(label_59, 3, 0, 1, 1);

        label_58 = new QLabel(horizontalWidget_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_13->addWidget(label_58, 1, 0, 1, 1);

        label_52 = new QLabel(horizontalWidget_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_13->addWidget(label_52, 4, 0, 1, 2);

        limit = new QSpinBox(horizontalWidget_2);
        limit->setObjectName(QString::fromUtf8("limit"));
        limit->setMaximum(99999);

        gridLayout_13->addWidget(limit, 9, 2, 1, 1);

        speed = new QSpinBox(horizontalWidget_2);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setMaximum(99999);

        gridLayout_13->addWidget(speed, 8, 2, 1, 1);

        timer = new QSpinBox(horizontalWidget_2);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setMaximum(99999);

        gridLayout_13->addWidget(timer, 7, 2, 1, 1);

        animate_on_active_checkbox = new QCheckBox(horizontalWidget_2);
        animate_on_active_checkbox->setObjectName(QString::fromUtf8("animate_on_active_checkbox"));

        gridLayout_13->addWidget(animate_on_active_checkbox, 10, 2, 1, 1);

        animation_loop_checkbox = new QCheckBox(horizontalWidget_2);
        animation_loop_checkbox->setObjectName(QString::fromUtf8("animation_loop_checkbox"));

        gridLayout_13->addWidget(animation_loop_checkbox, 12, 2, 1, 1);

        name = new QLineEdit(horizontalWidget_2);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMaxLength(30);

        gridLayout_13->addWidget(name, 1, 2, 1, 1);

        label_3 = new QLabel(horizontalWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_13->addWidget(label_3, 12, 0, 1, 1);

        label_2 = new QLabel(horizontalWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_13->addWidget(label_2, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 14, 0, 1, 1);

        graphic_h = new QSpinBox(horizontalWidget_2);
        graphic_h->setObjectName(QString::fromUtf8("graphic_h"));
        graphic_h->setMinimum(8);
        graphic_h->setMaximum(999);
        graphic_h->setValue(16);

        gridLayout_13->addWidget(graphic_h, 5, 2, 1, 1);

        animation_reverse_checkbox = new QCheckBox(horizontalWidget_2);
        animation_reverse_checkbox->setObjectName(QString::fromUtf8("animation_reverse_checkbox"));

        gridLayout_13->addWidget(animation_reverse_checkbox, 13, 2, 1, 1);

        label_4 = new QLabel(horizontalWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_13->addWidget(label_4, 13, 0, 1, 1);

        label = new QLabel(horizontalWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_13->addWidget(label, 0, 0, 1, 1);

        objectlist_combo = new QComboBox(horizontalWidget_2);
        objectlist_combo->setObjectName(QString::fromUtf8("objectlist_combo"));

        gridLayout_13->addWidget(objectlist_combo, 0, 2, 1, 1);

        label_62 = new QLabel(horizontalWidget_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_13->addWidget(label_62, 9, 0, 1, 1);

        label_61 = new QLabel(horizontalWidget_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        gridLayout_13->addWidget(label_61, 7, 0, 1, 1);


        horizontalLayout_14->addLayout(gridLayout_13);

        verticalWidget_2 = new QWidget(horizontalWidget_2);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy1);
        verticalWidget_2->setMaximumSize(QSize(16777215, 400));
        verticalWidget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_9 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(10, 1, -1, -1);
        verticalWidget_3 = new QWidget(verticalWidget_2);
        verticalWidget_3->setObjectName(QString::fromUtf8("verticalWidget_3"));
        sizePolicy1.setHeightForWidth(verticalWidget_3->sizePolicy().hasHeightForWidth());
        verticalWidget_3->setSizePolicy(sizePolicy1);
        verticalWidget_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_10 = new QVBoxLayout(verticalWidget_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        scrollArea_5 = new QScrollArea(verticalWidget_3);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        sizePolicy.setHeightForWidth(scrollArea_5->sizePolicy().hasHeightForWidth());
        scrollArea_5->setSizePolicy(sizePolicy);
        scrollArea_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_5->setWidgetResizable(false);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 334, 305));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents_5->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_5->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents_5->setAutoFillBackground(true);
        object_preview_area = new npcPreviewArea(scrollAreaWidgetContents_5);
        object_preview_area->setObjectName(QString::fromUtf8("object_preview_area"));
        object_preview_area->setGeometry(QRect(0, 0, 181, 171));
        object_preview_area->setStyleSheet(QString::fromUtf8(""));
        scrollArea_5->setWidget(scrollAreaWidgetContents_5);

        verticalLayout_10->addWidget(scrollArea_5);


        verticalLayout_9->addWidget(verticalWidget_3);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_64 = new QLabel(verticalWidget_2);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_64->sizePolicy().hasHeightForWidth());
        label_64->setSizePolicy(sizePolicy3);

        horizontalLayout_15->addWidget(label_64);

        frame_duration_spinbox = new QSpinBox(verticalWidget_2);
        frame_duration_spinbox->setObjectName(QString::fromUtf8("frame_duration_spinbox"));
        frame_duration_spinbox->setMinimum(5);
        frame_duration_spinbox->setMaximum(9999);
        frame_duration_spinbox->setValue(20);

        horizontalLayout_15->addWidget(frame_duration_spinbox);


        verticalLayout_9->addLayout(horizontalLayout_15);


        horizontalLayout_14->addWidget(verticalWidget_2);


        gridLayout->addWidget(horizontalWidget_2, 0, 0, 1, 1);


        retranslateUi(object_tab);

        QMetaObject::connectSlotsByName(object_tab);
    } // setupUi

    void retranslateUi(QWidget *object_tab)
    {
        object_tab->setWindowTitle(QApplication::translate("object_tab", "Form", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("object_tab", "Graphic Height:", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("object_tab", "Type:", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("object_tab", "Speed:", 0, QApplication::UnicodeUTF8));
        type_combo->clear();
        type_combo->insertItems(0, QStringList()
         << QApplication::translate("object_tab", "Moving Platform (up/down)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Moving platform (left/right)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Disapearing Block", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Energy Tank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Weapons Tank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Energy Pill (big)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Weapons Pill (big)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Enegy Pill (small)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Weapons Pill (small)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "1 UP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Faller Platform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Flying Platform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Fly Item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Coil Item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Active Disappearing Block", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Armor Piece (Arms)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Armor Piece (Body)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Armor Piece (Legs)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Expanding Ray (Horizontal)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Expanding Ray (Vertical)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Track Platform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Boss Teleporter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Destructible Wall", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Special Tank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Death Ray (Vertical)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Death Ray (Horizontal)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("object_tab", "Final Boss Teleporter", 0, QApplication::UnicodeUTF8)
        );
        label_59->setText(QApplication::translate("object_tab", "Graphic:", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("object_tab", "Name:", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("object_tab", "Graphic Width: ", 0, QApplication::UnicodeUTF8));
        animate_on_active_checkbox->setText(QString());
        animation_loop_checkbox->setText(QString());
        name->setText(QApplication::translate("object_tab", "My Object", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("object_tab", "Animation Loop:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("object_tab", "Animate only when active:", 0, QApplication::UnicodeUTF8));
        animation_reverse_checkbox->setText(QString());
        label_4->setText(QApplication::translate("object_tab", "Animation Reverse:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("object_tab", "Object:", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("object_tab", "Limit:", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("object_tab", "Timer:", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("object_tab", "Duration:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class object_tab: public Ui_object_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECT_TAB_H
