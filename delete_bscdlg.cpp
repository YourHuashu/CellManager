#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDate>
#include "delete_bscdlg.h"

delete_bscDlg::delete_bscDlg(QWidget *parent) :
    QDialog(parent)
{
    bscidlabel = new QLabel;
    bscidlabel->setText(tr("请输入要删除的基站控制器编号"));
    bscid = new QLineEdit;

    okBtn = new QPushButton;
    okBtn->setText(tr("删除"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);

    layout1->addWidget(bscidlabel, 0, 0);
    layout1->addWidget(bscid, 0, 1);

    QHBoxLayout *layout2 = new QHBoxLayout();

    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);
    layout1->addLayout(layout2, 1, 1);

    layout1->setColumnStretch(0, 1);
    layout1->setColumnStretch(1, 3);

    layout1->setMargin(15);
    layout1->setSpacing(10);

    connect(okBtn,SIGNAL(clicked()), this, SLOT(okBtnOnclick()));
    connect(cancelBtn,SIGNAL(clicked()), this, SLOT(cancelBtnOnclick()));

    isok = false;
    setWindowIcon(QIcon("main.png"));
    setWindowTitle(tr("删除基站控制器"));
    bscid->setFocus();
}

#define DELETEBSC "delete from bscs where bscid = %1"

void delete_bscDlg::okBtnOnclick()
{
    if (bscid->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr("错误"), tr("基站控制器编号不能为空"));
        bscid->setFocus();
        return ;
    }

    isok = true;
    SQL = QString(DELETEBSC).arg(bscid->text());
    close();

}

void delete_bscDlg::cancelBtnOnclick()
{
    close();
}


