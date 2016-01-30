/********************************************************************************
** Form generated from reading UI file 'sceneslist.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENESLIST_H
#define UI_SCENESLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ScenesList
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *ScenesList)
    {
        if (ScenesList->objectName().isEmpty())
            ScenesList->setObjectName(QString::fromUtf8("ScenesList"));
        ScenesList->resize(400, 300);
        textEdit = new QTextEdit(ScenesList);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 130, 104, 70));

        retranslateUi(ScenesList);

        QMetaObject::connectSlotsByName(ScenesList);
    } // setupUi

    void retranslateUi(QDialog *ScenesList)
    {
        ScenesList->setWindowTitle(QApplication::translate("ScenesList", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScenesList: public Ui_ScenesList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENESLIST_H
