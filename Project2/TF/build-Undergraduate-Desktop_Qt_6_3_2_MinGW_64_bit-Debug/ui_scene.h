/********************************************************************************
** Form generated from reading UI file 'scene.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENE_H
#define UI_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <unit.h>

QT_BEGIN_NAMESPACE

class Ui_Scene
{
public:
    Unit *widget;
    Unit *widget_2;

    void setupUi(QWidget *Scene)
    {
        if (Scene->objectName().isEmpty())
            Scene->setObjectName(QString::fromUtf8("Scene"));
        Scene->resize(1005, 670);
        widget = new Unit(Scene);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 180, 120, 80));
        widget->setStyleSheet(QString::fromUtf8(""));
        widget_2 = new Unit(Scene);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(270, 290, 120, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));

        retranslateUi(Scene);

        QMetaObject::connectSlotsByName(Scene);
    } // setupUi

    void retranslateUi(QWidget *Scene)
    {
        Scene->setWindowTitle(QCoreApplication::translate("Scene", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scene: public Ui_Scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENE_H
