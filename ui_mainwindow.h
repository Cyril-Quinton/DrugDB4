/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouvelle_Pharmacie;
    QAction *actionModifierPharmacie;
    QAction *actionSauvegarder;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QFrame *line;
    QLabel *label_5;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSplitter *splitter;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QSplitter *splitter_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QCheckBox *checkBox_2;
    QLabel *label_7;
    QLabel *label_3;
    QCheckBox *checkBox;
    QFrame *line_2;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 458);
        actionNouvelle_Pharmacie = new QAction(MainWindow);
        actionNouvelle_Pharmacie->setObjectName(QStringLiteral("actionNouvelle_Pharmacie"));
        actionModifierPharmacie = new QAction(MainWindow);
        actionModifierPharmacie->setObjectName(QStringLiteral("actionModifierPharmacie"));
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName(QStringLiteral("actionSauvegarder"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(230, 0, 161, 361));
        textEdit->setReadOnly(true);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(400, 0, 271, 361));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 20, 141, 27));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 40, 231, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 0, 141, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 221, 300));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        splitter->addWidget(lineEdit);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);
        splitter->addWidget(pushButton);

        verticalLayout->addWidget(splitter);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        lineEdit_2 = new QLineEdit(splitter_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        splitter_2->addWidget(lineEdit_2);
        pushButton_2 = new QPushButton(splitter_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);
        splitter_2->addWidget(pushButton_2);

        verticalLayout->addWidget(splitter_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 3);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout->addWidget(pushButton_3, 6, 2, 2, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 3);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 7, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 6, 0, 1, 1);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 0, 1, 3);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 5, 2, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 5, 0, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 370, 51, 27));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        textEdit->raise();
        tableWidget->raise();
        comboBox->raise();
        line->raise();
        label_5->raise();
        pushButton_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 25));
        menuBar->setDefaultUp(false);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(comboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton_2);
        QWidget::setTabOrder(pushButton_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, spinBox);
        QWidget::setTabOrder(spinBox, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, tableWidget);
        QWidget::setTabOrder(tableWidget, textEdit);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionNouvelle_Pharmacie);
        menuFichier->addAction(actionModifierPharmacie);
        menuFichier->addAction(actionSauvegarder);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DrugDB 1.0", 0));
        actionNouvelle_Pharmacie->setText(QApplication::translate("MainWindow", "Ouvrir Pharmacie (ctrl+o)", 0));
        actionModifierPharmacie->setText(QApplication::translate("MainWindow", "Modifier la pharmacie (ctrl+m)", 0));
        actionSauvegarder->setText(QApplication::translate("MainWindow", "Sauvegarder (ctrl+s)", 0));
        label_5->setText(QApplication::translate("MainWindow", "Pharmacie courante", 0));
        label->setText(QApplication::translate("MainWindow", "M\303\251dicament", 0));
        pushButton->setText(QApplication::translate("MainWindow", "OK", 0));
        label_2->setText(QApplication::translate("MainWindow", "Effet secondaire", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "OK", 0));
        label_6->setText(QApplication::translate("MainWindow", "Recherche Basique", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "Al\303\251atoire", 0));
        label_7->setText(QApplication::translate("MainWindow", "Recherche Avanc\303\251e", 0));
        label_3->setText(QApplication::translate("MainWindow", "M\303\251dicament", 0));
        checkBox->setText(QApplication::translate("MainWindow", "2 premiers", 0));
        label_4->setText(QApplication::translate("MainWindow", "Nb effet min  ", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Aide", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
