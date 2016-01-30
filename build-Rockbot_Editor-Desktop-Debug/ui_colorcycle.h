/********************************************************************************
** Form generated from reading UI file 'colorcycle.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORCYCLE_H
#define UI_COLORCYCLE_H

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
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "colorcycle_map_preview.h"

QT_BEGIN_NAMESPACE

class Ui_colorcycle_edit
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QPushButton *color_pick_button1;
    QSpacerItem *horizontalSpacer;
    QPushButton *color_pick_button2;
    QPushButton *color_pick_button3;
    QPushButton *color_pick_button4;
    QPushButton *color_pick_button5;
    QPushButton *color_pick_button6;
    QPushButton *color_pick_button7;
    QPushButton *color_pick_button8;
    QPushButton *color_pick_button9;
    QPushButton *color_pick_button10;
    QSpinBox *duration1;
    QSpinBox *duration2;
    QSpinBox *duration3;
    QSpinBox *duration4;
    QSpinBox *duration5;
    QSpinBox *duration6;
    QSpinBox *duration7;
    QSpinBox *duration8;
    QSpinBox *duration9;
    QSpinBox *duration10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    colorcycle_map_preview *map_preview;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *stage_selector;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QCheckBox *show_colorcycle1_checkbox;
    QCheckBox *show_colorcycle2_checkbox;
    QCheckBox *show_colorcycle3_checkbox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *colorcycle_edit)
    {
        if (colorcycle_edit->objectName().isEmpty())
            colorcycle_edit->setObjectName(QString::fromUtf8("colorcycle_edit"));
        colorcycle_edit->resize(831, 478);
        gridLayout_3 = new QGridLayout(colorcycle_edit);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, -1, -1);
        color_pick_button1 = new QPushButton(colorcycle_edit);
        color_pick_button1->setObjectName(QString::fromUtf8("color_pick_button1"));
        color_pick_button1->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button1, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 10, 1, 1);

        color_pick_button2 = new QPushButton(colorcycle_edit);
        color_pick_button2->setObjectName(QString::fromUtf8("color_pick_button2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(color_pick_button2->sizePolicy().hasHeightForWidth());
        color_pick_button2->setSizePolicy(sizePolicy);
        color_pick_button2->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button2, 1, 2, 1, 1);

        color_pick_button3 = new QPushButton(colorcycle_edit);
        color_pick_button3->setObjectName(QString::fromUtf8("color_pick_button3"));
        color_pick_button3->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button3, 1, 4, 1, 1);

        color_pick_button4 = new QPushButton(colorcycle_edit);
        color_pick_button4->setObjectName(QString::fromUtf8("color_pick_button4"));
        color_pick_button4->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button4, 1, 6, 1, 1);

        color_pick_button5 = new QPushButton(colorcycle_edit);
        color_pick_button5->setObjectName(QString::fromUtf8("color_pick_button5"));
        color_pick_button5->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button5, 1, 8, 1, 1);

        color_pick_button6 = new QPushButton(colorcycle_edit);
        color_pick_button6->setObjectName(QString::fromUtf8("color_pick_button6"));
        color_pick_button6->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button6, 2, 0, 1, 1);

        color_pick_button7 = new QPushButton(colorcycle_edit);
        color_pick_button7->setObjectName(QString::fromUtf8("color_pick_button7"));
        color_pick_button7->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button7, 2, 2, 1, 1);

        color_pick_button8 = new QPushButton(colorcycle_edit);
        color_pick_button8->setObjectName(QString::fromUtf8("color_pick_button8"));
        color_pick_button8->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button8, 2, 4, 1, 1);

        color_pick_button9 = new QPushButton(colorcycle_edit);
        color_pick_button9->setObjectName(QString::fromUtf8("color_pick_button9"));
        color_pick_button9->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button9, 2, 6, 1, 1);

        color_pick_button10 = new QPushButton(colorcycle_edit);
        color_pick_button10->setObjectName(QString::fromUtf8("color_pick_button10"));
        color_pick_button10->setMinimumSize(QSize(0, 32));

        gridLayout_4->addWidget(color_pick_button10, 2, 8, 1, 1);

        duration1 = new QSpinBox(colorcycle_edit);
        duration1->setObjectName(QString::fromUtf8("duration1"));
        duration1->setMaximum(9999);
        duration1->setValue(100);

        gridLayout_4->addWidget(duration1, 1, 1, 1, 1);

        duration2 = new QSpinBox(colorcycle_edit);
        duration2->setObjectName(QString::fromUtf8("duration2"));
        duration2->setMaximum(9999);
        duration2->setValue(100);

        gridLayout_4->addWidget(duration2, 1, 3, 1, 1);

        duration3 = new QSpinBox(colorcycle_edit);
        duration3->setObjectName(QString::fromUtf8("duration3"));
        duration3->setMaximum(9999);
        duration3->setValue(100);

        gridLayout_4->addWidget(duration3, 1, 5, 1, 1);

        duration4 = new QSpinBox(colorcycle_edit);
        duration4->setObjectName(QString::fromUtf8("duration4"));
        duration4->setMaximum(9999);
        duration4->setValue(100);

        gridLayout_4->addWidget(duration4, 1, 7, 1, 1);

        duration5 = new QSpinBox(colorcycle_edit);
        duration5->setObjectName(QString::fromUtf8("duration5"));
        duration5->setMaximum(9999);
        duration5->setValue(100);

        gridLayout_4->addWidget(duration5, 1, 9, 1, 1);

        duration6 = new QSpinBox(colorcycle_edit);
        duration6->setObjectName(QString::fromUtf8("duration6"));
        duration6->setMaximum(9999);
        duration6->setValue(100);

        gridLayout_4->addWidget(duration6, 2, 1, 1, 1);

        duration7 = new QSpinBox(colorcycle_edit);
        duration7->setObjectName(QString::fromUtf8("duration7"));
        duration7->setMaximum(9999);
        duration7->setValue(100);

        gridLayout_4->addWidget(duration7, 2, 3, 1, 1);

        duration8 = new QSpinBox(colorcycle_edit);
        duration8->setObjectName(QString::fromUtf8("duration8"));
        duration8->setMaximum(9999);
        duration8->setValue(100);

        gridLayout_4->addWidget(duration8, 2, 5, 1, 1);

        duration9 = new QSpinBox(colorcycle_edit);
        duration9->setObjectName(QString::fromUtf8("duration9"));
        duration9->setMaximum(9999);
        duration9->setValue(100);

        gridLayout_4->addWidget(duration9, 2, 7, 1, 1);

        duration10 = new QSpinBox(colorcycle_edit);
        duration10->setObjectName(QString::fromUtf8("duration10"));
        duration10->setMaximum(9999);
        duration10->setValue(100);

        gridLayout_4->addWidget(duration10, 2, 9, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        scrollArea = new QScrollArea(colorcycle_edit);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 341));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        map_preview = new colorcycle_map_preview(scrollAreaWidgetContents);
        map_preview->setObjectName(QString::fromUtf8("map_preview"));
        map_preview->setGeometry(QRect(0, -10, 821, 180));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(map_preview->sizePolicy().hasHeightForWidth());
        map_preview->setSizePolicy(sizePolicy2);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        gridLayout_3->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(colorcycle_edit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        stage_selector = new QComboBox(colorcycle_edit);
        stage_selector->setObjectName(QString::fromUtf8("stage_selector"));

        horizontalLayout->addWidget(stage_selector);

        label_3 = new QLabel(colorcycle_edit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_2 = new QComboBox(colorcycle_edit);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label_2 = new QLabel(colorcycle_edit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(colorcycle_edit);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        show_colorcycle1_checkbox = new QCheckBox(colorcycle_edit);
        show_colorcycle1_checkbox->setObjectName(QString::fromUtf8("show_colorcycle1_checkbox"));
        show_colorcycle1_checkbox->setChecked(true);

        horizontalLayout->addWidget(show_colorcycle1_checkbox);

        show_colorcycle2_checkbox = new QCheckBox(colorcycle_edit);
        show_colorcycle2_checkbox->setObjectName(QString::fromUtf8("show_colorcycle2_checkbox"));
        show_colorcycle2_checkbox->setChecked(true);

        horizontalLayout->addWidget(show_colorcycle2_checkbox);

        show_colorcycle3_checkbox = new QCheckBox(colorcycle_edit);
        show_colorcycle3_checkbox->setObjectName(QString::fromUtf8("show_colorcycle3_checkbox"));
        show_colorcycle3_checkbox->setChecked(true);

        horizontalLayout->addWidget(show_colorcycle3_checkbox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(colorcycle_edit);

        QMetaObject::connectSlotsByName(colorcycle_edit);
    } // setupUi

    void retranslateUi(QWidget *colorcycle_edit)
    {
        colorcycle_edit->setWindowTitle(QApplication::translate("colorcycle_edit", "Form", 0, QApplication::UnicodeUTF8));
        color_pick_button1->setText(QApplication::translate("colorcycle_edit", "Pick #1", 0, QApplication::UnicodeUTF8));
        color_pick_button2->setText(QApplication::translate("colorcycle_edit", "Pick #2", 0, QApplication::UnicodeUTF8));
        color_pick_button3->setText(QApplication::translate("colorcycle_edit", "Pick #3", 0, QApplication::UnicodeUTF8));
        color_pick_button4->setText(QApplication::translate("colorcycle_edit", "Pick #4", 0, QApplication::UnicodeUTF8));
        color_pick_button5->setText(QApplication::translate("colorcycle_edit", "Pick #5", 0, QApplication::UnicodeUTF8));
        color_pick_button6->setText(QApplication::translate("colorcycle_edit", "Pick #6", 0, QApplication::UnicodeUTF8));
        color_pick_button7->setText(QApplication::translate("colorcycle_edit", "Pick #7", 0, QApplication::UnicodeUTF8));
        color_pick_button8->setText(QApplication::translate("colorcycle_edit", "Pick #8", 0, QApplication::UnicodeUTF8));
        color_pick_button9->setText(QApplication::translate("colorcycle_edit", "Pick #9", 0, QApplication::UnicodeUTF8));
        color_pick_button10->setText(QApplication::translate("colorcycle_edit", "Pick #10", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("colorcycle_edit", "Stage:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("colorcycle_edit", "Map:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("colorcycle_edit", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("colorcycle_edit", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("colorcycle_edit", "2", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("colorcycle_edit", "Color Key:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("colorcycle_edit", "GREEN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("colorcycle_edit", "PURPLE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("colorcycle_edit", "CYAN", 0, QApplication::UnicodeUTF8)
        );
        show_colorcycle1_checkbox->setText(QApplication::translate("colorcycle_edit", "Show #1", 0, QApplication::UnicodeUTF8));
        show_colorcycle2_checkbox->setText(QApplication::translate("colorcycle_edit", "Show #2", 0, QApplication::UnicodeUTF8));
        show_colorcycle3_checkbox->setText(QApplication::translate("colorcycle_edit", "Show #3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class colorcycle_edit: public Ui_colorcycle_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORCYCLE_H
