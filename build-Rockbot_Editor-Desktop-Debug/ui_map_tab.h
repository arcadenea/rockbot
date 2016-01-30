/********************************************************************************
** Form generated from reading UI file 'map_tab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_TAB_H
#define UI_MAP_TAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "animtitle.h"
#include "editorarea.h"
#include "editortilepallete.h"

QT_BEGIN_NAMESPACE

class Ui_map_tab
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *Sidebar;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_6;
    QComboBox *stageListCombo;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *mapListCombo;
    QSpinBox *spinBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QToolBox *toolBox;
    QWidget *page_map_properties;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout_13;
    QSpinBox *bg1_y_pos;
    QComboBox *bg1_filename;
    QLabel *label_52;
    QLabel *label_56;
    QLabel *label_58;
    QLabel *label_60;
    QPushButton *bg_color_pick;
    QLabel *label_59;
    QCheckBox *checkBox;
    QComboBox *bg2_filename;
    QCheckBox *checkBox_2;
    QSpinBox *bg2_y_pos;
    QCheckBox *checkBox_3;
    QLabel *label_61;
    QLabel *label_62;
    QDoubleSpinBox *bg1_speed;
    QDoubleSpinBox *bg2_speed;
    QWidget *page_map;
    QVBoxLayout *verticalLayout_10;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    EditorTilePallete *pallete;
    QSpacerItem *verticalSpacer_6;
    QWidget *Terrain;
    QListWidget *listWidget_2;
    QWidget *page_npc;
    QListWidget *npc_listWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *npc_direction_combo;
    QWidget *page_Link;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QComboBox *link_orientation_combobox;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *link_bidi_checkbox;
    QSpacerItem *verticalSpacer;
    QCheckBox *link_isdoor_checkbox;
    QWidget *page_objects;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *objectListWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QComboBox *object_direction_combo;
    QWidget *animTiles;
    QVBoxLayout *verticalLayout_6;
    animTitle *animTile_Preview;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QComboBox *anim_tile_graphic_combobox;
    QComboBox *current_anim_tile_combobox;
    QLabel *label_6;
    QSpinBox *anim_tile_delay_spinbox;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    EditorArea *editArea;

    void setupUi(QWidget *map_tab)
    {
        if (map_tab->objectName().isEmpty())
            map_tab->setObjectName(QString::fromUtf8("map_tab"));
        map_tab->resize(765, 481);
        horizontalLayout_2 = new QHBoxLayout(map_tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Sidebar = new QWidget(map_tab);
        Sidebar->setObjectName(QString::fromUtf8("Sidebar"));
        Sidebar->setMinimumSize(QSize(400, 0));
        Sidebar->setMaximumSize(QSize(400, 16777215));
        verticalLayout = new QVBoxLayout(Sidebar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, 1, -1, -1);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 0, -1, 0);
        stageListCombo = new QComboBox(Sidebar);
        stageListCombo->setObjectName(QString::fromUtf8("stageListCombo"));

        gridLayout_6->addWidget(stageListCombo, 0, 1, 1, 1);

        label_9 = new QLabel(Sidebar);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 4, 1, 1);

        label_10 = new QLabel(Sidebar);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(Sidebar);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 0, 2, 1, 1);

        mapListCombo = new QComboBox(Sidebar);
        mapListCombo->setObjectName(QString::fromUtf8("mapListCombo"));

        gridLayout_6->addWidget(mapListCombo, 0, 3, 1, 1);

        spinBox = new QSpinBox(Sidebar);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(5);
        spinBox->setValue(1);

        gridLayout_6->addWidget(spinBox, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        groupBox = new QGroupBox(Sidebar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(groupBox);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setEnabled(true);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        page_map_properties = new QWidget();
        page_map_properties->setObjectName(QString::fromUtf8("page_map_properties"));
        page_map_properties->setGeometry(QRect(0, 0, 363, 245));
        verticalLayout_11 = new QVBoxLayout(page_map_properties);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        bg1_y_pos = new QSpinBox(page_map_properties);
        bg1_y_pos->setObjectName(QString::fromUtf8("bg1_y_pos"));
        bg1_y_pos->setMaximum(999);

        gridLayout_13->addWidget(bg1_y_pos, 3, 1, 1, 1);

        bg1_filename = new QComboBox(page_map_properties);
        bg1_filename->setObjectName(QString::fromUtf8("bg1_filename"));

        gridLayout_13->addWidget(bg1_filename, 1, 1, 1, 1);

        label_52 = new QLabel(page_map_properties);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_13->addWidget(label_52, 1, 0, 1, 1);

        label_56 = new QLabel(page_map_properties);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_13->addWidget(label_56, 3, 0, 1, 1);

        label_58 = new QLabel(page_map_properties);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_13->addWidget(label_58, 0, 0, 1, 1);

        label_60 = new QLabel(page_map_properties);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_13->addWidget(label_60, 7, 0, 1, 1);

        bg_color_pick = new QPushButton(page_map_properties);
        bg_color_pick->setObjectName(QString::fromUtf8("bg_color_pick"));

        gridLayout_13->addWidget(bg_color_pick, 0, 1, 1, 1);

        label_59 = new QLabel(page_map_properties);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_13->addWidget(label_59, 4, 0, 1, 1);

        checkBox = new QCheckBox(page_map_properties);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout_13->addWidget(checkBox, 8, 0, 1, 1);

        bg2_filename = new QComboBox(page_map_properties);
        bg2_filename->setObjectName(QString::fromUtf8("bg2_filename"));

        gridLayout_13->addWidget(bg2_filename, 4, 1, 1, 1);

        checkBox_2 = new QCheckBox(page_map_properties);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        gridLayout_13->addWidget(checkBox_2, 9, 0, 1, 1);

        bg2_y_pos = new QSpinBox(page_map_properties);
        bg2_y_pos->setObjectName(QString::fromUtf8("bg2_y_pos"));
        bg2_y_pos->setMaximum(999);

        gridLayout_13->addWidget(bg2_y_pos, 7, 1, 1, 1);

        checkBox_3 = new QCheckBox(page_map_properties);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        gridLayout_13->addWidget(checkBox_3, 9, 1, 1, 1);

        label_61 = new QLabel(page_map_properties);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        gridLayout_13->addWidget(label_61, 2, 0, 1, 1);

        label_62 = new QLabel(page_map_properties);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_13->addWidget(label_62, 6, 0, 1, 1);

        bg1_speed = new QDoubleSpinBox(page_map_properties);
        bg1_speed->setObjectName(QString::fromUtf8("bg1_speed"));
        bg1_speed->setMinimum(0);
        bg1_speed->setMaximum(4);
        bg1_speed->setSingleStep(0.1);

        gridLayout_13->addWidget(bg1_speed, 2, 1, 1, 1);

        bg2_speed = new QDoubleSpinBox(page_map_properties);
        bg2_speed->setObjectName(QString::fromUtf8("bg2_speed"));
        bg2_speed->setMinimum(0);
        bg2_speed->setMaximum(4);
        bg2_speed->setSingleStep(0.1);

        gridLayout_13->addWidget(bg2_speed, 6, 1, 1, 1);


        verticalLayout_11->addLayout(gridLayout_13);

        toolBox->addItem(page_map_properties, QString::fromUtf8("Map Properties"));
        page_map = new QWidget();
        page_map->setObjectName(QString::fromUtf8("page_map"));
        page_map->setGeometry(QRect(0, 0, 157, 154));
        verticalLayout_10 = new QVBoxLayout(page_map);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalWidget = new QWidget(page_map);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalWidget->setMaximumSize(QSize(16777215, 320));
        verticalLayout_3 = new QVBoxLayout(verticalWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 10, -1, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(verticalWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        scrollArea_2 = new QScrollArea(verticalWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setWidgetResizable(false);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 284, 75));
        pallete = new EditorTilePallete(scrollAreaWidgetContents_2);
        pallete->setObjectName(QString::fromUtf8("pallete"));
        pallete->setGeometry(QRect(10, 0, 241, 71));
        sizePolicy.setHeightForWidth(pallete->sizePolicy().hasHeightForWidth());
        pallete->setSizePolicy(sizePolicy);
        pallete->setMinimumSize(QSize(100, 50));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);


        verticalLayout_10->addWidget(verticalWidget);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_6);

        toolBox->addItem(page_map, QString::fromUtf8("Palette"));
        Terrain = new QWidget();
        Terrain->setObjectName(QString::fromUtf8("Terrain"));
        Terrain->setGeometry(QRect(0, 0, 98, 28));
        listWidget_2 = new QListWidget(Terrain);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar_icons/Lock"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar_icons/stairs.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar_icons/object-order-lower.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/toolbar_icons/edit-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/toolbar_icons/flag-blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem4->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/toolbar_icons/flag-green.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem5->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/toolbar_icons/arrow-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem6->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/toolbar_icons/arrow-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem7->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/toolbar_icons/arrow-down.png"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem8->setIcon(icon8);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/toolbar_icons/system-switch-user.png"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem9->setIcon(icon9);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/toolbar_icons/Save"), QSize(), QIcon::Normal, QIcon::On);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem10->setIcon(icon10);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(0, 0, 358, 361));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy2);
        toolBox->addItem(Terrain, QString::fromUtf8("Terrain"));
        page_npc = new QWidget();
        page_npc->setObjectName(QString::fromUtf8("page_npc"));
        page_npc->setGeometry(QRect(0, 0, 98, 28));
        sizePolicy.setHeightForWidth(page_npc->sizePolicy().hasHeightForWidth());
        page_npc->setSizePolicy(sizePolicy);
        npc_listWidget = new QListWidget(page_npc);
        npc_listWidget->setObjectName(QString::fromUtf8("npc_listWidget"));
        npc_listWidget->setGeometry(QRect(2, 2, 361, 151));
        sizePolicy2.setHeightForWidth(npc_listWidget->sizePolicy().hasHeightForWidth());
        npc_listWidget->setSizePolicy(sizePolicy2);
        verticalLayoutWidget = new QWidget(page_npc);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 160, 361, 31));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalWidget = new QWidget(verticalLayoutWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout_5 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        npc_direction_combo = new QComboBox(horizontalWidget);
        npc_direction_combo->setObjectName(QString::fromUtf8("npc_direction_combo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(npc_direction_combo->sizePolicy().hasHeightForWidth());
        npc_direction_combo->setSizePolicy(sizePolicy3);
        npc_direction_combo->setMinimumSize(QSize(0, 16));

        horizontalLayout_5->addWidget(npc_direction_combo);


        verticalLayout_4->addWidget(horizontalWidget);

        toolBox->addItem(page_npc, QString::fromUtf8("NPC Placing"));
        page_Link = new QWidget();
        page_Link->setObjectName(QString::fromUtf8("page_Link"));
        page_Link->setGeometry(QRect(0, 0, 380, 234));
        gridWidget = new QWidget(page_Link);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 0, 363, 311));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        link_orientation_combobox = new QComboBox(gridWidget);
        link_orientation_combobox->setObjectName(QString::fromUtf8("link_orientation_combobox"));

        gridLayout_2->addWidget(link_orientation_combobox, 0, 1, 1, 1);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(gridWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        link_bidi_checkbox = new QCheckBox(gridWidget);
        link_bidi_checkbox->setObjectName(QString::fromUtf8("link_bidi_checkbox"));
        link_bidi_checkbox->setChecked(true);

        gridLayout_2->addWidget(link_bidi_checkbox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        link_isdoor_checkbox = new QCheckBox(gridWidget);
        link_isdoor_checkbox->setObjectName(QString::fromUtf8("link_isdoor_checkbox"));

        gridLayout_2->addWidget(link_isdoor_checkbox, 2, 1, 1, 1);

        toolBox->addItem(page_Link, QString::fromUtf8("Link Placing"));
        page_objects = new QWidget();
        page_objects->setObjectName(QString::fromUtf8("page_objects"));
        page_objects->setGeometry(QRect(0, 0, 380, 234));
        verticalLayoutWidget_2 = new QWidget(page_objects);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 371, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        objectListWidget = new QListWidget(verticalLayoutWidget_2);
        objectListWidget->setObjectName(QString::fromUtf8("objectListWidget"));
        sizePolicy2.setHeightForWidth(objectListWidget->sizePolicy().hasHeightForWidth());
        objectListWidget->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(objectListWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        object_direction_combo = new QComboBox(verticalLayoutWidget_2);
        object_direction_combo->setObjectName(QString::fromUtf8("object_direction_combo"));

        horizontalLayout_4->addWidget(object_direction_combo);


        verticalLayout_2->addLayout(horizontalLayout_4);

        toolBox->addItem(page_objects, QString::fromUtf8("Object Placing"));
        animTiles = new QWidget();
        animTiles->setObjectName(QString::fromUtf8("animTiles"));
        animTiles->setGeometry(QRect(0, 0, 159, 145));
        verticalLayout_6 = new QVBoxLayout(animTiles);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        animTile_Preview = new animTitle(animTiles);
        animTile_Preview->setObjectName(QString::fromUtf8("animTile_Preview"));
        animTile_Preview->setMinimumSize(QSize(32, 32));
        animTile_Preview->setMaximumSize(QSize(32, 32));
        animTile_Preview->setBaseSize(QSize(0, 0));
        animTile_Preview->setStyleSheet(QString::fromUtf8("background-color: black;"));

        verticalLayout_6->addWidget(animTile_Preview);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, -1, 10);
        label_8 = new QLabel(animTiles);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        anim_tile_graphic_combobox = new QComboBox(animTiles);
        anim_tile_graphic_combobox->setObjectName(QString::fromUtf8("anim_tile_graphic_combobox"));
        anim_tile_graphic_combobox->setEnabled(false);

        gridLayout_3->addWidget(anim_tile_graphic_combobox, 1, 1, 1, 1);

        current_anim_tile_combobox = new QComboBox(animTiles);
        current_anim_tile_combobox->setObjectName(QString::fromUtf8("current_anim_tile_combobox"));
        current_anim_tile_combobox->setEnabled(false);

        gridLayout_3->addWidget(current_anim_tile_combobox, 0, 1, 1, 1);

        label_6 = new QLabel(animTiles);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        anim_tile_delay_spinbox = new QSpinBox(animTiles);
        anim_tile_delay_spinbox->setObjectName(QString::fromUtf8("anim_tile_delay_spinbox"));
        anim_tile_delay_spinbox->setEnabled(false);
        anim_tile_delay_spinbox->setMaximum(9999);

        gridLayout_3->addWidget(anim_tile_delay_spinbox, 2, 1, 1, 1);

        label_3 = new QLabel(animTiles);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        toolBox->addItem(animTiles, QString::fromUtf8("Animated Tiles (Disabled)"));

        verticalLayout_5->addWidget(toolBox);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_2->addWidget(Sidebar);

        scrollArea = new QScrollArea(map_tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 420, 500));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        editArea = new EditorArea(scrollAreaWidgetContents);
        editArea->setObjectName(QString::fromUtf8("editArea"));
        editArea->setGeometry(QRect(0, 0, 211, 151));
        editArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);


        retranslateUi(map_tab);

        toolBox->setCurrentIndex(0);
        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(map_tab);
    } // setupUi

    void retranslateUi(QWidget *map_tab)
    {
        map_tab->setWindowTitle(QApplication::translate("map_tab", "Form", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("map_tab", "Zoom:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("map_tab", "Stage:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("map_tab", "Map:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_52->setText(QApplication::translate("map_tab", "Background1 Image:", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("map_tab", "Background1 Y Position:", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("map_tab", "Background Color:", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("map_tab", "Background2 Y Position:", 0, QApplication::UnicodeUTF8));
        bg_color_pick->setText(QApplication::translate("map_tab", "Pick Color", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("map_tab", "Background2 Image:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("map_tab", "show background color", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("map_tab", "show bg1", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("map_tab", "show bg2", 0, QApplication::UnicodeUTF8));
        label_61->setText(QApplication::translate("map_tab", "Bg1 Speed Multiplier:", 0, QApplication::UnicodeUTF8));
        label_62->setText(QApplication::translate("map_tab", "Bg2 Speed Multiplier:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_map_properties), QApplication::translate("map_tab", "Map Properties", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("map_tab", "Level:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("map_tab", "Background", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("map_tab", "Overlay", 0, QApplication::UnicodeUTF8)
        );
        toolBox->setItemText(toolBox->indexOf(page_map), QApplication::translate("map_tab", "Palette", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("map_tab", "Solid", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("map_tab", "Stairs", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("map_tab", "Door", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_2->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("map_tab", "Spikes", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("map_tab", "Water", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_2->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("map_tab", "Ice", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_2->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("map_tab", "Move to Left", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("map_tab", "Move to Right", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_2->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("map_tab", "Sand", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_2->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("map_tab", "Scroll Lock", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_2->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("map_tab", "Checkpoint", 0, QApplication::UnicodeUTF8));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        toolBox->setItemText(toolBox->indexOf(Terrain), QApplication::translate("map_tab", "Terrain", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("map_tab", "Direction:", 0, QApplication::UnicodeUTF8));
        npc_direction_combo->clear();
        npc_direction_combo->insertItems(0, QStringList()
         << QApplication::translate("map_tab", "Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("map_tab", "Right", 0, QApplication::UnicodeUTF8)
        );
        toolBox->setItemText(toolBox->indexOf(page_npc), QApplication::translate("map_tab", "NPC Placing", 0, QApplication::UnicodeUTF8));
        link_orientation_combobox->clear();
        link_orientation_combobox->insertItems(0, QStringList()
         << QApplication::translate("map_tab", "Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("map_tab", "Vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("map_tab", "Teleporter", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("map_tab", "Type:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("map_tab", "Bi-Direcional:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("map_tab", "Is Door:", 0, QApplication::UnicodeUTF8));
        link_bidi_checkbox->setText(QString());
        link_isdoor_checkbox->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_Link), QApplication::translate("map_tab", "Link Placing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        page_objects->setToolTip(QApplication::translate("map_tab", "Object Options", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("map_tab", "Direction:", 0, QApplication::UnicodeUTF8));
        object_direction_combo->clear();
        object_direction_combo->insertItems(0, QStringList()
         << QApplication::translate("map_tab", "Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("map_tab", "Right", 0, QApplication::UnicodeUTF8)
        );
        toolBox->setItemText(toolBox->indexOf(page_objects), QApplication::translate("map_tab", "Object Placing", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("map_tab", "Graphic:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("map_tab", "Current Tile:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("map_tab", "Frame Delay:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(animTiles), QApplication::translate("map_tab", "Animated Tiles (Disabled)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class map_tab: public Ui_map_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_TAB_H
