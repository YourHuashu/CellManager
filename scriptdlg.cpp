#include <QGridLayout>
#include <QLayout>
#include <QMessageBox>
#include <QHBoxLayout>
#include "scriptdlg.h"

scriptDlg::scriptDlg(QWidget *parent) :
    QDialog(parent)
{
    lable0 = new QLabel;
    lable0->setText(tr("请输入SQL"));
    textEditSQL = new QTextEdit;

    okBtn = new QPushButton;
    okBtn->setText(tr("执行"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));


    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(lable0, 0, 0);
    layout1->addWidget(textEditSQL, 0, 1);


    QHBoxLayout *layout2 = new QHBoxLayout();

    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);
    layout1->addLayout(layout2, 1, 1);


    layout1->setColumnStretch(0, 1);//设置第一列宽为1
    layout1->setColumnStretch(1, 5);//设置第二列宽为5

    layout1->setMargin(15);//设置边距
    layout1->setSpacing(10);//设置控件间间距


    //layout1->setSizeConstraint(QLayout::SetFixedSize);

    connect(okBtn,SIGNAL(clicked()), this, SLOT(okBtnOnclick()));
    connect(cancelBtn,SIGNAL(clicked()), this, SLOT(cancelBtnOnclick()));

    isok = false;
    setWindowIcon(QIcon("main.png"));
    setWindowTitle(tr("执行SQL"));
    //setWindowFlags(windowFlags() | Qt::Tool);//设置不在任务栏出现
    textEditSQL->setFocus();//设置textEditSQL控件具有用户输入焦点
}

void scriptDlg::okBtnOnclick()
{
    isok = true;
    SQL = textEditSQL->toPlainText();
    close();

}

void scriptDlg::cancelBtnOnclick()
{
    close();
}


