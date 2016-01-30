/********************************************************************************
** Form generated from reading UI file 'game_properties_tab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_PROPERTIES_TAB_H
#define UI_GAME_PROPERTIES_TAB_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_properties_tab
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QComboBox *special_item2_combo;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QComboBox *semicharged_shot_combo;
    QSpacerItem *verticalSpacer;
    QComboBox *special_item1_combo;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *stagefaces_stage_combo;
    QComboBox *stagefaces_face_combo;
    QLineEdit *lineEdit;
    QLabel *label_5;

    void setupUi(QWidget *game_properties_tab)
    {
        if (game_properties_tab->objectName().isEmpty())
            game_properties_tab->setObjectName(QString::fromUtf8("game_properties_tab"));
        game_properties_tab->resize(669, 437);
        horizontalLayout = new QHBoxLayout(game_properties_tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        special_item2_combo = new QComboBox(game_properties_tab);
        special_item2_combo->setObjectName(QString::fromUtf8("special_item2_combo"));

        gridLayout_2->addWidget(special_item2_combo, 2, 1, 1, 1);

        label_2 = new QLabel(game_properties_tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(game_properties_tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(game_properties_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        semicharged_shot_combo = new QComboBox(game_properties_tab);
        semicharged_shot_combo->setObjectName(QString::fromUtf8("semicharged_shot_combo"));

        gridLayout_2->addWidget(semicharged_shot_combo, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        special_item1_combo = new QComboBox(game_properties_tab);
        special_item1_combo->setObjectName(QString::fromUtf8("special_item1_combo"));

        gridLayout_2->addWidget(special_item1_combo, 1, 1, 1, 1);

        label_4 = new QLabel(game_properties_tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stagefaces_stage_combo = new QComboBox(game_properties_tab);
        stagefaces_stage_combo->setObjectName(QString::fromUtf8("stagefaces_stage_combo"));

        horizontalLayout_2->addWidget(stagefaces_stage_combo);

        stagefaces_face_combo = new QComboBox(game_properties_tab);
        stagefaces_face_combo->setObjectName(QString::fromUtf8("stagefaces_face_combo"));
        stagefaces_face_combo->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(stagefaces_face_combo);


        gridLayout_2->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        lineEdit = new QLineEdit(game_properties_tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(30);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(game_properties_tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        retranslateUi(game_properties_tab);

        QMetaObject::connectSlotsByName(game_properties_tab);
    } // setupUi

    void retranslateUi(QWidget *game_properties_tab)
    {
        game_properties_tab->setWindowTitle(QApplication::translate("game_properties_tab", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("game_properties_tab", "Special Item #2:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("game_properties_tab", "Special Item #1:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("game_properties_tab", "Semi-Charged Shot:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("game_properties_tab", "Stages Faces:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("game_properties_tab", "Game Name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class game_properties_tab: public Ui_game_properties_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_PROPERTIES_TAB_H
