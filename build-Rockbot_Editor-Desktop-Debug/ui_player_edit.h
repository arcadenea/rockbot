/********************************************************************************
** Form generated from reading UI file 'player_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_EDIT_H
#define UI_PLAYER_EDIT_H

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
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "player_preview_area.h"

QT_BEGIN_NAMESPACE

class Ui_player_edit
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox_2;
    QWidget *page_properties;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QLabel *label_34;
    QSpacerItem *horizontalSpacer;
    QLabel *label_16;
    QCheckBox *canDoubleJumpCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QComboBox *chargedshot_combo;
    QCheckBox *CanAirDashCheckBox;
    QSpinBox *players_tab_hp;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *players_tab_list_combo;
    QLabel *label_2;
    QCheckBox *canShotDiagonal;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *players_tab_maxshots;
    QLineEdit *players_tab_name;
    QCheckBox *players_tab_hasshield;
    QCheckBox *can_slide_checkbox;
    QSpinBox *damageModSpinBox;
    QWidget *page_graphics;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_41;
    QSpinBox *player_sprite_w;
    QLabel *label_42;
    QSpinBox *player_sprite_h;
    QComboBox *player_graphics_combo;
    QLabel *label_47;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *color1_picker;
    QPushButton *ColorValueIndicator1;
    QPushButton *color2_picker;
    QPushButton *ColorValueIndicator2;
    QPushButton *color3_picker;
    QPushButton *ColorValueIndicator3;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *key1_picker;
    QPushButton *ColorKeyIndicator1;
    QPushButton *key2_picker;
    QPushButton *ColorKeyIndicator2;
    QPushButton *key3_picker;
    QPushButton *ColorKeyIndicator3;
    QComboBox *players_tab_list_combo_2;
    QLabel *label;
    QComboBox *weaponlist_combo;
    QLabel *label_19;
    QLabel *label_40;
    QLabel *label_39;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_43;
    QSpinBox *player_hitarea_x;
    QLabel *label_44;
    QSpinBox *player_hitarea_y;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_45;
    QSpinBox *player_hitarea_w;
    QLabel *label_46;
    QSpinBox *player_hitarea_h;
    QLabel *label_38;
    QLabel *label_5;
    QComboBox *playerFace_comboBox;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    player_preview_area *player_preview_widget;

    void setupUi(QWidget *player_edit)
    {
        if (player_edit->objectName().isEmpty())
            player_edit->setObjectName(QString::fromUtf8("player_edit"));
        player_edit->resize(770, 469);
        gridLayout = new QGridLayout(player_edit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolBox_2 = new QToolBox(player_edit);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        page_properties = new QWidget();
        page_properties->setObjectName(QString::fromUtf8("page_properties"));
        page_properties->setGeometry(QRect(0, 0, 752, 393));
        gridLayout_2 = new QGridLayout(page_properties);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, 10, -1);
        label_18 = new QLabel(page_properties);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 4, 0, 1, 1);

        label_34 = new QLabel(page_properties);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_3->addWidget(label_34, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_16 = new QLabel(page_properties);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        canDoubleJumpCheckBox = new QCheckBox(page_properties);
        canDoubleJumpCheckBox->setObjectName(QString::fromUtf8("canDoubleJumpCheckBox"));

        gridLayout_3->addWidget(canDoubleJumpCheckBox, 1, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        label_4 = new QLabel(page_properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 3, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 9, 0, 1, 1);

        label_6 = new QLabel(page_properties);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 8, 0, 1, 1);

        chargedshot_combo = new QComboBox(page_properties);
        chargedshot_combo->setObjectName(QString::fromUtf8("chargedshot_combo"));

        gridLayout_3->addWidget(chargedshot_combo, 8, 2, 1, 1);

        CanAirDashCheckBox = new QCheckBox(page_properties);
        CanAirDashCheckBox->setObjectName(QString::fromUtf8("CanAirDashCheckBox"));

        gridLayout_3->addWidget(CanAirDashCheckBox, 2, 6, 1, 1);

        players_tab_hp = new QSpinBox(page_properties);
        players_tab_hp->setObjectName(QString::fromUtf8("players_tab_hp"));
        players_tab_hp->setMinimum(1);
        players_tab_hp->setValue(32);

        gridLayout_3->addWidget(players_tab_hp, 2, 2, 1, 1);

        label_14 = new QLabel(page_properties);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(page_properties);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        label_17 = new QLabel(page_properties);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 3, 0, 1, 1);

        label_3 = new QLabel(page_properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 4, 1, 1);

        label_8 = new QLabel(page_properties);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 4, 1, 1);

        players_tab_list_combo = new QComboBox(page_properties);
        players_tab_list_combo->setObjectName(QString::fromUtf8("players_tab_list_combo"));

        gridLayout_3->addWidget(players_tab_list_combo, 0, 2, 1, 1);

        label_2 = new QLabel(page_properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 4, 1, 1);

        canShotDiagonal = new QCheckBox(page_properties);
        canShotDiagonal->setObjectName(QString::fromUtf8("canShotDiagonal"));

        gridLayout_3->addWidget(canShotDiagonal, 3, 6, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 5, 1, 1);

        players_tab_maxshots = new QSpinBox(page_properties);
        players_tab_maxshots->setObjectName(QString::fromUtf8("players_tab_maxshots"));
        players_tab_maxshots->setMinimum(1);
        players_tab_maxshots->setValue(3);

        gridLayout_3->addWidget(players_tab_maxshots, 4, 2, 1, 1);

        players_tab_name = new QLineEdit(page_properties);
        players_tab_name->setObjectName(QString::fromUtf8("players_tab_name"));
        players_tab_name->setMaxLength(30);

        gridLayout_3->addWidget(players_tab_name, 1, 2, 1, 1);

        players_tab_hasshield = new QCheckBox(page_properties);
        players_tab_hasshield->setObjectName(QString::fromUtf8("players_tab_hasshield"));

        gridLayout_3->addWidget(players_tab_hasshield, 3, 2, 1, 1);

        can_slide_checkbox = new QCheckBox(page_properties);
        can_slide_checkbox->setObjectName(QString::fromUtf8("can_slide_checkbox"));

        gridLayout_3->addWidget(can_slide_checkbox, 0, 6, 1, 1);

        damageModSpinBox = new QSpinBox(page_properties);
        damageModSpinBox->setObjectName(QString::fromUtf8("damageModSpinBox"));
        damageModSpinBox->setMinimum(-3);
        damageModSpinBox->setMaximum(3);

        gridLayout_3->addWidget(damageModSpinBox, 5, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        toolBox_2->addItem(page_properties, QString::fromUtf8("Properties"));
        page_graphics = new QWidget();
        page_graphics->setObjectName(QString::fromUtf8("page_graphics"));
        page_graphics->setGeometry(QRect(0, 0, 752, 393));
        gridLayout_4 = new QGridLayout(page_graphics);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_41 = new QLabel(page_graphics);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_4->addWidget(label_41);

        player_sprite_w = new QSpinBox(page_graphics);
        player_sprite_w->setObjectName(QString::fromUtf8("player_sprite_w"));
        player_sprite_w->setValue(29);

        horizontalLayout_4->addWidget(player_sprite_w);

        label_42 = new QLabel(page_graphics);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_4->addWidget(label_42);

        player_sprite_h = new QSpinBox(page_graphics);
        player_sprite_h->setObjectName(QString::fromUtf8("player_sprite_h"));
        player_sprite_h->setValue(32);

        horizontalLayout_4->addWidget(player_sprite_h);


        gridLayout_9->addLayout(horizontalLayout_4, 3, 2, 1, 1);

        player_graphics_combo = new QComboBox(page_graphics);
        player_graphics_combo->setObjectName(QString::fromUtf8("player_graphics_combo"));

        gridLayout_9->addWidget(player_graphics_combo, 1, 2, 1, 1);

        label_47 = new QLabel(page_graphics);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_9->addWidget(label_47, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        color1_picker = new QPushButton(page_graphics);
        color1_picker->setObjectName(QString::fromUtf8("color1_picker"));

        horizontalLayout_7->addWidget(color1_picker);

        ColorValueIndicator1 = new QPushButton(page_graphics);
        ColorValueIndicator1->setObjectName(QString::fromUtf8("ColorValueIndicator1"));
        ColorValueIndicator1->setMinimumSize(QSize(32, 32));
        ColorValueIndicator1->setMaximumSize(QSize(32, 32));

        horizontalLayout_7->addWidget(ColorValueIndicator1);

        color2_picker = new QPushButton(page_graphics);
        color2_picker->setObjectName(QString::fromUtf8("color2_picker"));

        horizontalLayout_7->addWidget(color2_picker);

        ColorValueIndicator2 = new QPushButton(page_graphics);
        ColorValueIndicator2->setObjectName(QString::fromUtf8("ColorValueIndicator2"));
        ColorValueIndicator2->setMinimumSize(QSize(32, 32));
        ColorValueIndicator2->setMaximumSize(QSize(32, 32));

        horizontalLayout_7->addWidget(ColorValueIndicator2);

        color3_picker = new QPushButton(page_graphics);
        color3_picker->setObjectName(QString::fromUtf8("color3_picker"));

        horizontalLayout_7->addWidget(color3_picker);

        ColorValueIndicator3 = new QPushButton(page_graphics);
        ColorValueIndicator3->setObjectName(QString::fromUtf8("ColorValueIndicator3"));
        ColorValueIndicator3->setMinimumSize(QSize(32, 32));
        ColorValueIndicator3->setMaximumSize(QSize(32, 32));

        horizontalLayout_7->addWidget(ColorValueIndicator3);


        gridLayout_9->addLayout(horizontalLayout_7, 6, 2, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        key1_picker = new QPushButton(page_graphics);
        key1_picker->setObjectName(QString::fromUtf8("key1_picker"));

        horizontalLayout_9->addWidget(key1_picker);

        ColorKeyIndicator1 = new QPushButton(page_graphics);
        ColorKeyIndicator1->setObjectName(QString::fromUtf8("ColorKeyIndicator1"));
        ColorKeyIndicator1->setMinimumSize(QSize(32, 32));
        ColorKeyIndicator1->setMaximumSize(QSize(32, 32));

        horizontalLayout_9->addWidget(ColorKeyIndicator1);

        key2_picker = new QPushButton(page_graphics);
        key2_picker->setObjectName(QString::fromUtf8("key2_picker"));

        horizontalLayout_9->addWidget(key2_picker);

        ColorKeyIndicator2 = new QPushButton(page_graphics);
        ColorKeyIndicator2->setObjectName(QString::fromUtf8("ColorKeyIndicator2"));
        ColorKeyIndicator2->setMinimumSize(QSize(32, 32));
        ColorKeyIndicator2->setMaximumSize(QSize(32, 32));

        horizontalLayout_9->addWidget(ColorKeyIndicator2);

        key3_picker = new QPushButton(page_graphics);
        key3_picker->setObjectName(QString::fromUtf8("key3_picker"));

        horizontalLayout_9->addWidget(key3_picker);

        ColorKeyIndicator3 = new QPushButton(page_graphics);
        ColorKeyIndicator3->setObjectName(QString::fromUtf8("ColorKeyIndicator3"));
        ColorKeyIndicator3->setMinimumSize(QSize(32, 32));
        ColorKeyIndicator3->setMaximumSize(QSize(32, 32));

        horizontalLayout_9->addWidget(ColorKeyIndicator3);


        gridLayout_9->addLayout(horizontalLayout_9, 5, 2, 1, 1);

        players_tab_list_combo_2 = new QComboBox(page_graphics);
        players_tab_list_combo_2->setObjectName(QString::fromUtf8("players_tab_list_combo_2"));

        gridLayout_9->addWidget(players_tab_list_combo_2, 0, 2, 1, 1);

        label = new QLabel(page_graphics);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        weaponlist_combo = new QComboBox(page_graphics);
        weaponlist_combo->setObjectName(QString::fromUtf8("weaponlist_combo"));

        gridLayout_9->addWidget(weaponlist_combo, 6, 1, 1, 1);

        label_19 = new QLabel(page_graphics);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_9->addWidget(label_19, 6, 0, 1, 1);

        label_40 = new QLabel(page_graphics);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_9->addWidget(label_40, 4, 0, 1, 1);

        label_39 = new QLabel(page_graphics);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_9->addWidget(label_39, 3, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_43 = new QLabel(page_graphics);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_12->addWidget(label_43);

        player_hitarea_x = new QSpinBox(page_graphics);
        player_hitarea_x->setObjectName(QString::fromUtf8("player_hitarea_x"));
        player_hitarea_x->setValue(4);

        horizontalLayout_12->addWidget(player_hitarea_x);

        label_44 = new QLabel(page_graphics);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_12->addWidget(label_44);

        player_hitarea_y = new QSpinBox(page_graphics);
        player_hitarea_y->setObjectName(QString::fromUtf8("player_hitarea_y"));
        player_hitarea_y->setValue(8);

        horizontalLayout_12->addWidget(player_hitarea_y);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(4, 4, 4, 4);
        label_45 = new QLabel(page_graphics);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_13->addWidget(label_45);

        player_hitarea_w = new QSpinBox(page_graphics);
        player_hitarea_w->setObjectName(QString::fromUtf8("player_hitarea_w"));
        player_hitarea_w->setValue(21);

        horizontalLayout_13->addWidget(player_hitarea_w);

        label_46 = new QLabel(page_graphics);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_13->addWidget(label_46);

        player_hitarea_h = new QSpinBox(page_graphics);
        player_hitarea_h->setObjectName(QString::fromUtf8("player_hitarea_h"));
        player_hitarea_h->setValue(24);

        horizontalLayout_13->addWidget(player_hitarea_h);


        verticalLayout_6->addLayout(horizontalLayout_13);


        gridLayout_9->addLayout(verticalLayout_6, 4, 2, 1, 1);

        label_38 = new QLabel(page_graphics);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_9->addWidget(label_38, 1, 0, 1, 1);

        label_5 = new QLabel(page_graphics);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_9->addWidget(label_5, 2, 0, 1, 1);

        playerFace_comboBox = new QComboBox(page_graphics);
        playerFace_comboBox->setObjectName(QString::fromUtf8("playerFace_comboBox"));

        gridLayout_9->addWidget(playerFace_comboBox, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_9);

        scrollArea_4 = new QScrollArea(page_graphics);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(false);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 489, 199));
        player_preview_widget = new player_preview_area(scrollAreaWidgetContents_4);
        player_preview_widget->setObjectName(QString::fromUtf8("player_preview_widget"));
        player_preview_widget->setGeometry(QRect(10, 10, 471, 181));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        verticalLayout->addWidget(scrollArea_4);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        toolBox_2->addItem(page_graphics, QString::fromUtf8("Graphics"));

        gridLayout->addWidget(toolBox_2, 0, 0, 1, 1);


        retranslateUi(player_edit);

        toolBox_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(player_edit);
    } // setupUi

    void retranslateUi(QWidget *player_edit)
    {
        player_edit->setWindowTitle(QApplication::translate("player_edit", "Form", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("player_edit", "Max Shots:", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("player_edit", "Damage Modifier::", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("player_edit", "Hit Points:", 0, QApplication::UnicodeUTF8));
        canDoubleJumpCheckBox->setText(QString());
        label_4->setText(QApplication::translate("player_edit", "Can Shot Diagonal:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("player_edit", "Charged Shot:", 0, QApplication::UnicodeUTF8));
        CanAirDashCheckBox->setText(QString());
        label_14->setText(QApplication::translate("player_edit", "Player:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("player_edit", "Name:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("player_edit", "Has Shield:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("player_edit", "Can Air Dash:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("player_edit", "Can Slide:", 0, QApplication::UnicodeUTF8));
        players_tab_list_combo->clear();
        players_tab_list_combo->insertItems(0, QStringList()
         << QApplication::translate("player_edit", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("player_edit", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("player_edit", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("player_edit", "4", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("player_edit", "Can Double-Jump:", 0, QApplication::UnicodeUTF8));
        canShotDiagonal->setText(QString());
        players_tab_hasshield->setText(QString());
        can_slide_checkbox->setText(QString());
        toolBox_2->setItemText(toolBox_2->indexOf(page_properties), QApplication::translate("player_edit", "Properties", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("player_edit", "Width:", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("player_edit", "Height:", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("player_edit", "Key Colors:", 0, QApplication::UnicodeUTF8));
        color1_picker->setText(QApplication::translate("player_edit", "Color 1", 0, QApplication::UnicodeUTF8));
        ColorValueIndicator1->setText(QString());
        color2_picker->setText(QApplication::translate("player_edit", "Color 2", 0, QApplication::UnicodeUTF8));
        ColorValueIndicator2->setText(QString());
        color3_picker->setText(QApplication::translate("player_edit", "Color 3", 0, QApplication::UnicodeUTF8));
        ColorValueIndicator3->setText(QString());
        key1_picker->setText(QApplication::translate("player_edit", "Key 1", 0, QApplication::UnicodeUTF8));
        ColorKeyIndicator1->setText(QString());
        key2_picker->setText(QApplication::translate("player_edit", "Key 2", 0, QApplication::UnicodeUTF8));
        ColorKeyIndicator2->setText(QString());
        key3_picker->setText(QApplication::translate("player_edit", "Key 3", 0, QApplication::UnicodeUTF8));
        ColorKeyIndicator3->setText(QString());
        label->setText(QApplication::translate("player_edit", "Player:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("player_edit", "Weapon Colors:", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("player_edit", "Hit Area Size:", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("player_edit", "Sprite Size:", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("player_edit", "X:", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("player_edit", "Y:", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("player_edit", "W:", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("player_edit", "H:", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("player_edit", "Graphics:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("player_edit", "Face Graphic:", 0, QApplication::UnicodeUTF8));
        toolBox_2->setItemText(toolBox_2->indexOf(page_graphics), QApplication::translate("player_edit", "Graphics", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class player_edit: public Ui_player_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_EDIT_H
