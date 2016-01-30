/********************************************************************************
** Form generated from reading UI file 'artificial_inteligence_tab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTIFICIAL_INTELIGENCE_TAB_H
#define UI_ARTIFICIAL_INTELIGENCE_TAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_artificial_inteligence_tab
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_5;
    QLabel *label_20;
    QLabel *label_21;
    QComboBox *near_action;
    QLabel *label_11;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_13;
    QComboBox *hit_action;
    QComboBox *hit_extra_parameter;
    QComboBox *dead_action;
    QComboBox *near_extra_parameter;
    QComboBox *dead_extra_parameter;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *ai_name;
    QGridLayout *gridLayout_2;
    QComboBox *action1;
    QComboBox *action3;
    QSpinBox *chance3;
    QLabel *label_3;
    QSpinBox *chance2;
    QComboBox *action4;
    QLabel *label_15;
    QLabel *label_5;
    QLabel *label_16;
    QComboBox *next2;
    QComboBox *next1;
    QSpinBox *delay3;
    QLabel *label_8;
    QSpinBox *delay1;
    QComboBox *next3;
    QComboBox *parameter3;
    QComboBox *parameter2;
    QLabel *label;
    QSpinBox *delay4;
    QComboBox *action2;
    QLabel *label_10;
    QLabel *label_12;
    QComboBox *next4;
    QComboBox *parameter4;
    QLabel *label_17;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_9;
    QSpinBox *chance5;
    QSpinBox *chance6;
    QSpinBox *chance7;
    QSpinBox *chance8;
    QComboBox *action5;
    QComboBox *action6;
    QSpinBox *delay2;
    QLabel *label_14;
    QComboBox *parameter1;
    QLabel *label_4;
    QSpinBox *chance1;
    QSpinBox *chance4;
    QComboBox *next8;
    QSpinBox *delay5;
    QSpinBox *delay6;
    QSpinBox *delay7;
    QSpinBox *delay8;
    QComboBox *action7;
    QComboBox *action8;
    QComboBox *parameter5;
    QComboBox *next5;
    QComboBox *parameter6;
    QComboBox *parameter7;
    QComboBox *parameter8;
    QComboBox *next6;
    QComboBox *next7;
    QComboBox *ai_selector;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QWidget *artificial_inteligence_tab)
    {
        if (artificial_inteligence_tab->objectName().isEmpty())
            artificial_inteligence_tab->setObjectName(QString::fromUtf8("artificial_inteligence_tab"));
        artificial_inteligence_tab->resize(742, 470);
        gridLayout = new QGridLayout(artificial_inteligence_tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, -1, -1, 10);
        label_20 = new QLabel(artificial_inteligence_tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_5->addWidget(label_20, 2, 0, 1, 1);

        label_21 = new QLabel(artificial_inteligence_tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_5->addWidget(label_21, 3, 0, 1, 1);

        near_action = new QComboBox(artificial_inteligence_tab);
        near_action->setObjectName(QString::fromUtf8("near_action"));

        gridLayout_5->addWidget(near_action, 1, 1, 1, 1);

        label_11 = new QLabel(artificial_inteligence_tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 1, 1, 1);

        label_18 = new QLabel(artificial_inteligence_tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_5->addWidget(label_18, 0, 2, 1, 1);

        label_19 = new QLabel(artificial_inteligence_tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_5->addWidget(label_19, 0, 0, 1, 1);

        label_13 = new QLabel(artificial_inteligence_tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 1, 0, 1, 1);

        hit_action = new QComboBox(artificial_inteligence_tab);
        hit_action->setObjectName(QString::fromUtf8("hit_action"));

        gridLayout_5->addWidget(hit_action, 2, 1, 1, 1);

        hit_extra_parameter = new QComboBox(artificial_inteligence_tab);
        hit_extra_parameter->setObjectName(QString::fromUtf8("hit_extra_parameter"));

        gridLayout_5->addWidget(hit_extra_parameter, 2, 2, 1, 1);

        dead_action = new QComboBox(artificial_inteligence_tab);
        dead_action->setObjectName(QString::fromUtf8("dead_action"));

        gridLayout_5->addWidget(dead_action, 3, 1, 1, 1);

        near_extra_parameter = new QComboBox(artificial_inteligence_tab);
        near_extra_parameter->setObjectName(QString::fromUtf8("near_extra_parameter"));

        gridLayout_5->addWidget(near_extra_parameter, 1, 2, 1, 1);

        dead_extra_parameter = new QComboBox(artificial_inteligence_tab);
        dead_extra_parameter->setObjectName(QString::fromUtf8("dead_extra_parameter"));

        gridLayout_5->addWidget(dead_extra_parameter, 3, 2, 1, 1);


        gridLayout->addLayout(gridLayout_5, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(artificial_inteligence_tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        ai_name = new QLineEdit(artificial_inteligence_tab);
        ai_name->setObjectName(QString::fromUtf8("ai_name"));
        ai_name->setMaxLength(30);

        horizontalLayout->addWidget(ai_name);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 6, -1, -1);
        action1 = new QComboBox(artificial_inteligence_tab);
        action1->setObjectName(QString::fromUtf8("action1"));

        gridLayout_2->addWidget(action1, 1, 2, 1, 1);

        action3 = new QComboBox(artificial_inteligence_tab);
        action3->setObjectName(QString::fromUtf8("action3"));

        gridLayout_2->addWidget(action3, 3, 2, 1, 1);

        chance3 = new QSpinBox(artificial_inteligence_tab);
        chance3->setObjectName(QString::fromUtf8("chance3"));
        chance3->setMaximum(100);
        chance3->setValue(20);

        gridLayout_2->addWidget(chance3, 3, 1, 1, 1);

        label_3 = new QLabel(artificial_inteligence_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);

        chance2 = new QSpinBox(artificial_inteligence_tab);
        chance2->setObjectName(QString::fromUtf8("chance2"));
        chance2->setMaximum(100);
        chance2->setValue(15);

        gridLayout_2->addWidget(chance2, 2, 1, 1, 1);

        action4 = new QComboBox(artificial_inteligence_tab);
        action4->setObjectName(QString::fromUtf8("action4"));

        gridLayout_2->addWidget(action4, 4, 2, 1, 1);

        label_15 = new QLabel(artificial_inteligence_tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 0, 2, 1, 1);

        label_5 = new QLabel(artificial_inteligence_tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 7, 0, 1, 1);

        label_16 = new QLabel(artificial_inteligence_tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 0, 4, 1, 1);

        next2 = new QComboBox(artificial_inteligence_tab);
        next2->setObjectName(QString::fromUtf8("next2"));

        gridLayout_2->addWidget(next2, 2, 4, 1, 1);

        next1 = new QComboBox(artificial_inteligence_tab);
        next1->setObjectName(QString::fromUtf8("next1"));

        gridLayout_2->addWidget(next1, 1, 4, 1, 1);

        delay3 = new QSpinBox(artificial_inteligence_tab);
        delay3->setObjectName(QString::fromUtf8("delay3"));
        delay3->setMaximum(9999);
        delay3->setValue(200);

        gridLayout_2->addWidget(delay3, 3, 5, 1, 1);

        label_8 = new QLabel(artificial_inteligence_tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        delay1 = new QSpinBox(artificial_inteligence_tab);
        delay1->setObjectName(QString::fromUtf8("delay1"));
        delay1->setMaximum(9999);
        delay1->setValue(200);

        gridLayout_2->addWidget(delay1, 1, 5, 1, 1);

        next3 = new QComboBox(artificial_inteligence_tab);
        next3->setObjectName(QString::fromUtf8("next3"));

        gridLayout_2->addWidget(next3, 3, 4, 1, 1);

        parameter3 = new QComboBox(artificial_inteligence_tab);
        parameter3->setObjectName(QString::fromUtf8("parameter3"));

        gridLayout_2->addWidget(parameter3, 3, 3, 1, 1);

        parameter2 = new QComboBox(artificial_inteligence_tab);
        parameter2->setObjectName(QString::fromUtf8("parameter2"));

        gridLayout_2->addWidget(parameter2, 2, 3, 1, 1);

        label = new QLabel(artificial_inteligence_tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 3, 1, 1);

        delay4 = new QSpinBox(artificial_inteligence_tab);
        delay4->setObjectName(QString::fromUtf8("delay4"));
        delay4->setMaximum(9999);
        delay4->setValue(200);

        gridLayout_2->addWidget(delay4, 4, 5, 1, 1);

        action2 = new QComboBox(artificial_inteligence_tab);
        action2->setObjectName(QString::fromUtf8("action2"));

        gridLayout_2->addWidget(action2, 2, 2, 1, 1);

        label_10 = new QLabel(artificial_inteligence_tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_12 = new QLabel(artificial_inteligence_tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        next4 = new QComboBox(artificial_inteligence_tab);
        next4->setObjectName(QString::fromUtf8("next4"));

        gridLayout_2->addWidget(next4, 4, 4, 1, 1);

        parameter4 = new QComboBox(artificial_inteligence_tab);
        parameter4->setObjectName(QString::fromUtf8("parameter4"));

        gridLayout_2->addWidget(parameter4, 4, 3, 1, 1);

        label_17 = new QLabel(artificial_inteligence_tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 0, 5, 1, 1);

        label_7 = new QLabel(artificial_inteligence_tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        label_6 = new QLabel(artificial_inteligence_tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_9 = new QLabel(artificial_inteligence_tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 8, 0, 1, 1);

        chance5 = new QSpinBox(artificial_inteligence_tab);
        chance5->setObjectName(QString::fromUtf8("chance5"));
        chance5->setMaximum(100);

        gridLayout_2->addWidget(chance5, 5, 1, 1, 1);

        chance6 = new QSpinBox(artificial_inteligence_tab);
        chance6->setObjectName(QString::fromUtf8("chance6"));
        chance6->setMaximum(100);

        gridLayout_2->addWidget(chance6, 6, 1, 1, 1);

        chance7 = new QSpinBox(artificial_inteligence_tab);
        chance7->setObjectName(QString::fromUtf8("chance7"));
        chance7->setMaximum(100);

        gridLayout_2->addWidget(chance7, 7, 1, 1, 1);

        chance8 = new QSpinBox(artificial_inteligence_tab);
        chance8->setObjectName(QString::fromUtf8("chance8"));
        chance8->setMaximum(100);

        gridLayout_2->addWidget(chance8, 8, 1, 1, 1);

        action5 = new QComboBox(artificial_inteligence_tab);
        action5->setObjectName(QString::fromUtf8("action5"));

        gridLayout_2->addWidget(action5, 5, 2, 1, 1);

        action6 = new QComboBox(artificial_inteligence_tab);
        action6->setObjectName(QString::fromUtf8("action6"));

        gridLayout_2->addWidget(action6, 6, 2, 1, 1);

        delay2 = new QSpinBox(artificial_inteligence_tab);
        delay2->setObjectName(QString::fromUtf8("delay2"));
        delay2->setMaximum(9999);
        delay2->setValue(200);

        gridLayout_2->addWidget(delay2, 2, 5, 1, 1);

        label_14 = new QLabel(artificial_inteligence_tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        parameter1 = new QComboBox(artificial_inteligence_tab);
        parameter1->setObjectName(QString::fromUtf8("parameter1"));

        gridLayout_2->addWidget(parameter1, 1, 3, 1, 1);

        label_4 = new QLabel(artificial_inteligence_tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        chance1 = new QSpinBox(artificial_inteligence_tab);
        chance1->setObjectName(QString::fromUtf8("chance1"));
        chance1->setMaximum(100);
        chance1->setValue(35);

        gridLayout_2->addWidget(chance1, 1, 1, 1, 1);

        chance4 = new QSpinBox(artificial_inteligence_tab);
        chance4->setObjectName(QString::fromUtf8("chance4"));
        chance4->setMaximum(100);
        chance4->setValue(30);

        gridLayout_2->addWidget(chance4, 4, 1, 1, 1);

        next8 = new QComboBox(artificial_inteligence_tab);
        next8->setObjectName(QString::fromUtf8("next8"));

        gridLayout_2->addWidget(next8, 8, 4, 1, 1);

        delay5 = new QSpinBox(artificial_inteligence_tab);
        delay5->setObjectName(QString::fromUtf8("delay5"));
        delay5->setMaximum(9999);
        delay5->setValue(200);

        gridLayout_2->addWidget(delay5, 5, 5, 1, 1);

        delay6 = new QSpinBox(artificial_inteligence_tab);
        delay6->setObjectName(QString::fromUtf8("delay6"));
        delay6->setMaximum(9999);
        delay6->setValue(200);

        gridLayout_2->addWidget(delay6, 6, 5, 1, 1);

        delay7 = new QSpinBox(artificial_inteligence_tab);
        delay7->setObjectName(QString::fromUtf8("delay7"));
        delay7->setMaximum(9999);
        delay7->setValue(200);

        gridLayout_2->addWidget(delay7, 7, 5, 1, 1);

        delay8 = new QSpinBox(artificial_inteligence_tab);
        delay8->setObjectName(QString::fromUtf8("delay8"));
        delay8->setMaximum(9999);
        delay8->setValue(200);

        gridLayout_2->addWidget(delay8, 8, 5, 1, 1);

        action7 = new QComboBox(artificial_inteligence_tab);
        action7->setObjectName(QString::fromUtf8("action7"));

        gridLayout_2->addWidget(action7, 7, 2, 1, 1);

        action8 = new QComboBox(artificial_inteligence_tab);
        action8->setObjectName(QString::fromUtf8("action8"));

        gridLayout_2->addWidget(action8, 8, 2, 1, 1);

        parameter5 = new QComboBox(artificial_inteligence_tab);
        parameter5->setObjectName(QString::fromUtf8("parameter5"));

        gridLayout_2->addWidget(parameter5, 5, 3, 1, 1);

        next5 = new QComboBox(artificial_inteligence_tab);
        next5->setObjectName(QString::fromUtf8("next5"));

        gridLayout_2->addWidget(next5, 5, 4, 1, 1);

        parameter6 = new QComboBox(artificial_inteligence_tab);
        parameter6->setObjectName(QString::fromUtf8("parameter6"));

        gridLayout_2->addWidget(parameter6, 6, 3, 1, 1);

        parameter7 = new QComboBox(artificial_inteligence_tab);
        parameter7->setObjectName(QString::fromUtf8("parameter7"));

        gridLayout_2->addWidget(parameter7, 7, 3, 1, 1);

        parameter8 = new QComboBox(artificial_inteligence_tab);
        parameter8->setObjectName(QString::fromUtf8("parameter8"));

        gridLayout_2->addWidget(parameter8, 8, 3, 1, 1);

        next6 = new QComboBox(artificial_inteligence_tab);
        next6->setObjectName(QString::fromUtf8("next6"));

        gridLayout_2->addWidget(next6, 6, 4, 1, 1);

        next7 = new QComboBox(artificial_inteligence_tab);
        next7->setObjectName(QString::fromUtf8("next7"));

        gridLayout_2->addWidget(next7, 7, 4, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 1, 1, 1);

        ai_selector = new QComboBox(artificial_inteligence_tab);
        ai_selector->setObjectName(QString::fromUtf8("ai_selector"));

        gridLayout->addWidget(ai_selector, 0, 1, 1, 1);

        line = new QFrame(artificial_inteligence_tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 1, 1, 1);

        line_2 = new QFrame(artificial_inteligence_tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 1, 1, 1);


        retranslateUi(artificial_inteligence_tab);

        QMetaObject::connectSlotsByName(artificial_inteligence_tab);
    } // setupUi

    void retranslateUi(QWidget *artificial_inteligence_tab)
    {
        artificial_inteligence_tab->setWindowTitle(QApplication::translate("artificial_inteligence_tab", "Form", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("artificial_inteligence_tab", "Hit", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("artificial_inteligence_tab", "Dead", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("artificial_inteligence_tab", "Action", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("artificial_inteligence_tab", "Extra Parameter", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("artificial_inteligence_tab", "Reaction", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("artificial_inteligence_tab", "Near player", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("artificial_inteligence_tab", "A.I. Name:", 0, QApplication::UnicodeUTF8));
        ai_name->setText(QString());
        label_3->setText(QApplication::translate("artificial_inteligence_tab", "#5:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("artificial_inteligence_tab", "Action", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("artificial_inteligence_tab", "#7:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("artificial_inteligence_tab", "Goto Next", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("artificial_inteligence_tab", "#2:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("artificial_inteligence_tab", "Extra Parameter", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("artificial_inteligence_tab", "#3:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("artificial_inteligence_tab", "#4:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("artificial_inteligence_tab", "Goto Delay", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("artificial_inteligence_tab", "Chance", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("artificial_inteligence_tab", "#1:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("artificial_inteligence_tab", "#8:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("artificial_inteligence_tab", "Number", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("artificial_inteligence_tab", "#6:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class artificial_inteligence_tab: public Ui_artificial_inteligence_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTIFICIAL_INTELIGENCE_TAB_H
