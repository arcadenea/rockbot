/********************************************************************************
** Form generated from reading UI file 'loadgamepicker.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADGAMEPICKER_H
#define UI_LOADGAMEPICKER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_loadGamePicker
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *gameList;

    void setupUi(QDialog *loadGamePicker)
    {
        if (loadGamePicker->objectName().isEmpty())
            loadGamePicker->setObjectName(QString::fromUtf8("loadGamePicker"));
        loadGamePicker->resize(318, 238);
        buttonBox = new QDialogButtonBox(loadGamePicker);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gameList = new QListWidget(loadGamePicker);
        gameList->setObjectName(QString::fromUtf8("gameList"));
        gameList->setGeometry(QRect(10, 10, 301, 181));

        retranslateUi(loadGamePicker);
        QObject::connect(buttonBox, SIGNAL(accepted()), loadGamePicker, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), loadGamePicker, SLOT(reject()));

        QMetaObject::connectSlotsByName(loadGamePicker);
    } // setupUi

    void retranslateUi(QDialog *loadGamePicker)
    {
        loadGamePicker->setWindowTitle(QApplication::translate("loadGamePicker", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loadGamePicker: public Ui_loadGamePicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADGAMEPICKER_H
