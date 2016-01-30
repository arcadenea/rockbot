/********************************************************************************
** Form generated from reading UI file 'stage_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGE_EDIT_H
#define UI_STAGE_EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stage_edit
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *stages_tab_bgmusic_combo;
    QLabel *label_48;
    QComboBox *stages_tab_stage_combo;
    QLabel *label_49;
    QLineEdit *stages_tab_stage_name_lineedit;
    QLineEdit *stages_tab_bossname_lineedit;
    QLabel *label_8;
    QLabel *label_50;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QComboBox *dialogs_line1_face_combo;
    QLabel *label_51;
    QLineEdit *dialogs_line1_text1;
    QLineEdit *dialogs_line1_text2;
    QLineEdit *dialogs_line1_text3;
    QLabel *label_53;
    QLineEdit *dialogs_line2_text1;
    QLineEdit *dialogs_line2_text2;
    QLineEdit *dialogs_line2_text3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_54;
    QComboBox *dialogs_answer1_player;
    QLabel *label_55;
    QLineEdit *dialogs_answer1_text1;
    QLineEdit *dialogs_answer1_text2;
    QLineEdit *dialogs_answer1_text3;
    QLabel *label_57;
    QLineEdit *dialogs_answer2_text1;
    QLineEdit *dialogs_answer2_text2;
    QLineEdit *dialogs_answer2_text3;
    QLabel *label_20;
    QComboBox *stage_boss_weapon_combo;
    QLabel *label_63;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_21;
    QLineEdit *boss_dialog_text1_line1;
    QLineEdit *boss_dialog_text1_line2;
    QLineEdit *boss_dialog_text1_line3;
    QLabel *label_24;
    QLineEdit *boss_dialog_text2_line1;
    QLineEdit *boss_dialog_text2_line2;
    QLineEdit *boss_dialog_text2_line3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *boss_dialog_answer1_line1;
    QLineEdit *boss_dialog_answer1_line2;
    QLineEdit *boss_dialog_answer1_line3;
    QLabel *label_2;
    QLineEdit *boss_dialog_answer2_line1;
    QLineEdit *boss_dialog_answer2_line2;
    QLineEdit *boss_dialog_answer2_line3;
    QComboBox *bossface_comboBox;

    void setupUi(QWidget *stage_edit)
    {
        if (stage_edit->objectName().isEmpty())
            stage_edit->setObjectName(QString::fromUtf8("stage_edit"));
        stage_edit->resize(907, 831);
        gridLayout = new QGridLayout(stage_edit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(stage_edit);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 893, 817));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, -1, 10, 10);
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 3, 2, 1, 1);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 5, 0, 1, 1);

        stages_tab_bgmusic_combo = new QComboBox(scrollAreaWidgetContents);
        stages_tab_bgmusic_combo->setObjectName(QString::fromUtf8("stages_tab_bgmusic_combo"));

        gridLayout_4->addWidget(stages_tab_bgmusic_combo, 5, 1, 1, 1);

        label_48 = new QLabel(scrollAreaWidgetContents);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_4->addWidget(label_48, 0, 0, 1, 1);

        stages_tab_stage_combo = new QComboBox(scrollAreaWidgetContents);
        stages_tab_stage_combo->setObjectName(QString::fromUtf8("stages_tab_stage_combo"));

        gridLayout_4->addWidget(stages_tab_stage_combo, 0, 1, 1, 1);

        label_49 = new QLabel(scrollAreaWidgetContents);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_4->addWidget(label_49, 1, 0, 1, 1);

        stages_tab_stage_name_lineedit = new QLineEdit(scrollAreaWidgetContents);
        stages_tab_stage_name_lineedit->setObjectName(QString::fromUtf8("stages_tab_stage_name_lineedit"));
        stages_tab_stage_name_lineedit->setMaxLength(30);

        gridLayout_4->addWidget(stages_tab_stage_name_lineedit, 1, 1, 1, 1);

        stages_tab_bossname_lineedit = new QLineEdit(scrollAreaWidgetContents);
        stages_tab_bossname_lineedit->setObjectName(QString::fromUtf8("stages_tab_bossname_lineedit"));
        stages_tab_bossname_lineedit->setMaxLength(30);

        gridLayout_4->addWidget(stages_tab_bossname_lineedit, 3, 1, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 3, 0, 1, 1);

        label_50 = new QLabel(scrollAreaWidgetContents);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_4->addWidget(label_50, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 8, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);

        dialogs_line1_face_combo = new QComboBox(scrollAreaWidgetContents);
        dialogs_line1_face_combo->setObjectName(QString::fromUtf8("dialogs_line1_face_combo"));
        dialogs_line1_face_combo->setIconSize(QSize(32, 32));

        verticalLayout_7->addWidget(dialogs_line1_face_combo);

        label_51 = new QLabel(scrollAreaWidgetContents);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        verticalLayout_7->addWidget(label_51);

        dialogs_line1_text1 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line1_text1->setObjectName(QString::fromUtf8("dialogs_line1_text1"));
        dialogs_line1_text1->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line1_text1);

        dialogs_line1_text2 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line1_text2->setObjectName(QString::fromUtf8("dialogs_line1_text2"));
        dialogs_line1_text2->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line1_text2);

        dialogs_line1_text3 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line1_text3->setObjectName(QString::fromUtf8("dialogs_line1_text3"));
        dialogs_line1_text3->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line1_text3);

        label_53 = new QLabel(scrollAreaWidgetContents);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        verticalLayout_7->addWidget(label_53);

        dialogs_line2_text1 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line2_text1->setObjectName(QString::fromUtf8("dialogs_line2_text1"));
        dialogs_line2_text1->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line2_text1);

        dialogs_line2_text2 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line2_text2->setObjectName(QString::fromUtf8("dialogs_line2_text2"));
        dialogs_line2_text2->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line2_text2);

        dialogs_line2_text3 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_line2_text3->setObjectName(QString::fromUtf8("dialogs_line2_text3"));
        dialogs_line2_text3->setMaxLength(30);

        verticalLayout_7->addWidget(dialogs_line2_text3);


        gridLayout_4->addLayout(verticalLayout_7, 6, 1, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_54 = new QLabel(scrollAreaWidgetContents);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        verticalLayout_8->addWidget(label_54);

        dialogs_answer1_player = new QComboBox(scrollAreaWidgetContents);
        dialogs_answer1_player->setObjectName(QString::fromUtf8("dialogs_answer1_player"));

        verticalLayout_8->addWidget(dialogs_answer1_player);

        label_55 = new QLabel(scrollAreaWidgetContents);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        verticalLayout_8->addWidget(label_55);

        dialogs_answer1_text1 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer1_text1->setObjectName(QString::fromUtf8("dialogs_answer1_text1"));
        dialogs_answer1_text1->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer1_text1);

        dialogs_answer1_text2 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer1_text2->setObjectName(QString::fromUtf8("dialogs_answer1_text2"));
        dialogs_answer1_text2->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer1_text2);

        dialogs_answer1_text3 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer1_text3->setObjectName(QString::fromUtf8("dialogs_answer1_text3"));
        dialogs_answer1_text3->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer1_text3);

        label_57 = new QLabel(scrollAreaWidgetContents);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        verticalLayout_8->addWidget(label_57);

        dialogs_answer2_text1 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer2_text1->setObjectName(QString::fromUtf8("dialogs_answer2_text1"));
        dialogs_answer2_text1->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer2_text1);

        dialogs_answer2_text2 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer2_text2->setObjectName(QString::fromUtf8("dialogs_answer2_text2"));
        dialogs_answer2_text2->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer2_text2);

        dialogs_answer2_text3 = new QLineEdit(scrollAreaWidgetContents);
        dialogs_answer2_text3->setObjectName(QString::fromUtf8("dialogs_answer2_text3"));
        dialogs_answer2_text3->setMaxLength(30);

        verticalLayout_8->addWidget(dialogs_answer2_text3);


        gridLayout_4->addLayout(verticalLayout_8, 6, 3, 1, 1);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 7, 0, 1, 1);

        stage_boss_weapon_combo = new QComboBox(scrollAreaWidgetContents);
        stage_boss_weapon_combo->setObjectName(QString::fromUtf8("stage_boss_weapon_combo"));

        gridLayout_4->addWidget(stage_boss_weapon_combo, 5, 3, 1, 1);

        label_63 = new QLabel(scrollAreaWidgetContents);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_4->addWidget(label_63, 5, 2, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_12->addWidget(label_21);

        boss_dialog_text1_line1 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text1_line1->setObjectName(QString::fromUtf8("boss_dialog_text1_line1"));
        boss_dialog_text1_line1->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text1_line1);

        boss_dialog_text1_line2 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text1_line2->setObjectName(QString::fromUtf8("boss_dialog_text1_line2"));
        boss_dialog_text1_line2->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text1_line2);

        boss_dialog_text1_line3 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text1_line3->setObjectName(QString::fromUtf8("boss_dialog_text1_line3"));
        boss_dialog_text1_line3->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text1_line3);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_12->addWidget(label_24);

        boss_dialog_text2_line1 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text2_line1->setObjectName(QString::fromUtf8("boss_dialog_text2_line1"));
        boss_dialog_text2_line1->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text2_line1);

        boss_dialog_text2_line2 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text2_line2->setObjectName(QString::fromUtf8("boss_dialog_text2_line2"));
        boss_dialog_text2_line2->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text2_line2);

        boss_dialog_text2_line3 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_text2_line3->setObjectName(QString::fromUtf8("boss_dialog_text2_line3"));
        boss_dialog_text2_line3->setMaxLength(30);

        verticalLayout_12->addWidget(boss_dialog_text2_line3);


        gridLayout_4->addLayout(verticalLayout_12, 7, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        boss_dialog_answer1_line1 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer1_line1->setObjectName(QString::fromUtf8("boss_dialog_answer1_line1"));
        boss_dialog_answer1_line1->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer1_line1);

        boss_dialog_answer1_line2 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer1_line2->setObjectName(QString::fromUtf8("boss_dialog_answer1_line2"));
        boss_dialog_answer1_line2->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer1_line2);

        boss_dialog_answer1_line3 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer1_line3->setObjectName(QString::fromUtf8("boss_dialog_answer1_line3"));
        boss_dialog_answer1_line3->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer1_line3);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        boss_dialog_answer2_line1 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer2_line1->setObjectName(QString::fromUtf8("boss_dialog_answer2_line1"));
        boss_dialog_answer2_line1->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer2_line1);

        boss_dialog_answer2_line2 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer2_line2->setObjectName(QString::fromUtf8("boss_dialog_answer2_line2"));
        boss_dialog_answer2_line2->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer2_line2);

        boss_dialog_answer2_line3 = new QLineEdit(scrollAreaWidgetContents);
        boss_dialog_answer2_line3->setObjectName(QString::fromUtf8("boss_dialog_answer2_line3"));
        boss_dialog_answer2_line3->setMaxLength(30);

        verticalLayout->addWidget(boss_dialog_answer2_line3);


        gridLayout_4->addLayout(verticalLayout, 7, 3, 1, 1);

        bossface_comboBox = new QComboBox(scrollAreaWidgetContents);
        bossface_comboBox->setObjectName(QString::fromUtf8("bossface_comboBox"));
        bossface_comboBox->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(bossface_comboBox, 3, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(stage_edit);

        QMetaObject::connectSlotsByName(stage_edit);
    } // setupUi

    void retranslateUi(QWidget *stage_edit)
    {
        stage_edit->setWindowTitle(QApplication::translate("stage_edit", "Form", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("stage_edit", "Boss Face File:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("stage_edit", "BG Music File:", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("stage_edit", "Stage:", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("stage_edit", "Stage Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("stage_edit", "Boss Name:", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("stage_edit", "Stage Dialogs:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("stage_edit", "Face:", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("stage_edit", "Line1 Text:", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("stage_edit", "Line2 Text:", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("stage_edit", "Answer Player:", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("stage_edit", "Answer 1 text:", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("stage_edit", "Answer 2 Text:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("stage_edit", "Boss Dialogs:", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("stage_edit", "Boss Weapon:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("stage_edit", "Boss Line 1 Text:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("stage_edit", "Boss Line 2 text:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("stage_edit", "Player Answer 1 Text:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("stage_edit", "Player Answer 2 text:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class stage_edit: public Ui_stage_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGE_EDIT_H
