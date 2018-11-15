#include "widget.h"

#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *pBtn = new QPushButton("crash");
    connect(pBtn,SIGNAL(clicked()),this,SLOT(slotOnClicked()));

    QVBoxLayout *pVlt = new QVBoxLayout;
    pVlt->addWidget(pBtn);
    pVlt->addStretch();

    setLayout(pVlt);
}

Widget::~Widget()
{
}

void Widget::a()
{
    setWindowTitle("a");
    b();
}

void Widget::b()
{
    setWindowTitle("b");
    c();
}

void Widget::c()
{
    setWindowTitle("c");
    int *a = 0;
    *a = 1;
}

void Widget::slotOnClicked()
{
    setWindowTitle("clicked");
    a();
}
