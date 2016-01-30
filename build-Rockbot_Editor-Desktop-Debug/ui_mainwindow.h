/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionQuit;
    QAction *actionSave;
    QAction *actionNormal_Edit;
    QAction *actionLock_Edit;
    QAction *actionEraser;
    QAction *actionAdd;
    QAction *actionFill;
    QAction *actionLink;
    QAction *actionStairs;
    QAction *actionEdit_NPC;
    QAction *actionEdit_Tileset;
    QAction *actionLayer_Level;
    QAction *actionOne;
    QAction *actionTwo;
    QAction *actionThree;
    QAction *actionAdd_Object;
    QAction *actionSet_Boss;
    QAction *actionReset_Map;
    QAction *actionSwap_Maps;
    QAction *actionAction_subboss;
    QAction *actionScenes_Editor;
    QAction *actionObjects;
    QAction *actionNPCs;
    QAction *actionTeleporters;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *game_tab;
    QGridLayout *gridLayout_16;
    QScrollArea *gamePropertiesScrollarea;
    QWidget *GamePropertiesScrollareaContents;
    QWidget *stage_tab;
    QGridLayout *gridLayout_5;
    QScrollArea *StagesScrollarea;
    QWidget *scrollAreaWidgetContents;
    QWidget *maps_tab;
    QGridLayout *gridLayout_17;
    QScrollArea *MapScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *weapon_edit_tab;
    QHBoxLayout *horizontalLayout_8;
    QScrollArea *WeaponScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *tab_projectiles;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *ProjectileScrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *npc_tab;
    QGridLayout *gridLayout_11;
    QScrollArea *NPCScrollArea;
    QWidget *scrollAreaWidgetContents_5;
    QWidget *ai_tab;
    QGridLayout *gridLayout_12;
    QScrollArea *AIScrollArea;
    QWidget *scrollAreaWidgetContents_6;
    QWidget *object_tab;
    QGridLayout *gridLayout_14;
    QScrollArea *ObjectScrollArea;
    QWidget *scrollAreaWidgetContents_7;
    QWidget *colorcycle_tab;
    QGridLayout *gridLayout_15;
    QScrollArea *ColorcycleScrollArea;
    QWidget *scrollAreaWidgetContents_8;
    QWidget *player_tab;
    QGridLayout *gridLayout_18;
    QScrollArea *PlayerScrollArea;
    QWidget *scrollAreaWidgetContents_9;
    QWidget *armor_tab;
    QGridLayout *gridLayout_2;
    QScrollArea *armorScrollArea;
    QWidget *scrollAreaWidgetContents_10;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *editToolBar;
    QMenuBar *menuBar;
    QMenu *menuFILE;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuLevel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(870, 443);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar_icons/New"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar_icons/Open"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/toolbar_icons/Save"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon1);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar_icons/Save"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionNormal_Edit = new QAction(MainWindow);
        actionNormal_Edit->setObjectName(QString::fromUtf8("actionNormal_Edit"));
        actionNormal_Edit->setCheckable(true);
        actionNormal_Edit->setChecked(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/toolbar_icons/draw-freehand.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/toolbar_icons/draw-freehand.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNormal_Edit->setIcon(icon3);
        actionLock_Edit = new QAction(MainWindow);
        actionLock_Edit->setObjectName(QString::fromUtf8("actionLock_Edit"));
        actionLock_Edit->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/toolbar_icons/Lock"), QSize(), QIcon::Normal, QIcon::On);
        actionLock_Edit->setIcon(icon4);
        actionEraser = new QAction(MainWindow);
        actionEraser->setObjectName(QString::fromUtf8("actionEraser"));
        actionEraser->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/toolbar_icons/draw-eraser.png"), QSize(), QIcon::Normal, QIcon::On);
        actionEraser->setIcon(icon5);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/toolbar_icons/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon6);
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName(QString::fromUtf8("actionFill"));
        actionFill->setCheckable(true);
        actionFill->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/toolbar_icons/Fill"), QSize(), QIcon::Normal, QIcon::Off);
        actionFill->setIcon(icon7);
        actionLink = new QAction(MainWindow);
        actionLink->setObjectName(QString::fromUtf8("actionLink"));
        actionLink->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/toolbar_icons/connect_no.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLink->setIcon(icon8);
        actionStairs = new QAction(MainWindow);
        actionStairs->setObjectName(QString::fromUtf8("actionStairs"));
        actionStairs->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/toolbar_icons/stairs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStairs->setIcon(icon9);
        actionEdit_NPC = new QAction(MainWindow);
        actionEdit_NPC->setObjectName(QString::fromUtf8("actionEdit_NPC"));
        actionEdit_NPC->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/toolbar_icons/Manager-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_NPC->setIcon(icon10);
        actionEdit_Tileset = new QAction(MainWindow);
        actionEdit_Tileset->setObjectName(QString::fromUtf8("actionEdit_Tileset"));
        actionEdit_Tileset->setCheckable(true);
        actionEdit_Tileset->setChecked(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/toolbar_icons/format-stroke-color.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_Tileset->setIcon(icon11);
        actionLayer_Level = new QAction(MainWindow);
        actionLayer_Level->setObjectName(QString::fromUtf8("actionLayer_Level"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/toolbar_icons/format-list-ordered.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLayer_Level->setIcon(icon12);
        actionOne = new QAction(MainWindow);
        actionOne->setObjectName(QString::fromUtf8("actionOne"));
        actionTwo = new QAction(MainWindow);
        actionTwo->setObjectName(QString::fromUtf8("actionTwo"));
        actionThree = new QAction(MainWindow);
        actionThree->setObjectName(QString::fromUtf8("actionThree"));
        actionAdd_Object = new QAction(MainWindow);
        actionAdd_Object->setObjectName(QString::fromUtf8("actionAdd_Object"));
        actionAdd_Object->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/toolbar_icons/media-playlist-shuffle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Object->setIcon(icon13);
        actionSet_Boss = new QAction(MainWindow);
        actionSet_Boss->setObjectName(QString::fromUtf8("actionSet_Boss"));
        actionSet_Boss->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/toolbar_icons/4a6b77ae99a98d0d3a0a68a6b5491305.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSet_Boss->setIcon(icon14);
        actionReset_Map = new QAction(MainWindow);
        actionReset_Map->setObjectName(QString::fromUtf8("actionReset_Map"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/toolbar_icons/archive-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset_Map->setIcon(icon15);
        actionSwap_Maps = new QAction(MainWindow);
        actionSwap_Maps->setObjectName(QString::fromUtf8("actionSwap_Maps"));
        actionAction_subboss = new QAction(MainWindow);
        actionAction_subboss->setObjectName(QString::fromUtf8("actionAction_subboss"));
        actionAction_subboss->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/toolbar_icons/Knight-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAction_subboss->setIcon(icon16);
        actionScenes_Editor = new QAction(MainWindow);
        actionScenes_Editor->setObjectName(QString::fromUtf8("actionScenes_Editor"));
        actionObjects = new QAction(MainWindow);
        actionObjects->setObjectName(QString::fromUtf8("actionObjects"));
        actionObjects->setCheckable(true);
        actionObjects->setChecked(true);
        actionNPCs = new QAction(MainWindow);
        actionNPCs->setObjectName(QString::fromUtf8("actionNPCs"));
        actionNPCs->setCheckable(true);
        actionNPCs->setChecked(true);
        actionTeleporters = new QAction(MainWindow);
        actionTeleporters->setObjectName(QString::fromUtf8("actionTeleporters"));
        actionTeleporters->setCheckable(true);
        actionTeleporters->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        game_tab = new QWidget();
        game_tab->setObjectName(QString::fromUtf8("game_tab"));
        gridLayout_16 = new QGridLayout(game_tab);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gamePropertiesScrollarea = new QScrollArea(game_tab);
        gamePropertiesScrollarea->setObjectName(QString::fromUtf8("gamePropertiesScrollarea"));
        gamePropertiesScrollarea->setWidgetResizable(true);
        GamePropertiesScrollareaContents = new QWidget();
        GamePropertiesScrollareaContents->setObjectName(QString::fromUtf8("GamePropertiesScrollareaContents"));
        GamePropertiesScrollareaContents->setGeometry(QRect(0, 0, 98, 28));
        gamePropertiesScrollarea->setWidget(GamePropertiesScrollareaContents);

        gridLayout_16->addWidget(gamePropertiesScrollarea, 0, 0, 1, 1);

        tabWidget->addTab(game_tab, QString());
        stage_tab = new QWidget();
        stage_tab->setObjectName(QString::fromUtf8("stage_tab"));
        gridLayout_5 = new QGridLayout(stage_tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        StagesScrollarea = new QScrollArea(stage_tab);
        StagesScrollarea->setObjectName(QString::fromUtf8("StagesScrollarea"));
        StagesScrollarea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        StagesScrollarea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(StagesScrollarea, 0, 0, 1, 1);

        tabWidget->addTab(stage_tab, QString());
        maps_tab = new QWidget();
        maps_tab->setObjectName(QString::fromUtf8("maps_tab"));
        gridLayout_17 = new QGridLayout(maps_tab);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        MapScrollArea = new QScrollArea(maps_tab);
        MapScrollArea->setObjectName(QString::fromUtf8("MapScrollArea"));
        MapScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 828, 295));
        MapScrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_17->addWidget(MapScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(maps_tab, QString());
        weapon_edit_tab = new QWidget();
        weapon_edit_tab->setObjectName(QString::fromUtf8("weapon_edit_tab"));
        horizontalLayout_8 = new QHBoxLayout(weapon_edit_tab);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        WeaponScrollArea = new QScrollArea(weapon_edit_tab);
        WeaponScrollArea->setObjectName(QString::fromUtf8("WeaponScrollArea"));
        WeaponScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 98, 28));
        WeaponScrollArea->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_8->addWidget(WeaponScrollArea);

        tabWidget->addTab(weapon_edit_tab, QString());
        tab_projectiles = new QWidget();
        tab_projectiles->setObjectName(QString::fromUtf8("tab_projectiles"));
        verticalLayout_2 = new QVBoxLayout(tab_projectiles);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ProjectileScrollArea = new QScrollArea(tab_projectiles);
        ProjectileScrollArea->setObjectName(QString::fromUtf8("ProjectileScrollArea"));
        ProjectileScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 98, 28));
        ProjectileScrollArea->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_2->addWidget(ProjectileScrollArea);

        tabWidget->addTab(tab_projectiles, QString());
        npc_tab = new QWidget();
        npc_tab->setObjectName(QString::fromUtf8("npc_tab"));
        gridLayout_11 = new QGridLayout(npc_tab);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        NPCScrollArea = new QScrollArea(npc_tab);
        NPCScrollArea->setObjectName(QString::fromUtf8("NPCScrollArea"));
        NPCScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 98, 28));
        NPCScrollArea->setWidget(scrollAreaWidgetContents_5);

        gridLayout_11->addWidget(NPCScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(npc_tab, QString());
        ai_tab = new QWidget();
        ai_tab->setObjectName(QString::fromUtf8("ai_tab"));
        gridLayout_12 = new QGridLayout(ai_tab);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        AIScrollArea = new QScrollArea(ai_tab);
        AIScrollArea->setObjectName(QString::fromUtf8("AIScrollArea"));
        AIScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 98, 28));
        AIScrollArea->setWidget(scrollAreaWidgetContents_6);

        gridLayout_12->addWidget(AIScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(ai_tab, QString());
        object_tab = new QWidget();
        object_tab->setObjectName(QString::fromUtf8("object_tab"));
        gridLayout_14 = new QGridLayout(object_tab);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        ObjectScrollArea = new QScrollArea(object_tab);
        ObjectScrollArea->setObjectName(QString::fromUtf8("ObjectScrollArea"));
        ObjectScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 98, 28));
        ObjectScrollArea->setWidget(scrollAreaWidgetContents_7);

        gridLayout_14->addWidget(ObjectScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(object_tab, QString());
        colorcycle_tab = new QWidget();
        colorcycle_tab->setObjectName(QString::fromUtf8("colorcycle_tab"));
        gridLayout_15 = new QGridLayout(colorcycle_tab);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        ColorcycleScrollArea = new QScrollArea(colorcycle_tab);
        ColorcycleScrollArea->setObjectName(QString::fromUtf8("ColorcycleScrollArea"));
        ColorcycleScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 98, 28));
        ColorcycleScrollArea->setWidget(scrollAreaWidgetContents_8);

        gridLayout_15->addWidget(ColorcycleScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(colorcycle_tab, QString());
        player_tab = new QWidget();
        player_tab->setObjectName(QString::fromUtf8("player_tab"));
        gridLayout_18 = new QGridLayout(player_tab);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        PlayerScrollArea = new QScrollArea(player_tab);
        PlayerScrollArea->setObjectName(QString::fromUtf8("PlayerScrollArea"));
        PlayerScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 98, 28));
        PlayerScrollArea->setWidget(scrollAreaWidgetContents_9);

        gridLayout_18->addWidget(PlayerScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(player_tab, QString());
        armor_tab = new QWidget();
        armor_tab->setObjectName(QString::fromUtf8("armor_tab"));
        gridLayout_2 = new QGridLayout(armor_tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        armorScrollArea = new QScrollArea(armor_tab);
        armorScrollArea->setObjectName(QString::fromUtf8("armorScrollArea"));
        armorScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_10 = new QWidget();
        scrollAreaWidgetContents_10->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_10"));
        scrollAreaWidgetContents_10->setGeometry(QRect(0, 0, 98, 28));
        armorScrollArea->setWidget(scrollAreaWidgetContents_10);

        gridLayout_2->addWidget(armorScrollArea, 0, 0, 1, 1);

        tabWidget->addTab(armor_tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        editToolBar = new QToolBar(MainWindow);
        editToolBar->setObjectName(QString::fromUtf8("editToolBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editToolBar->sizePolicy().hasHeightForWidth());
        editToolBar->setSizePolicy(sizePolicy2);
        MainWindow->addToolBar(Qt::TopToolBarArea, editToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 20));
        menuFILE = new QMenu(menuBar);
        menuFILE->setObjectName(QString::fromUtf8("menuFILE"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuLevel = new QMenu(menuView);
        menuLevel->setObjectName(QString::fromUtf8("menuLevel"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEdit_Tileset);
        mainToolBar->addAction(actionEdit_NPC);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAction_subboss);
        mainToolBar->addAction(actionSet_Boss);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd_Object);
        editToolBar->addAction(actionNormal_Edit);
        editToolBar->addAction(actionLock_Edit);
        editToolBar->addAction(actionEraser);
        editToolBar->addAction(actionFill);
        editToolBar->addSeparator();
        editToolBar->addAction(actionLink);
        menuBar->addAction(menuFILE->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFILE->addAction(actionNew);
        menuFILE->addAction(actionOpen);
        menuFILE->addAction(actionSave);
        menuFILE->addAction(actionSwap_Maps);
        menuFILE->addAction(actionReset_Map);
        menuFILE->addSeparator();
        menuFILE->addAction(actionScenes_Editor);
        menuFILE->addSeparator();
        menuFILE->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuView->addAction(menuLevel->menuAction());
        menuView->addAction(actionObjects);
        menuView->addAction(actionNPCs);
        menuView->addAction(actionTeleporters);
        menuLevel->addAction(actionOne);
        menuLevel->addAction(actionTwo);
        menuLevel->addAction(actionThree);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionNormal_Edit->setText(QApplication::translate("MainWindow", "Normal Edit", 0, QApplication::UnicodeUTF8));
        actionLock_Edit->setText(QApplication::translate("MainWindow", "Lock Edit", 0, QApplication::UnicodeUTF8));
        actionEraser->setText(QApplication::translate("MainWindow", "Eraser", 0, QApplication::UnicodeUTF8));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        actionFill->setText(QApplication::translate("MainWindow", "Fill", 0, QApplication::UnicodeUTF8));
        actionLink->setText(QApplication::translate("MainWindow", "Link", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLink->setToolTip(QApplication::translate("MainWindow", "Link Maps", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStairs->setText(QApplication::translate("MainWindow", "Stairs", 0, QApplication::UnicodeUTF8));
        actionEdit_NPC->setText(QApplication::translate("MainWindow", "Edit NPC", 0, QApplication::UnicodeUTF8));
        actionEdit_Tileset->setText(QApplication::translate("MainWindow", "Edit Tileset", 0, QApplication::UnicodeUTF8));
        actionLayer_Level->setText(QApplication::translate("MainWindow", "Layer Level", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLayer_Level->setToolTip(QApplication::translate("MainWindow", "Layer Level", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOne->setText(QApplication::translate("MainWindow", "one", 0, QApplication::UnicodeUTF8));
        actionTwo->setText(QApplication::translate("MainWindow", "two", 0, QApplication::UnicodeUTF8));
        actionThree->setText(QApplication::translate("MainWindow", "three", 0, QApplication::UnicodeUTF8));
        actionAdd_Object->setText(QApplication::translate("MainWindow", "Add Object", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_Object->setToolTip(QApplication::translate("MainWindow", "Add Object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSet_Boss->setText(QApplication::translate("MainWindow", "Set Boss", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSet_Boss->setToolTip(QApplication::translate("MainWindow", "Set Stage Boss", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionReset_Map->setText(QApplication::translate("MainWindow", "Reset Map", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionReset_Map->setToolTip(QApplication::translate("MainWindow", "Clear all map tiles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSwap_Maps->setText(QApplication::translate("MainWindow", "Swap Stages", 0, QApplication::UnicodeUTF8));
        actionAction_subboss->setText(QApplication::translate("MainWindow", "action_subboss", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAction_subboss->setToolTip(QApplication::translate("MainWindow", "Set sub-boss", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionScenes_Editor->setText(QApplication::translate("MainWindow", "Scenes Editor", 0, QApplication::UnicodeUTF8));
        actionObjects->setText(QApplication::translate("MainWindow", "Objects", 0, QApplication::UnicodeUTF8));
        actionNPCs->setText(QApplication::translate("MainWindow", "Enemies", 0, QApplication::UnicodeUTF8));
        actionTeleporters->setText(QApplication::translate("MainWindow", "Teleporters", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(game_tab), QApplication::translate("MainWindow", "Game Properties", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(stage_tab), QApplication::translate("MainWindow", "Stages", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(maps_tab), QApplication::translate("MainWindow", "Maps", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(weapon_edit_tab), QApplication::translate("MainWindow", "Weapons", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_projectiles), QApplication::translate("MainWindow", "Projectiles", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(npc_tab), QApplication::translate("MainWindow", "NPCs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ai_tab), QApplication::translate("MainWindow", "Artificial Inteligence", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(object_tab), QApplication::translate("MainWindow", "Objects", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(colorcycle_tab), QApplication::translate("MainWindow", "Colorcycle", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(player_tab), QApplication::translate("MainWindow", "Player Edit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(armor_tab), QApplication::translate("MainWindow", "Armor Pieces", 0, QApplication::UnicodeUTF8));
        editToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        menuFILE->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuLevel->setTitle(QApplication::translate("MainWindow", "Level", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
