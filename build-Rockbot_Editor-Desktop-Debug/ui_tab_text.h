/********************************************************************************
** Form generated from reading UI file 'tab_text.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_TEXT_H
#define UI_TAB_TEXT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TabText
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *AddButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *listCombo;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *text_lineEdit;
    QLabel *label_3;
    QSpinBox *textY_spinBox;
    QSpinBox *textX_spinBox;
    QLabel *label_5;
    QComboBox *transitionType_comboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *TabText)
    {
        if (TabText->objectName().isEmpty())
            TabText->setObjectName(QString::fromUtf8("TabText"));
        TabText->resize(400, 300);
        verticalLayout = new QVBoxLayout(TabText);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        AddButton = new QPushButton(TabText);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        gridLayout_2->addWidget(AddButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        listCombo = new QComboBox(TabText);
        listCombo->setObjectName(QString::fromUtf8("listCombo"));

        gridLayout_2->addWidget(listCombo, 1, 2, 1, 1);

        label_4 = new QLabel(TabText);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(TabText);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(TabText);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        text_lineEdit = new QLineEdit(TabText);
        text_lineEdit->setObjectName(QString::fromUtf8("text_lineEdit"));

        gridLayout->addWidget(text_lineEdit, 1, 0, 1, 1);

        label_3 = new QLabel(TabText);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        textY_spinBox = new QSpinBox(TabText);
        textY_spinBox->setObjectName(QString::fromUtf8("textY_spinBox"));

        gridLayout->addWidget(textY_spinBox, 1, 2, 1, 1);

        textX_spinBox = new QSpinBox(TabText);
        textX_spinBox->setObjectName(QString::fromUtf8("textX_spinBox"));

        gridLayout->addWidget(textX_spinBox, 1, 1, 1, 1);

        label_5 = new QLabel(TabText);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        transitionType_comboBox = new QComboBox(TabText);
        transitionType_comboBox->setObjectName(QString::fromUtf8("transitionType_comboBox"));

        gridLayout->addWidget(transitionType_comboBox, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TabText);

        QMetaObject::connectSlotsByName(TabText);
    } // setupUi

    void retranslateUi(QDialog *TabText)
    {
        TabText->setWindowTitle(QApplication::translate("TabText", "Dialog", 0, QApplication::UnicodeUTF8));
        AddButton->setText(QApplication::translate("TabText", "Add New Entry", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TabText", "Select Entry:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TabText", "X", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TabText", "Text", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TabText", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TabText", "Transition Type:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabText: public Ui_TabText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_TEXT_H
