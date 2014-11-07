/********************************************************************************
** Form generated from reading UI file 'dialog_phname.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PHNAME_H
#define UI_DIALOG_PHNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_PhName
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog_PhName)
    {
        if (Dialog_PhName->objectName().isEmpty())
            Dialog_PhName->setObjectName(QStringLiteral("Dialog_PhName"));
        Dialog_PhName->resize(400, 89);
        buttonBox = new QDialogButtonBox(Dialog_PhName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Dialog_PhName);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 20, 208, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(Dialog_PhName);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_PhName, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), lineEdit, SLOT(copy()));

        QMetaObject::connectSlotsByName(Dialog_PhName);
    } // setupUi

    void retranslateUi(QDialog *Dialog_PhName)
    {
        Dialog_PhName->setWindowTitle(QApplication::translate("Dialog_PhName", "Dialog", 0));
        label->setText(QApplication::translate("Dialog_PhName", "donnez un nom \303\240 la pharmacie", 0));
        lineEdit->setText(QApplication::translate("Dialog_PhName", "sans_titre", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_PhName: public Ui_Dialog_PhName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PHNAME_H
