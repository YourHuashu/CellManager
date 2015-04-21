#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDate>
#include "select_mscdlg.h"

select_mscDlg::select_mscDlg(QWidget *parent) :
    QDialog(parent)
{
    mscidlabel = new QLabel;
    mscidlabel->setText(tr("请输入MSCID"));
    mscid = new QLineEdit;

    okBtn = new QPushButton;
    okBtn->setText(tr("查询"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(mscidlabel, 0, 0);
    layout1->addWidget(mscid, 0, 1);

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
    setWindowTitle(tr("查询MSC"));
    mscid->setFocus();
}

#define SELECTMSC1 "select mscid, mscpc 基站控制器点码, mscname 基站控制器名称, districtname 区域名称, DATE_FORMAT(createdate, '%Y-%m-%d') 建立时间, description 描述 from mscs"
#define SELECTMSC2 "select mscid, mscpc 基站控制器点码, mscname 基站控制器名称, districtname 区域名称, DATE_FORMAT(createdate, '%Y-%m-%d') 建立时间, description 描述 from mscs where mscid = %1"

void select_mscDlg::okBtnOnclick()
{
    isok = true;

    if (mscid->text().trimmed().isEmpty())
    {
        SQL = SELECTMSC1;
    }else
    {
        SQL = QString(SELECTMSC2).arg(mscid->text());
    }
    close();
}

void select_mscDlg::cancelBtnOnclick()
{
    close();
}


