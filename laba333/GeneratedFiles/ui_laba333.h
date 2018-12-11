/********************************************************************************
** Form generated from reading UI file 'laba333.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABA333_H
#define UI_LABA333_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Laba333Class
{
public:
    QGroupBox *add;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *modelAdd;
    QLabel *label_2;
    QLineEdit *colorAdd;
    QLabel *label_3;
    QLineEdit *znAdd;
    QPushButton *addAdd;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *get;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *znGet;
    QLabel *label_4;
    QLineEdit *modelGet;
    QLabel *label_5;
    QLineEdit *colorGet;
    QPushButton *getGet;
    QPushButton *delGet;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;
    QGroupBox *menu;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *menuFiles;
    QPushButton *menuAdd;
    QPushButton *menuGet;
    QPushButton *menuGetAll;
    QGroupBox *files;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *nameFiles;
    QPushButton *addFile;
    QPushButton *printFile;
    QSpacerItem *verticalSpacer;
    QPushButton *delAllFiles;

    void setupUi(QWidget *Laba333Class)
    {
        if (Laba333Class->objectName().isEmpty())
            Laba333Class->setObjectName(QStringLiteral("Laba333Class"));
        Laba333Class->resize(858, 612);
        add = new QGroupBox(Laba333Class);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(230, 20, 221, 191));
        verticalLayoutWidget = new QWidget(add);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 201, 166));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        modelAdd = new QLineEdit(verticalLayoutWidget);
        modelAdd->setObjectName(QStringLiteral("modelAdd"));

        verticalLayout->addWidget(modelAdd);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        colorAdd = new QLineEdit(verticalLayoutWidget);
        colorAdd->setObjectName(QStringLiteral("colorAdd"));

        verticalLayout->addWidget(colorAdd);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        znAdd = new QLineEdit(verticalLayoutWidget);
        znAdd->setObjectName(QStringLiteral("znAdd"));

        verticalLayout->addWidget(znAdd);

        addAdd = new QPushButton(verticalLayoutWidget);
        addAdd->setObjectName(QStringLiteral("addAdd"));

        verticalLayout->addWidget(addAdd);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        get = new QGroupBox(Laba333Class);
        get->setObjectName(QStringLiteral("get"));
        get->setGeometry(QRect(240, 400, 211, 191));
        verticalLayoutWidget_2 = new QWidget(get);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 19, 191, 169));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        znGet = new QLabel(verticalLayoutWidget_2);
        znGet->setObjectName(QStringLiteral("znGet"));
        znGet->setLayoutDirection(Qt::LeftToRight);
        znGet->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(znGet);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        modelGet = new QLineEdit(verticalLayoutWidget_2);
        modelGet->setObjectName(QStringLiteral("modelGet"));

        verticalLayout_2->addWidget(modelGet);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        colorGet = new QLineEdit(verticalLayoutWidget_2);
        colorGet->setObjectName(QStringLiteral("colorGet"));

        verticalLayout_2->addWidget(colorGet);

        getGet = new QPushButton(verticalLayoutWidget_2);
        getGet->setObjectName(QStringLiteral("getGet"));

        verticalLayout_2->addWidget(getGet);

        delGet = new QPushButton(verticalLayoutWidget_2);
        delGet->setObjectName(QStringLiteral("delGet"));

        verticalLayout_2->addWidget(delGet);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tableWidget = new QTableWidget(Laba333Class);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(490, 90, 351, 192));
        menu = new QGroupBox(Laba333Class);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(10, 10, 211, 191));
        verticalLayoutWidget_3 = new QWidget(menu);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 191, 161));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        menuFiles = new QPushButton(verticalLayoutWidget_3);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));

        verticalLayout_3->addWidget(menuFiles);

        menuAdd = new QPushButton(verticalLayoutWidget_3);
        menuAdd->setObjectName(QStringLiteral("menuAdd"));

        verticalLayout_3->addWidget(menuAdd);

        menuGet = new QPushButton(verticalLayoutWidget_3);
        menuGet->setObjectName(QStringLiteral("menuGet"));

        verticalLayout_3->addWidget(menuGet);

        menuGetAll = new QPushButton(verticalLayoutWidget_3);
        menuGetAll->setObjectName(QStringLiteral("menuGetAll"));

        verticalLayout_3->addWidget(menuGetAll);

        files = new QGroupBox(Laba333Class);
        files->setObjectName(QStringLiteral("files"));
        files->setGeometry(QRect(230, 210, 221, 191));
        verticalLayoutWidget_4 = new QWidget(files);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 201, 153));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        nameFiles = new QLineEdit(verticalLayoutWidget_4);
        nameFiles->setObjectName(QStringLiteral("nameFiles"));

        verticalLayout_4->addWidget(nameFiles);

        addFile = new QPushButton(verticalLayoutWidget_4);
        addFile->setObjectName(QStringLiteral("addFile"));

        verticalLayout_4->addWidget(addFile);

        printFile = new QPushButton(verticalLayoutWidget_4);
        printFile->setObjectName(QStringLiteral("printFile"));

        verticalLayout_4->addWidget(printFile);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        delAllFiles = new QPushButton(verticalLayoutWidget_4);
        delAllFiles->setObjectName(QStringLiteral("delAllFiles"));

        verticalLayout_4->addWidget(delAllFiles);


        retranslateUi(Laba333Class);

        QMetaObject::connectSlotsByName(Laba333Class);
    } // setupUi

    void retranslateUi(QWidget *Laba333Class)
    {
        Laba333Class->setWindowTitle(QApplication::translate("Laba333Class", "Laba333", Q_NULLPTR));
        add->setTitle(QApplication::translate("Laba333Class", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", Q_NULLPTR));
        label->setText(QApplication::translate("Laba333Class", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("Laba333Class", "\320\246\320\262\320\265\321\202", Q_NULLPTR));
        label_3->setText(QApplication::translate("Laba333Class", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        addAdd->setText(QApplication::translate("Laba333Class", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        get->setTitle(QApplication::translate("Laba333Class", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        znGet->setText(QString());
        label_4->setText(QApplication::translate("Laba333Class", "\320\234\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        label_5->setText(QApplication::translate("Laba333Class", "\320\246\320\262\320\265\321\202", Q_NULLPTR));
        getGet->setText(QApplication::translate("Laba333Class", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214", Q_NULLPTR));
        delGet->setText(QApplication::translate("Laba333Class", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Laba333Class", "\320\274\320\276\320\264\320\265\320\273\321\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Laba333Class", "\321\206\320\262\320\265\321\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Laba333Class", "\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Laba333Class", "\320\234\320\265\320\275\321\216", Q_NULLPTR));
        menuFiles->setText(QApplication::translate("Laba333Class", "\321\204\320\260\320\271\320\273", Q_NULLPTR));
        menuAdd->setText(QApplication::translate("Laba333Class", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menuGet->setText(QApplication::translate("Laba333Class", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menuGetAll->setText(QApplication::translate("Laba333Class", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\262\321\201\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", Q_NULLPTR));
        files->setTitle(QApplication::translate("Laba333Class", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        label_6->setText(QApplication::translate("Laba333Class", "\320\247\321\202\320\265\320\270\320\265/\320\227\320\260\320\277\320\270\321\201\321\214 \320\262 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        nameFiles->setText(QApplication::translate("Laba333Class", "ffff.txt", Q_NULLPTR));
        addFile->setText(QApplication::translate("Laba333Class", "\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        printFile->setText(QApplication::translate("Laba333Class", "\320\262\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        delAllFiles->setText(QApplication::translate("Laba333Class", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Laba333Class: public Ui_Laba333Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA333_H
