/********************************************************************************
** Form generated from reading UI file 'stage_swap_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGE_SWAP_DIALOG_H
#define UI_STAGE_SWAP_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_stage_swap_dialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *origin_combo;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QComboBox *destiny_combo;

    void setupUi(QDialog *stage_swap_dialog)
    {
        if (stage_swap_dialog->objectName().isEmpty())
            stage_swap_dialog->setObjectName(QString::fromUtf8("stage_swap_dialog"));
        stage_swap_dialog->resize(400, 300);
        gridLayout = new QGridLayout(stage_swap_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        origin_combo = new QComboBox(stage_swap_dialog);
        origin_combo->setObjectName(QString::fromUtf8("origin_combo"));

        gridLayout->addWidget(origin_combo, 0, 1, 1, 1);

        label = new QLabel(stage_swap_dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        label_2 = new QLabel(stage_swap_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(stage_swap_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        destiny_combo = new QComboBox(stage_swap_dialog);
        destiny_combo->setObjectName(QString::fromUtf8("destiny_combo"));

        gridLayout->addWidget(destiny_combo, 1, 1, 1, 1);


        retranslateUi(stage_swap_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), stage_swap_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), stage_swap_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(stage_swap_dialog);
    } // setupUi

    void retranslateUi(QDialog *stage_swap_dialog)
    {
        stage_swap_dialog->setWindowTitle(QApplication::translate("stage_swap_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("stage_swap_dialog", "Origin Stage:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("stage_swap_dialog", "Destiny Stage:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class stage_swap_dialog: public Ui_stage_swap_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGE_SWAP_DIALOG_H
