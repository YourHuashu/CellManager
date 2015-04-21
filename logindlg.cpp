#include <QGridLayout>
#include <QMessageBox>
#include "logindlg.h"

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent)
{
    lable0 = new QLabel;
    lable0->setText(tr("用户ID"));
    lineEditUserID = new QLineEdit;

    lable1 = new QLabel;
    lable1->setText(tr("密码"));
    lineEditPasswd = new QLineEdit;
    lineEditPasswd->setEchoMode(QLineEdit::Password);//设置为密码框


    lable2 = new QLabel;
    lable2->setText(tr("数据库名称"));
    lineEditDBName = new QLineEdit;


    lable3 = new QLabel;
    lable3->setText(tr("服务器IP"));
    lineEditHostIP = new QLineEdit;



    loginBtn = new QPushButton;
    loginBtn->setText(tr("登录"));
    logoutBtn = new QPushButton;
    logoutBtn->setText(tr("取消"));


    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(lable0, 0, 0);
    layout1->addWidget(lineEditUserID, 0, 1);

    layout1->addWidget(lable1, 1, 0);
    layout1->addWidget(lineEditPasswd, 1, 1);

    layout1->addWidget(lable2, 2, 0);
    layout1->addWidget(lineEditDBName, 2, 1);

    layout1->addWidget(lable3, 3, 0);
    layout1->addWidget(lineEditHostIP, 3, 1);


    layout1->addWidget(loginBtn, 4, 0);
    layout1->addWidget(logoutBtn, 4, 1);

    layout1->setColumnStretch(0, 1);
    layout1->setColumnStretch(1, 1);

    layout1->setMargin(15);//设置边距
    layout1->setSpacing(10);//设置控件间的间隔
    layout1->setSizeConstraint(QLayout::SetFixedSize);//设置layout为最合适大小

    connect(loginBtn,SIGNAL(clicked()), this, SLOT(loginBtnOnclick()));
    connect(logoutBtn,SIGNAL(clicked()), this, SLOT(logoutBtnOnclick()));

    islogin = false;
    setWindowIcon(QIcon("main.png"));//设置窗口光标
    setWindowTitle(tr("登录"));//设置窗口标题
    //setWindowFlags(windowFlags() | Qt::Tool);//设置不在任务栏出现
    lineEditUserID->setFocus();//设置lineEditUserID控件具有输入焦点

    //设置对话框背景颜色或图片
    setAutoFillBackground(true);
    QPalette palette;
    //palette.setColor(QPalette::Background, QColor(Qt::blue));
    palette.setBrush(QPalette::Background, QBrush(QPixmap("2.jpg")));
    setPalette(palette);
}

void loginDlg::loginBtnOnclick()
{
    islogin = true;
    userid = lineEditUserID->text();
    passwd = lineEditPasswd->text();
    dbname = lineEditDBName->text();
    hostip = lineEditHostIP->text();
    close();
}

void loginDlg::logoutBtnOnclick()
{
    close();
}


