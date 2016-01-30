/********************************************************************************
** Form generated from reading UI file 'tab_image.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_IMAGE_H
#define UI_TAB_IMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tab_image
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *select_comboBox;
    QLabel *label_3;
    QPushButton *add_Button;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *desty_spinBox;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *y_spinBox;
    QLabel *label;
    QSpinBox *destx_spinBox;
    QLabel *label_8;
    QSpinBox *delay_spinBox;
    QSpinBox *x_spinBox;
    QLabel *label_2;
    QLineEdit *name_textEdit;
    QLabel *label_9;
    QCheckBox *blocking_checkBox;
    QComboBox *filename_comboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *tab_image)
    {
        if (tab_image->objectName().isEmpty())
            tab_image->setObjectName(QString::fromUtf8("tab_image"));
        tab_image->resize(565, 391);
        verticalLayout_2 = new QVBoxLayout(tab_image);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        select_comboBox = new QComboBox(tab_image);
        select_comboBox->setObjectName(QString::fromUtf8("select_comboBox"));

        gridLayout->addWidget(select_comboBox, 1, 1, 1, 1);

        label_3 = new QLabel(tab_image);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        add_Button = new QPushButton(tab_image);
        add_Button->setObjectName(QString::fromUtf8("add_Button"));

        gridLayout->addWidget(add_Button, 0, 1, 1, 1);

        label_4 = new QLabel(tab_image);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(tab_image);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        desty_spinBox = new QSpinBox(tab_image);
        desty_spinBox->setObjectName(QString::fromUtf8("desty_spinBox"));
        desty_spinBox->setMaximum(999);

        gridLayout->addWidget(desty_spinBox, 7, 1, 1, 1);

        label_7 = new QLabel(tab_image);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_6 = new QLabel(tab_image);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        y_spinBox = new QSpinBox(tab_image);
        y_spinBox->setObjectName(QString::fromUtf8("y_spinBox"));
        y_spinBox->setMaximum(999);

        gridLayout->addWidget(y_spinBox, 5, 1, 1, 1);

        label = new QLabel(tab_image);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        destx_spinBox = new QSpinBox(tab_image);
        destx_spinBox->setObjectName(QString::fromUtf8("destx_spinBox"));
        destx_spinBox->setMaximum(999);

        gridLayout->addWidget(destx_spinBox, 6, 1, 1, 1);

        label_8 = new QLabel(tab_image);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        delay_spinBox = new QSpinBox(tab_image);
        delay_spinBox->setObjectName(QString::fromUtf8("delay_spinBox"));
        delay_spinBox->setMaximum(999);

        gridLayout->addWidget(delay_spinBox, 8, 1, 1, 1);

        x_spinBox = new QSpinBox(tab_image);
        x_spinBox->setObjectName(QString::fromUtf8("x_spinBox"));
        x_spinBox->setMaximum(999);

        gridLayout->addWidget(x_spinBox, 4, 1, 1, 1);

        label_2 = new QLabel(tab_image);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        name_textEdit = new QLineEdit(tab_image);
        name_textEdit->setObjectName(QString::fromUtf8("name_textEdit"));

        gridLayout->addWidget(name_textEdit, 2, 1, 1, 1);

        label_9 = new QLabel(tab_image);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        blocking_checkBox = new QCheckBox(tab_image);
        blocking_checkBox->setObjectName(QString::fromUtf8("blocking_checkBox"));
        blocking_checkBox->setEnabled(false);
        blocking_checkBox->setChecked(true);

        gridLayout->addWidget(blocking_checkBox, 9, 1, 1, 1);

        filename_comboBox = new QComboBox(tab_image);
        filename_comboBox->setObjectName(QString::fromUtf8("filename_comboBox"));

        gridLayout->addWidget(filename_comboBox, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(tab_image);

        QMetaObject::connectSlotsByName(tab_image);
    } // setupUi

    void retranslateUi(QWidget *tab_image)
    {
        tab_image->setWindowTitle(QApplication::translate("tab_image", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("tab_image", "File:", 0, QApplication::UnicodeUTF8));
        add_Button->setText(QApplication::translate("tab_image", "Add New Entry", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("tab_image", "X:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("tab_image", "Y:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("tab_image", "Dest Y:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("tab_image", "Dest X:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("tab_image", "Select Entry:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("tab_image", "Move Delay:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("tab_image", "Name:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("tab_image", "Blocking:", 0, QApplication::UnicodeUTF8));
        blocking_checkBox->setText(QString());
        blocking_checkBox->setShortcut(QApplication::translate("tab_image", "Ctrl+S", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tab_image: public Ui_tab_image {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_IMAGE_H
