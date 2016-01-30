/********************************************************************************
** Form generated from reading UI file 'sceneeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEEDITORWINDOW_H
#define UI_SCENEEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneEditorWindow
{
public:
    QAction *actionSave;
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabs;
    QWidget *tab_sequence;
    QGridLayout *gridLayout_2;
    QScrollArea *sequenceScrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_cleararea;
    QWidget *tab_text;
    QGridLayout *gridLayout_3;
    QScrollArea *tabTextScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *tab_image;
    QGridLayout *gridLayout_4;
    QScrollArea *tabImage_scrollArea;
    QWidget *tabImage_scrollArea_contents;
    QWidget *tab_animation;
    QGridLayout *gridLayout_5;
    QScrollArea *tabAnimation_scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *tab_sfx;
    QWidget *tab_music;
    QGridLayout *gridLayout_6;
    QWidget *widget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SceneEditorWindow)
    {
        if (SceneEditorWindow->objectName().isEmpty())
            SceneEditorWindow->setObjectName(QString::fromUtf8("SceneEditorWindow"));
        SceneEditorWindow->resize(1051, 569);
        actionSave = new QAction(SceneEditorWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(SceneEditorWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(SceneEditorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        tab_sequence = new QWidget();
        tab_sequence->setObjectName(QString::fromUtf8("tab_sequence"));
        gridLayout_2 = new QGridLayout(tab_sequence);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sequenceScrollArea = new QScrollArea(tab_sequence);
        sequenceScrollArea->setObjectName(QString::fromUtf8("sequenceScrollArea"));
        sequenceScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 670, 464));
        sequenceScrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(sequenceScrollArea, 0, 0, 1, 1);

        tabs->addTab(tab_sequence, QString());
        tab_cleararea = new QWidget();
        tab_cleararea->setObjectName(QString::fromUtf8("tab_cleararea"));
        tabs->addTab(tab_cleararea, QString());
        tab_text = new QWidget();
        tab_text->setObjectName(QString::fromUtf8("tab_text"));
        gridLayout_3 = new QGridLayout(tab_text);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabTextScrollArea = new QScrollArea(tab_text);
        tabTextScrollArea->setObjectName(QString::fromUtf8("tabTextScrollArea"));
        tabTextScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 419, 495));
        tabTextScrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(tabTextScrollArea, 0, 0, 1, 1);

        tabs->addTab(tab_text, QString());
        tab_image = new QWidget();
        tab_image->setObjectName(QString::fromUtf8("tab_image"));
        gridLayout_4 = new QGridLayout(tab_image);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabImage_scrollArea = new QScrollArea(tab_image);
        tabImage_scrollArea->setObjectName(QString::fromUtf8("tabImage_scrollArea"));
        tabImage_scrollArea->setWidgetResizable(true);
        tabImage_scrollArea_contents = new QWidget();
        tabImage_scrollArea_contents->setObjectName(QString::fromUtf8("tabImage_scrollArea_contents"));
        tabImage_scrollArea_contents->setGeometry(QRect(0, 0, 670, 464));
        tabImage_scrollArea->setWidget(tabImage_scrollArea_contents);

        gridLayout_4->addWidget(tabImage_scrollArea, 0, 0, 1, 1);

        tabs->addTab(tab_image, QString());
        tab_animation = new QWidget();
        tab_animation->setObjectName(QString::fromUtf8("tab_animation"));
        gridLayout_5 = new QGridLayout(tab_animation);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabAnimation_scrollArea = new QScrollArea(tab_animation);
        tabAnimation_scrollArea->setObjectName(QString::fromUtf8("tabAnimation_scrollArea"));
        tabAnimation_scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 419, 495));
        tabAnimation_scrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout_5->addWidget(tabAnimation_scrollArea, 0, 0, 1, 1);

        tabs->addTab(tab_animation, QString());
        tab_sfx = new QWidget();
        tab_sfx->setObjectName(QString::fromUtf8("tab_sfx"));
        tabs->addTab(tab_sfx, QString());
        tab_music = new QWidget();
        tab_music->setObjectName(QString::fromUtf8("tab_music"));
        tabs->addTab(tab_music, QString());

        gridLayout->addWidget(tabs, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, -1, 10, -1);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(320, 200));
        widget->setMaximumSize(QSize(320, 200));

        gridLayout_6->addWidget(widget, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_6, 0, 1, 1, 1);

        SceneEditorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SceneEditorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1051, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SceneEditorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SceneEditorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SceneEditorWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);

        retranslateUi(SceneEditorWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SceneEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SceneEditorWindow)
    {
        SceneEditorWindow->setWindowTitle(QApplication::translate("SceneEditorWindow", "Scenes Editor", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("SceneEditorWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("SceneEditorWindow", "Quit", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_sequence), QApplication::translate("SceneEditorWindow", "Sequence", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_cleararea), QApplication::translate("SceneEditorWindow", "Clear-Area", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_text), QApplication::translate("SceneEditorWindow", "Show Text", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_image), QApplication::translate("SceneEditorWindow", "Show Image", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_animation), QApplication::translate("SceneEditorWindow", "Show Animation", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_sfx), QApplication::translate("SceneEditorWindow", "Play Sound Effect", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab_music), QApplication::translate("SceneEditorWindow", "Play Music", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SceneEditorWindow", "PLAY", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("SceneEditorWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SceneEditorWindow: public Ui_SceneEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEEDITORWINDOW_H
