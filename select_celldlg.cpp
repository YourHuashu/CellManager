#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDate>
#include "select_celldlg.h"

select_cellDlg::select_cellDlg(QWidget *parent) :
    QDialog(parent)
{
    cellidlabel = new QLabel;
    cellidlabel->setText(tr("请输入基站ID"));
    cellid = new QLineEdit;

    okBtn = new QPushButton;
    okBtn->setText(tr("查询"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(cellidlabel, 0, 0);
    layout1->addWidget(cellid, 0, 1);

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
    setWindowTitle(tr("查询基站ID"));
    cellid->setFocus();
}

#define SELECTCELL1 "select a.cellid, a.cellname cell名称, a.bscid, DATE_FORMAT(a.createdate, '%Y-%m-%d') 建立时间, a.longitude 经度, a.latitude 纬度, b.bscpc 基站控制器点码, b.bscname 基站控制器名称, b.branchname 支局名称, c.mscpc MSD点码, c.mscname MSC名称, c.districtname 区域名称, a.description 描述 from cells a, bscs b, mscs c where a.bscid = b.bscid and b.mscid = c.mscid"
#define SELECTCELL2 "select a.cellid, a.cellname cell名称, a.bscid, DATE_FORMAT(a.createdate, '%Y-%m-%d') 建立时间, a.longitude 经度, a.latitude 纬度, b.bscpc 基站控制器点码, b.bscname 基站控制器名称, b.branchname 支局名称, c.mscpc MSD点码, c.mscname MSC名称, c.districtname 区域名称, a.description 描述 from cells a, bscs b, mscs c where a.bscid = b.bscid and b.mscid = c.mscid and a.cellid = %1"


void select_cellDlg::okBtnOnclick()
{
    isok = true;

    if (cellid->text().trimmed().isEmpty())
    {
        SQL = SELECTCELL1;
    }else
    {
        SQL = QString(SELECTCELL2).arg(cellid->text());
    }
    close();
}

void select_cellDlg::cancelBtnOnclick()
{
    close();
}


