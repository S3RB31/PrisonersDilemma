/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "fieldwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QFrame *controls;
    QGroupBox *sizeBox;
    QCheckBox *lockBox;
    QLineEdit *cellszEdit;
    QPushButton *cellszButton;
    QLabel *cellszLabel;
    QGroupBox *statusBox;
    QLabel *statusLabel2;
    QLabel *statusLabel1;
    QLabel *statusLabel3;
    QGroupBox *gameBox;
    QPushButton *playButton;
    QLabel *stepsLabel;
    QLineEdit *stepsEdit;
    QCheckBox *stepsBox;
    QPushButton *imageButton;
    FieldWidget *playField;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(717, 500);
        MainWindowClass->setMinimumSize(QSize(717, 500));
        MainWindowClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(717, 500));
        controls = new QFrame(centralWidget);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(470, 20, 221, 481));
        sizeBox = new QGroupBox(controls);
        sizeBox->setObjectName(QStringLiteral("sizeBox"));
        sizeBox->setGeometry(QRect(10, 10, 191, 91));
        sizeBox->setAlignment(Qt::AlignCenter);
        sizeBox->setFlat(true);
        lockBox = new QCheckBox(sizeBox);
        lockBox->setObjectName(QStringLiteral("lockBox"));
        lockBox->setGeometry(QRect(20, 60, 61, 25));
        cellszEdit = new QLineEdit(sizeBox);
        cellszEdit->setObjectName(QStringLiteral("cellszEdit"));
        cellszEdit->setGeometry(QRect(110, 26, 51, 20));
        cellszEdit->setCursor(QCursor(Qt::IBeamCursor));
        cellszEdit->setFocusPolicy(Qt::StrongFocus);
        cellszEdit->setStyleSheet(QStringLiteral("border:1px solid black;"));
        cellszEdit->setAlignment(Qt::AlignCenter);
        cellszButton = new QPushButton(sizeBox);
        cellszButton->setObjectName(QStringLiteral("cellszButton"));
        cellszButton->setGeometry(QRect(100, 60, 71, 25));
        cellszButton->setCursor(QCursor(Qt::PointingHandCursor));
        cellszButton->setFocusPolicy(Qt::StrongFocus);
        cellszLabel = new QLabel(sizeBox);
        cellszLabel->setObjectName(QStringLiteral("cellszLabel"));
        cellszLabel->setGeometry(QRect(30, 27, 71, 16));
        statusBox = new QGroupBox(controls);
        statusBox->setObjectName(QStringLiteral("statusBox"));
        statusBox->setGeometry(QRect(10, 120, 191, 121));
        statusBox->setAlignment(Qt::AlignCenter);
        statusBox->setFlat(true);
        statusLabel2 = new QLabel(statusBox);
        statusLabel2->setObjectName(QStringLiteral("statusLabel2"));
        statusLabel2->setGeometry(QRect(10, 60, 171, 20));
        statusLabel1 = new QLabel(statusBox);
        statusLabel1->setObjectName(QStringLiteral("statusLabel1"));
        statusLabel1->setGeometry(QRect(10, 30, 171, 20));
        statusLabel3 = new QLabel(statusBox);
        statusLabel3->setObjectName(QStringLiteral("statusLabel3"));
        statusLabel3->setGeometry(QRect(10, 90, 171, 20));
        gameBox = new QGroupBox(controls);
        gameBox->setObjectName(QStringLiteral("gameBox"));
        gameBox->setGeometry(QRect(10, 260, 191, 141));
        gameBox->setAlignment(Qt::AlignCenter);
        gameBox->setFlat(true);
        playButton = new QPushButton(gameBox);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(10, 60, 91, 23));
        stepsLabel = new QLabel(gameBox);
        stepsLabel->setObjectName(QStringLiteral("stepsLabel"));
        stepsLabel->setEnabled(true);
        stepsLabel->setGeometry(QRect(10, 26, 81, 16));
        stepsLabel->setAlignment(Qt::AlignCenter);
        stepsEdit = new QLineEdit(gameBox);
        stepsEdit->setObjectName(QStringLiteral("stepsEdit"));
        stepsEdit->setEnabled(true);
        stepsEdit->setGeometry(QRect(120, 26, 51, 20));
        stepsEdit->setCursor(QCursor(Qt::IBeamCursor));
        stepsEdit->setFocusPolicy(Qt::StrongFocus);
        stepsEdit->setStyleSheet(QStringLiteral("border:1px solid black;"));
        stepsEdit->setAlignment(Qt::AlignCenter);
        stepsBox = new QCheckBox(gameBox);
        stepsBox->setObjectName(QStringLiteral("stepsBox"));
        stepsBox->setEnabled(true);
        stepsBox->setGeometry(QRect(120, 60, 61, 21));
        stepsBox->setChecked(false);
        imageButton = new QPushButton(gameBox);
        imageButton->setObjectName(QStringLiteral("imageButton"));
        imageButton->setGeometry(QRect(10, 100, 91, 23));
        playField = new FieldWidget(centralWidget);
        playField->setObjectName(QStringLiteral("playField"));
        playField->setGeometry(QRect(20, 30, 161, 141));
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        sizeBox->setTitle(QApplication::translate("MainWindowClass", "Size settings", 0));
        lockBox->setText(QApplication::translate("MainWindowClass", "Lock UI", 0));
        cellszButton->setText(QApplication::translate("MainWindowClass", "Set cell size", 0));
        cellszLabel->setText(QApplication::translate("MainWindowClass", "Cell size   ->", 0));
        statusBox->setTitle(QApplication::translate("MainWindowClass", "Status", 0));
        statusLabel2->setText(QString());
        statusLabel1->setText(QString());
        statusLabel3->setText(QString());
        gameBox->setTitle(QApplication::translate("MainWindowClass", "Game", 0));
        playButton->setText(QApplication::translate("MainWindowClass", "PLAY!", 0));
        stepsLabel->setText(QApplication::translate("MainWindowClass", "No. of steps   ->", 0));
        stepsEdit->setText(QApplication::translate("MainWindowClass", "1", 0));
        stepsBox->setText(QApplication::translate("MainWindowClass", "Infinite", 0));
        imageButton->setText(QApplication::translate("MainWindowClass", "Save image ...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
