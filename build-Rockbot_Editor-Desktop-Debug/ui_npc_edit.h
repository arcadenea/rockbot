/********************************************************************************
** Form generated from reading UI file 'npc_edit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NPC_EDIT_H
#define UI_NPC_EDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <sprite_preview_area.h>
#include "npcpreviewarea.h"

QT_BEGIN_NAMESPACE

class Ui_npc_edit
{
public:
    QGridLayout *gridLayout;
    QWidget *horizontalWidget_2;
    QGridLayout *gridLayout_4;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_10;
    QWidget *verticalWidget_3;
    QVBoxLayout *verticalLayout_11;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_7;
    npcPreviewArea *npc_edit_tab_previewarea;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QComboBox *frame_list_selector;
    QLabel *label_69;
    QSpinBox *npc_edit_tab_frameduration;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddFrame_Button;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *frameList_listWidget;
    QVBoxLayout *verticalLayout_2;
    sprite_preview_area *sprites_preview_widget;
    QGridLayout *gridLayout_2;
    QSpinBox *sprite_duration_spinBox;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *sprite_colision_x;
    QSpinBox *sprite_colision_y;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QSpinBox *sprite_colision_w;
    QSpinBox *sprite_colision_h;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *frameUp;
    QPushButton *frameDown;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout_11;
    QSpinBox *respawn_time_spinBox;
    QLabel *label_70;
    QSpinBox *npc_edit_tab_NpcHP;
    QLabel *label_65;
    QComboBox *npc_edit_tab_iatype;
    QLabel *label_66;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QSpinBox *hitarea_x_spinBox;
    QLabel *label_15;
    QSpinBox *hitarea_y_spinBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QSpinBox *hitarea_w_spinBox;
    QLabel *label_17;
    QSpinBox *hitarea_h_spinBox;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_68;
    QSpinBox *npc_edit_tab_range;
    QCheckBox *npc_edit_tab_canshoot;
    QCheckBox *isSubBoss_checkbox;
    QComboBox *npc_edit_tab_graphiccombo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QSpinBox *sprite_pos_x;
    QLabel *label_11;
    QSpinBox *sprite_pos_y;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *projectile1_comboBox;
    QComboBox *projectile2_comboBox;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_60;
    QSpinBox *npc_edit_tab_graphicwidth;
    QLabel *label_61;
    QSpinBox *npc_edit_tab_graphicheight;
    QComboBox *npc_edit_tab_shieldtype;
    QCheckBox *checkBox;
    QLabel *label_62;
    QLabel *label_64;
    QSpinBox *npc_edit_tab_movespeed;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_13;
    QComboBox *npc_edit_tab_selectnpccombo;
    QCheckBox *isBoss_checkBox;
    QLabel *label;
    QLabel *label_67;
    QLabel *label_2;
    QLabel *label_63;
    QLineEdit *npc_edit_tab_NpcName;
    QHBoxLayout *horizontalLayout;
    QComboBox *npc_edit_tab_weakness_list;
    QSpinBox *npc_edit_tab_weakness_points;

    void setupUi(QWidget *npc_edit)
    {
        if (npc_edit->objectName().isEmpty())
            npc_edit->setObjectName(QString::fromUtf8("npc_edit"));
        npc_edit->resize(906, 706);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(npc_edit->sizePolicy().hasHeightForWidth());
        npc_edit->setSizePolicy(sizePolicy);
        npc_edit->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(npc_edit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalWidget_2 = new QWidget(npc_edit);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy1);
        horizontalWidget_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_4 = new QGridLayout(horizontalWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalWidget_2 = new QWidget(horizontalWidget_2);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy2);
        verticalWidget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_10 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalWidget_3 = new QWidget(verticalWidget_2);
        verticalWidget_3->setObjectName(QString::fromUtf8("verticalWidget_3"));
        sizePolicy2.setHeightForWidth(verticalWidget_3->sizePolicy().hasHeightForWidth());
        verticalWidget_3->setSizePolicy(sizePolicy2);
        verticalWidget_3->setMaximumSize(QSize(16777215, 220));
        verticalWidget_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_11 = new QVBoxLayout(verticalWidget_3);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea_6 = new QScrollArea(verticalWidget_3);
        scrollArea_6->setObjectName(QString::fromUtf8("scrollArea_6"));
        sizePolicy1.setHeightForWidth(scrollArea_6->sizePolicy().hasHeightForWidth());
        scrollArea_6->setSizePolicy(sizePolicy1);
        scrollArea_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_6->setWidgetResizable(false);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 434, 558));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(100);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents_7->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_7->setSizePolicy(sizePolicy3);
        scrollAreaWidgetContents_7->setAutoFillBackground(true);
        npc_edit_tab_previewarea = new npcPreviewArea(scrollAreaWidgetContents_7);
        npc_edit_tab_previewarea->setObjectName(QString::fromUtf8("npc_edit_tab_previewarea"));
        npc_edit_tab_previewarea->setGeometry(QRect(0, 0, 651, 581));
        npc_edit_tab_previewarea->setStyleSheet(QString::fromUtf8(""));
        scrollArea_6->setWidget(scrollAreaWidgetContents_7);

        verticalLayout_11->addWidget(scrollArea_6);


        verticalLayout_10->addWidget(verticalWidget_3);

        frame_2 = new QFrame(verticalWidget_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 20));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, -1);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        frame_list_selector = new QComboBox(frame_2);
        frame_list_selector->setObjectName(QString::fromUtf8("frame_list_selector"));

        horizontalLayout_7->addWidget(frame_list_selector);

        label_69 = new QLabel(frame_2);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_69->sizePolicy().hasHeightForWidth());
        label_69->setSizePolicy(sizePolicy4);

        horizontalLayout_7->addWidget(label_69);

        npc_edit_tab_frameduration = new QSpinBox(frame_2);
        npc_edit_tab_frameduration->setObjectName(QString::fromUtf8("npc_edit_tab_frameduration"));
        npc_edit_tab_frameduration->setMinimum(5);
        npc_edit_tab_frameduration->setMaximum(9999);
        npc_edit_tab_frameduration->setValue(20);

        horizontalLayout_7->addWidget(npc_edit_tab_frameduration);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, 20, -1, -1);

        verticalLayout_8->addLayout(horizontalLayout_19);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AddFrame_Button = new QPushButton(frame_2);
        AddFrame_Button->setObjectName(QString::fromUtf8("AddFrame_Button"));

        horizontalLayout_5->addWidget(AddFrame_Button);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        frameList_listWidget = new QListWidget(frame_2);
        frameList_listWidget->setObjectName(QString::fromUtf8("frameList_listWidget"));
        frameList_listWidget->setAlternatingRowColors(true);
        frameList_listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        frameList_listWidget->setIconSize(QSize(64, 64));

        horizontalLayout_3->addWidget(frameList_listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 10, -1);
        sprites_preview_widget = new sprite_preview_area(frame_2);
        sprites_preview_widget->setObjectName(QString::fromUtf8("sprites_preview_widget"));
        sprites_preview_widget->setMinimumSize(QSize(256, 256));
        sprites_preview_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(sprites_preview_widget);


        horizontalLayout_3->addLayout(verticalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sprite_duration_spinBox = new QSpinBox(frame_2);
        sprite_duration_spinBox->setObjectName(QString::fromUtf8("sprite_duration_spinBox"));
        sprite_duration_spinBox->setMaximum(99999);

        gridLayout_2->addWidget(sprite_duration_spinBox, 1, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        sprite_colision_x = new QSpinBox(frame_2);
        sprite_colision_x->setObjectName(QString::fromUtf8("sprite_colision_x"));

        gridLayout_2->addWidget(sprite_colision_x, 2, 1, 1, 1);

        sprite_colision_y = new QSpinBox(frame_2);
        sprite_colision_y->setObjectName(QString::fromUtf8("sprite_colision_y"));

        gridLayout_2->addWidget(sprite_colision_y, 3, 1, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 0, 1, 1);

        sprite_colision_w = new QSpinBox(frame_2);
        sprite_colision_w->setObjectName(QString::fromUtf8("sprite_colision_w"));

        gridLayout_2->addWidget(sprite_colision_w, 4, 1, 1, 1);

        sprite_colision_h = new QSpinBox(frame_2);
        sprite_colision_h->setObjectName(QString::fromUtf8("sprite_colision_h"));

        gridLayout_2->addWidget(sprite_colision_h, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar_icons/edit-delete.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);

        verticalLayout->addWidget(pushButton);

        frameUp = new QPushButton(frame_2);
        frameUp->setObjectName(QString::fromUtf8("frameUp"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar_icons/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        frameUp->setIcon(icon1);

        verticalLayout->addWidget(frameUp);

        frameDown = new QPushButton(frame_2);
        frameDown->setObjectName(QString::fromUtf8("frameDown"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar_icons/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        frameDown->setIcon(icon2);

        verticalLayout->addWidget(frameDown);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout_10->addWidget(frame_2);


        gridLayout_4->addWidget(verticalWidget_2, 0, 2, 1, 1);

        widget = new QWidget(horizontalWidget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        widget->setMinimumSize(QSize(300, 0));
        widget->setMaximumSize(QSize(300, 16777215));
        widget->setBaseSize(QSize(300, 0));
        gridLayout_11 = new QGridLayout(widget);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_11->setContentsMargins(-1, -1, -1, 20);
        respawn_time_spinBox = new QSpinBox(widget);
        respawn_time_spinBox->setObjectName(QString::fromUtf8("respawn_time_spinBox"));
        respawn_time_spinBox->setMaximum(99999);

        gridLayout_11->addWidget(respawn_time_spinBox, 22, 2, 1, 1);

        label_70 = new QLabel(widget);
        label_70->setObjectName(QString::fromUtf8("label_70"));

        gridLayout_11->addWidget(label_70, 0, 0, 1, 1);

        npc_edit_tab_NpcHP = new QSpinBox(widget);
        npc_edit_tab_NpcHP->setObjectName(QString::fromUtf8("npc_edit_tab_NpcHP"));
        npc_edit_tab_NpcHP->setValue(5);

        gridLayout_11->addWidget(npc_edit_tab_NpcHP, 3, 2, 1, 1);

        label_65 = new QLabel(widget);
        label_65->setObjectName(QString::fromUtf8("label_65"));

        gridLayout_11->addWidget(label_65, 17, 0, 1, 1);

        npc_edit_tab_iatype = new QComboBox(widget);
        npc_edit_tab_iatype->setObjectName(QString::fromUtf8("npc_edit_tab_iatype"));
        npc_edit_tab_iatype->setEnabled(true);

        gridLayout_11->addWidget(npc_edit_tab_iatype, 17, 2, 1, 1);

        label_66 = new QLabel(widget);
        label_66->setObjectName(QString::fromUtf8("label_66"));

        gridLayout_11->addWidget(label_66, 16, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        hitarea_x_spinBox = new QSpinBox(widget);
        hitarea_x_spinBox->setObjectName(QString::fromUtf8("hitarea_x_spinBox"));
        hitarea_x_spinBox->setMaximum(999);

        horizontalLayout_4->addWidget(hitarea_x_spinBox);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_4->addWidget(label_15);

        hitarea_y_spinBox = new QSpinBox(widget);
        hitarea_y_spinBox->setObjectName(QString::fromUtf8("hitarea_y_spinBox"));
        hitarea_y_spinBox->setMaximum(999);

        horizontalLayout_4->addWidget(hitarea_y_spinBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_8->addWidget(label_16);

        hitarea_w_spinBox = new QSpinBox(widget);
        hitarea_w_spinBox->setObjectName(QString::fromUtf8("hitarea_w_spinBox"));
        hitarea_w_spinBox->setMaximum(999);

        horizontalLayout_8->addWidget(hitarea_w_spinBox);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_8->addWidget(label_17);

        hitarea_h_spinBox = new QSpinBox(widget);
        hitarea_h_spinBox->setObjectName(QString::fromUtf8("hitarea_h_spinBox"));
        hitarea_h_spinBox->setMaximum(999);

        horizontalLayout_8->addWidget(hitarea_h_spinBox);


        verticalLayout_3->addLayout(horizontalLayout_8);


        gridLayout_11->addLayout(verticalLayout_3, 9, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_11->addWidget(label_3, 8, 0, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_11->addWidget(label_12, 22, 0, 1, 1);

        label_68 = new QLabel(widget);
        label_68->setObjectName(QString::fromUtf8("label_68"));

        gridLayout_11->addWidget(label_68, 20, 0, 1, 1);

        npc_edit_tab_range = new QSpinBox(widget);
        npc_edit_tab_range->setObjectName(QString::fromUtf8("npc_edit_tab_range"));
        npc_edit_tab_range->setMinimum(0);
        npc_edit_tab_range->setMaximum(999);
        npc_edit_tab_range->setValue(160);

        gridLayout_11->addWidget(npc_edit_tab_range, 20, 2, 1, 1);

        npc_edit_tab_canshoot = new QCheckBox(widget);
        npc_edit_tab_canshoot->setObjectName(QString::fromUtf8("npc_edit_tab_canshoot"));

        gridLayout_11->addWidget(npc_edit_tab_canshoot, 11, 0, 1, 1);

        isSubBoss_checkbox = new QCheckBox(widget);
        isSubBoss_checkbox->setObjectName(QString::fromUtf8("isSubBoss_checkbox"));

        gridLayout_11->addWidget(isSubBoss_checkbox, 12, 2, 1, 1);

        npc_edit_tab_graphiccombo = new QComboBox(widget);
        npc_edit_tab_graphiccombo->setObjectName(QString::fromUtf8("npc_edit_tab_graphiccombo"));

        gridLayout_11->addWidget(npc_edit_tab_graphiccombo, 4, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        sprite_pos_x = new QSpinBox(widget);
        sprite_pos_x->setObjectName(QString::fromUtf8("sprite_pos_x"));
        sprite_pos_x->setEnabled(true);
        sprite_pos_x->setMinimum(-99);

        horizontalLayout_2->addWidget(sprite_pos_x);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        sprite_pos_y = new QSpinBox(widget);
        sprite_pos_y->setObjectName(QString::fromUtf8("sprite_pos_y"));
        sprite_pos_y->setEnabled(true);
        sprite_pos_y->setMinimum(-99);

        horizontalLayout_2->addWidget(sprite_pos_y);


        gridLayout_11->addLayout(horizontalLayout_2, 8, 2, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, -1, 0, 0);
        projectile1_comboBox = new QComboBox(widget);
        projectile1_comboBox->setObjectName(QString::fromUtf8("projectile1_comboBox"));

        horizontalLayout_11->addWidget(projectile1_comboBox);

        projectile2_comboBox = new QComboBox(widget);
        projectile2_comboBox->setObjectName(QString::fromUtf8("projectile2_comboBox"));

        horizontalLayout_11->addWidget(projectile2_comboBox);


        gridLayout_11->addLayout(horizontalLayout_11, 13, 2, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        label_60 = new QLabel(widget);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        horizontalLayout_6->addWidget(label_60);

        npc_edit_tab_graphicwidth = new QSpinBox(widget);
        npc_edit_tab_graphicwidth->setObjectName(QString::fromUtf8("npc_edit_tab_graphicwidth"));
        npc_edit_tab_graphicwidth->setMinimum(8);
        npc_edit_tab_graphicwidth->setMaximum(127);
        npc_edit_tab_graphicwidth->setValue(16);

        horizontalLayout_6->addWidget(npc_edit_tab_graphicwidth);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        label_61 = new QLabel(widget);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_9->addWidget(label_61);

        npc_edit_tab_graphicheight = new QSpinBox(widget);
        npc_edit_tab_graphicheight->setObjectName(QString::fromUtf8("npc_edit_tab_graphicheight"));
        npc_edit_tab_graphicheight->setMinimum(8);
        npc_edit_tab_graphicheight->setMaximum(127);
        npc_edit_tab_graphicheight->setValue(16);

        horizontalLayout_9->addWidget(npc_edit_tab_graphicheight);


        gridLayout_11->addLayout(horizontalLayout_9, 5, 2, 1, 1);

        npc_edit_tab_shieldtype = new QComboBox(widget);
        npc_edit_tab_shieldtype->setObjectName(QString::fromUtf8("npc_edit_tab_shieldtype"));

        gridLayout_11->addWidget(npc_edit_tab_shieldtype, 16, 2, 1, 1);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_11->addWidget(checkBox, 12, 0, 1, 1);

        label_62 = new QLabel(widget);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_11->addWidget(label_62, 1, 0, 1, 1);

        label_64 = new QLabel(widget);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        gridLayout_11->addWidget(label_64, 3, 0, 1, 1);

        npc_edit_tab_movespeed = new QSpinBox(widget);
        npc_edit_tab_movespeed->setObjectName(QString::fromUtf8("npc_edit_tab_movespeed"));
        npc_edit_tab_movespeed->setMinimum(0);
        npc_edit_tab_movespeed->setMaximum(20);
        npc_edit_tab_movespeed->setValue(2);

        gridLayout_11->addWidget(npc_edit_tab_movespeed, 19, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_9, 23, 0, 1, 1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_11->addWidget(label_13, 9, 0, 1, 1);

        npc_edit_tab_selectnpccombo = new QComboBox(widget);
        npc_edit_tab_selectnpccombo->setObjectName(QString::fromUtf8("npc_edit_tab_selectnpccombo"));

        gridLayout_11->addWidget(npc_edit_tab_selectnpccombo, 0, 2, 1, 1);

        isBoss_checkBox = new QCheckBox(widget);
        isBoss_checkBox->setObjectName(QString::fromUtf8("isBoss_checkBox"));

        gridLayout_11->addWidget(isBoss_checkBox, 11, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_11->addWidget(label, 21, 0, 1, 1);

        label_67 = new QLabel(widget);
        label_67->setObjectName(QString::fromUtf8("label_67"));

        gridLayout_11->addWidget(label_67, 19, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_11->addWidget(label_2, 13, 0, 1, 1);

        label_63 = new QLabel(widget);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_11->addWidget(label_63, 4, 0, 1, 1);

        npc_edit_tab_NpcName = new QLineEdit(widget);
        npc_edit_tab_NpcName->setObjectName(QString::fromUtf8("npc_edit_tab_NpcName"));
        npc_edit_tab_NpcName->setMaxLength(30);

        gridLayout_11->addWidget(npc_edit_tab_NpcName, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        npc_edit_tab_weakness_list = new QComboBox(widget);
        npc_edit_tab_weakness_list->setObjectName(QString::fromUtf8("npc_edit_tab_weakness_list"));

        horizontalLayout->addWidget(npc_edit_tab_weakness_list);

        npc_edit_tab_weakness_points = new QSpinBox(widget);
        npc_edit_tab_weakness_points->setObjectName(QString::fromUtf8("npc_edit_tab_weakness_points"));

        horizontalLayout->addWidget(npc_edit_tab_weakness_points);


        gridLayout_11->addLayout(horizontalLayout, 21, 2, 1, 1);


        gridLayout_4->addWidget(widget, 0, 1, 1, 1);


        gridLayout->addWidget(horizontalWidget_2, 0, 0, 1, 1);


        retranslateUi(npc_edit);

        QMetaObject::connectSlotsByName(npc_edit);
    } // setupUi

    void retranslateUi(QWidget *npc_edit)
    {
        npc_edit->setWindowTitle(QApplication::translate("npc_edit", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("npc_edit", "Frame Type:", 0, QApplication::UnicodeUTF8));
        frame_list_selector->clear();
        frame_list_selector->insertItems(0, QStringList()
         << QApplication::translate("npc_edit", "STAND", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "WALK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "JUMP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "TELEPORT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "JUMP_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "WALK_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "HIT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "STAIRS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "STAIRS_SEMI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "STAIRS_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "STAIRS_MOVE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "TROW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "TURN (HORIZONTAL)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "MOVE_SEMI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "WALK_AIR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "INTRO", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "SPECIAL_ATTACK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "SLIDE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "SHIELD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "TURN (VERTICAL)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK THROW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK DIAGONAL UP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK DIAGONAL DOWN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK UP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK DOWN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "ATTACK SPECIAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "LOOK UP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "GRAB WALL", 0, QApplication::UnicodeUTF8)
        );
        label_69->setText(QApplication::translate("npc_edit", "Duration:", 0, QApplication::UnicodeUTF8));
        AddFrame_Button->setText(QApplication::translate("npc_edit", "Add Frame", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("npc_edit", "Delay:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("npc_edit", "X:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("npc_edit", "Y:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("npc_edit", "W:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("npc_edit", "H:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        frameUp->setText(QString());
        frameDown->setText(QString());
#ifndef QT_NO_TOOLTIP
        respawn_time_spinBox->setToolTip(QApplication::translate("npc_edit", "If different than zero, NPC will respawn even if is on-screen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_70->setText(QApplication::translate("npc_edit", "Npc:", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("npc_edit", "*IA Type:", 0, QApplication::UnicodeUTF8));
        label_66->setText(QApplication::translate("npc_edit", "Shield Type:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("npc_edit", "x:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("npc_edit", "y:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("npc_edit", "w:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("npc_edit", "h:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("npc_edit", "Sprites Position ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("npc_edit", "Auto-Respawn Delay:", 0, QApplication::UnicodeUTF8));
        label_68->setText(QApplication::translate("npc_edit", "Range:", 0, QApplication::UnicodeUTF8));
        npc_edit_tab_canshoot->setText(QApplication::translate("npc_edit", "Is Ghost", 0, QApplication::UnicodeUTF8));
        isSubBoss_checkbox->setText(QApplication::translate("npc_edit", "Is Sub-Boss", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("npc_edit", "X: ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("npc_edit", "Y: ", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("npc_edit", "Width: ", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("npc_edit", "Height:", 0, QApplication::UnicodeUTF8));
        npc_edit_tab_shieldtype->clear();
        npc_edit_tab_shieldtype->insertItems(0, QStringList()
         << QApplication::translate("npc_edit", "no shield", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "full shield", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "front shield", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("npc_edit", "stand_shield", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        checkBox->setText(QApplication::translate("npc_edit", "Can Fly", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("npc_edit", "Name:", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("npc_edit", "Hit Points:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("npc_edit", "Hit Area:", 0, QApplication::UnicodeUTF8));
        isBoss_checkBox->setText(QApplication::translate("npc_edit", "Is Boss", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("npc_edit", "Weaknesses:", 0, QApplication::UnicodeUTF8));
        label_67->setText(QApplication::translate("npc_edit", "Speed:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("npc_edit", "Attacks:", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("npc_edit", "Graphic:", 0, QApplication::UnicodeUTF8));
        npc_edit_tab_NpcName->setText(QApplication::translate("npc_edit", "My NPC", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class npc_edit: public Ui_npc_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NPC_EDIT_H
