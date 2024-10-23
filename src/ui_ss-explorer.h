/********************************************************************************
** Form generated from reading UI file 'SSExplorer1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SS_2D_EXPLORER_H
#define UI_SS_2D_EXPLORER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SSExplorer
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QScrollBar *verticalScrollBar;
    QVBoxLayout *verticalLayout_7;
    QLabel *smallImg0;
    QLabel *smallImg1;
    QLabel *smallImg2;
    QLabel *smallImg3;
    QLabel *largeImg;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *printBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDockWidget *SSExplorer)
    {
        if (SSExplorer->objectName().isEmpty())
            SSExplorer->setObjectName("SSExplorer");
        SSExplorer->resize(1035, 573);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SSExplorer->sizePolicy().hasHeightForWidth());
        SSExplorer->setSizePolicy(sizePolicy);
        SSExplorer->setFloating(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(dockWidgetContents);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalScrollBar = new QScrollBar(dockWidgetContents);
        verticalScrollBar->setObjectName("verticalScrollBar");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalScrollBar->sizePolicy().hasHeightForWidth());
        verticalScrollBar->setSizePolicy(sizePolicy2);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(verticalScrollBar);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        smallImg0 = new QLabel(dockWidgetContents);
        smallImg0->setObjectName("smallImg0");

        verticalLayout_7->addWidget(smallImg0);

        smallImg1 = new QLabel(dockWidgetContents);
        smallImg1->setObjectName("smallImg1");

        verticalLayout_7->addWidget(smallImg1);

        smallImg2 = new QLabel(dockWidgetContents);
        smallImg2->setObjectName("smallImg2");

        verticalLayout_7->addWidget(smallImg2);

        smallImg3 = new QLabel(dockWidgetContents);
        smallImg3->setObjectName("smallImg3");

        verticalLayout_7->addWidget(smallImg3);


        horizontalLayout_3->addLayout(verticalLayout_7);

        largeImg = new QLabel(dockWidgetContents);
        largeImg->setObjectName("largeImg");
        sizePolicy2.setHeightForWidth(largeImg->sizePolicy().hasHeightForWidth());
        largeImg->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(largeImg);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);
        horizontalLayout_3->setStretch(2, 30);

        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        printBtn = new QPushButton(dockWidgetContents);
        printBtn->setObjectName("printBtn");
        sizePolicy2.setHeightForWidth(printBtn->sizePolicy().hasHeightForWidth());
        printBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(printBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        cancelBtn = new QPushButton(dockWidgetContents);
        cancelBtn->setObjectName("cancelBtn");
        sizePolicy2.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(cancelBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_4);

        verticalLayout_6->setStretch(0, 15);
        verticalLayout_6->setStretch(1, 1);

        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 1, 1);

        SSExplorer->setWidget(dockWidgetContents);

        retranslateUi(SSExplorer);

        QMetaObject::connectSlotsByName(SSExplorer);
    } // setupUi

    void retranslateUi(QDockWidget *SSExplorer)
    {
        SSExplorer->setWindowTitle(QCoreApplication::translate("SSExplorer", "DockWidget", nullptr));
        smallImg0->setText(QCoreApplication::translate("SSExplorer", "TextLabel", nullptr));
        smallImg1->setText(QCoreApplication::translate("SSExplorer", "TextLabel", nullptr));
        smallImg2->setText(QCoreApplication::translate("SSExplorer", "TextLabel", nullptr));
        smallImg3->setText(QCoreApplication::translate("SSExplorer", "TextLabel", nullptr));
        largeImg->setText(QString());
        printBtn->setText(QCoreApplication::translate("SSExplorer", "Print", nullptr));
        cancelBtn->setText(QCoreApplication::translate("SSExplorer", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SSExplorer: public Ui_SSExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SS_2D_EXPLORER_H
