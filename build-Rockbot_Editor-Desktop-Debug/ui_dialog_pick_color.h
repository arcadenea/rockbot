/********************************************************************************
** Form generated from reading UI file 'dialog_pick_color.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PICK_COLOR_H
#define UI_DIALOG_PICK_COLOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_pick_color
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *dialog_pick_color)
    {
        if (dialog_pick_color->objectName().isEmpty())
            dialog_pick_color->setObjectName(QString::fromUtf8("dialog_pick_color"));
        dialog_pick_color->resize(659, 383);
        buttonBox = new QDialogButtonBox(dialog_pick_color);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 350, 461, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(dialog_pick_color);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 641, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(dialog_pick_color);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_pick_color, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_pick_color, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_pick_color);
    } // setupUi

    void retranslateUi(QDialog *dialog_pick_color)
    {
        dialog_pick_color->setWindowTitle(QApplication::translate("dialog_pick_color", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_pick_color: public Ui_dialog_pick_color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PICK_COLOR_H
