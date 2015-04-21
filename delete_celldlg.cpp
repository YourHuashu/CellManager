#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDate>
#include "delete_celldlg.h"

delete_cellDlg::delete_cellDlg(QWidget *parent) :
    QDialog(parent)
{
    cellidlabel = new QLabel;
    cellidlabel->setText(tr("请输入要删除的基站编号"));
    cellid = new QLineEdit;

    okBtn = new QPushButton;
    okBtn->setText(tr("删除"));
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
    setWindowTitle(tr("删除基站"));
    cellid->setFocus();
}



#define DELETECELL "delete from cells where cellid = %1"


void delete_cellDlg::okBtnOnclick()
{
    if (cellid->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr("错误"), tr("基站编号不能为空"));
        cellid->setFocus();
        return ;
    }

    isok = true;
    SQL = QString(DELETECELL).arg(cellid->text());
    close();

}

void delete_cellDlg::cancelBtnOnclick()
{
    close();
}


