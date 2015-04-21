#include <QMessageBox>
#include <QTableView>
#include <QStandardItemModel>
#include <QWidget>
#include <QMdiSubWindow>
#include <QInputDialog>
#include <QPalette>

#include "mainwindow.h"
#include "logindlg.h"
#include "scriptdlg.h"
#include "insert_celldlg.h"
#include "insert_bscdlg.h"
#include "insert_mscdlg.h"
#include "delete_celldlg.h"
#include "delete_bscdlg.h"
#include "delete_mscdlg.h"
#include "select_celldlg.h"
#include "select_bscdlg.h"
#include "select_mscdlg.h"
#include "update_celldlg.h"
#include "update_bscdlg.h"
#include "update_mscdlg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("CDMA无线基站管理系统"));//设置窗口标题
    setWindowIcon(QIcon("main.png"));//设置窗口光标
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);//设置窗口中央控件为mdiArea
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);//设置自动具有横向滚动条
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//设置自动具有纵向滚动条

    createActions();//建立行为的函数
    createMunus();//建立菜单的函数

    //设置主窗口背景颜色或图片
    mdiArea->setBackground(Qt::NoBrush);
    mdiArea->setStyleSheet("background-image: url(1.jpg);");//背景设置为1.jpt，子窗口大小不可调整
    //mdiArea->setStyleSheet("background-color:blue;");//背景设置为蓝色
    //mdiArea->setStyleSheet("border-image: url(1.jpg);");//背景设置为1.jpt，同时子窗口大小可调整

}

MainWindow::~MainWindow()
{

}

void MainWindow::createMunus()
{
    adminMenu = menuBar()->addMenu(tr("管理"));//建立管理菜单
    adminMenu->addAction(loginAction);//在管理菜单下加入登录行为
    adminMenu->addAction(logoutAction);//在管理菜单下加入注销行为
    adminMenu->addSeparator();//在管理菜单下加入一个分隔符
    adminMenu->addAction(exitAction);//在管理菜单下加入退出
    dataMenu = menuBar()->addMenu(tr("数据"));//建立数据菜单
    dataMenu->addAction(insert_cellAction);//在数据菜单下加入添加基站行为
    dataMenu->addAction(insert_bscAction);//在数据菜单下加入添加基站控制器行为
    dataMenu->addAction(insert_mscAction);//在数据菜单下加入添加MSC行为
    dataMenu->addAction(delete_cellAction);//在数据菜单下加入删除基站行为
    dataMenu->addAction(delete_bscAction);//在数据菜单下加入删除基站控制器行为
    dataMenu->addAction(delete_mscAction);//在数据菜单下加入删除MSC行为
    dataMenu->addAction(select_cellAction);//在数据菜单下加入查询基站行为
    dataMenu->addAction(select_bscAction);//在数据菜单下加入查询基站控制器行为
    dataMenu->addAction(select_mscAction);//在数据菜单下加入查询MSC行为
    dataMenu->addAction(update_cellAction);//在数据菜单下加入修改基站行为
    dataMenu->addAction(update_bscAction);//在数据菜单下加入修改基站控制器行为
    dataMenu->addAction(update_mscAction);//在数据菜单下加入修改MSC行为

    dataMenu->addSeparator();//在数据菜单下加入分隔符
    dataMenu->addAction(scriptAction);//在数据菜单下加入执行SQL脚本行为
    windowMenu = menuBar()->addMenu(tr("窗口"));//建立窗口菜单
    windowMenu->addAction(cascadeAction);//在窗口菜单下加入并列子窗口行为
    windowMenu->addAction(tileAction);//在窗口菜单下加入层叠子窗口行为
    helpMenu = menuBar()->addMenu(tr("帮助"));//建立帮助菜单
    helpMenu->addAction(helpAction);//在帮助菜单下建立帮助行为
    helpMenu->addSeparator();//在帮助菜单下加入一个分隔符
    helpMenu->addAction(aboutAction);//在帮助菜单下加入关于行为
}

void MainWindow::createActions()
{
    loginAction = new QAction(tr("登录"), this);
    loginAction->setShortcut(tr("Ctrl+u"));
    connect(loginAction, SIGNAL(triggered()), this, SLOT(on_login()));

    logoutAction = new QAction(tr("注销"), this);
    logoutAction->setShortcut(tr("Ctrl+b"));
    connect(logoutAction, SIGNAL(triggered()), this, SLOT(on_logout()));

    exitAction = new QAction(tr("退出"), this);
    exitAction->setShortcut(tr("Ctrl+w"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_exit()));

    insert_cellAction = new QAction(tr("添加基站"), this);
    insert_cellAction->setShortcut(tr("Ctrl+d"));
    insert_cellAction->setEnabled(false);
    connect(insert_cellAction, SIGNAL(triggered()), this, SLOT(on_insert_cell()));

    insert_bscAction = new QAction(tr("添加基站控制器"), this);
    insert_bscAction->setShortcut(tr("Ctrl+e"));
    insert_bscAction->setEnabled(false);
    connect(insert_bscAction, SIGNAL(triggered()), this, SLOT(on_insert_bsc()));
    insert_mscAction = new QAction(tr("添加MSC"), this);
    insert_mscAction->setShortcut(tr("Ctrl+f"));
    insert_mscAction->setEnabled(false);
    connect(insert_mscAction, SIGNAL(triggered()), this, SLOT(on_insert_msc()));

    delete_cellAction = new QAction(tr("删除基站"), this);
    delete_cellAction->setShortcut(tr("Ctrl+g"));
    delete_cellAction->setEnabled(false);
    connect(delete_cellAction, SIGNAL(triggered()), this, SLOT(on_delete_cell()));

    delete_bscAction = new QAction(tr("删除基站控制器"), this);
    delete_bscAction->setShortcut(tr("Ctrl+h"));
    delete_bscAction->setEnabled(false);
    connect(delete_bscAction, SIGNAL(triggered()), this, SLOT(on_delete_bsc()));
    delete_mscAction = new QAction(tr("删除MSC"), this);
    delete_mscAction->setShortcut(tr("Ctrl+i"));
    delete_mscAction->setEnabled(false);
    connect(delete_mscAction, SIGNAL(triggered()), this, SLOT(on_delete_msc()));

    select_cellAction = new QAction(tr("查询基站"), this);
    select_cellAction->setShortcut(tr("Ctrl+j"));
    select_cellAction->setEnabled(false);
    connect(select_cellAction, SIGNAL(triggered()), this, SLOT(on_select_cell()));

    select_bscAction = new QAction(tr("查询基站控制器"), this);
    select_bscAction->setShortcut(tr("Ctrl+k"));
    select_bscAction->setEnabled(false);
    connect(select_bscAction, SIGNAL(triggered()), this, SLOT(on_select_bsc()));

    select_mscAction = new QAction(tr("查询MSC"), this);
    select_mscAction->setShortcut(tr("Ctrl+l"));
    select_mscAction->setEnabled(false);
    connect(select_mscAction, SIGNAL(triggered()), this, SLOT(on_select_msc()));

    update_cellAction = new QAction(tr("修改基站"), this);
    update_cellAction->setShortcut(tr("Ctrl+m"));
    update_cellAction->setEnabled(false);
    connect(update_cellAction, SIGNAL(triggered()), this, SLOT(on_update_cell()));

    update_bscAction = new QAction(tr("修改基站控制器"), this);
    update_bscAction->setShortcut(tr("Ctrl+n"));
    update_bscAction->setEnabled(false);
    connect(update_bscAction, SIGNAL(triggered()), this, SLOT(on_update_bsc()));

    update_mscAction = new QAction(tr("修改MSC"), this);
    update_mscAction->setShortcut(tr("Ctrl+o"));
    update_mscAction->setEnabled(false);
    connect(update_mscAction, SIGNAL(triggered()), this, SLOT(on_update_msc()));

    scriptAction = new QAction(tr("执行脚本"), this);
    scriptAction->setShortcut(tr("Ctrl+p"));
    scriptAction->setEnabled(false);
    connect(scriptAction, SIGNAL(triggered()), this, SLOT(on_script()));

    cascadeAction = new QAction(tr("层叠窗口"), this);
    cascadeAction->setShortcut(tr("Ctrl+q"));
    connect(cascadeAction, SIGNAL(triggered()), this, SLOT(cascadeSubWindows()));

    tileAction = new QAction(tr("并列窗口"), this);
    tileAction->setShortcut(tr("Ctrl+r"));
    connect(tileAction, SIGNAL(triggered()), this, SLOT(tileSubWindows()));

    helpAction = new QAction(tr("帮助"), this);
    helpAction->setShortcut(tr("Ctrl+s"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(on_help()));

    aboutAction = new QAction(tr("关于"), this);
    aboutAction->setShortcut(tr("Ctrl+t"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(on_about()));
}

void MainWindow::on_login()
{
    //-------------弹出登录对话框------------------------------
    loginDlg login(this);
    login.exec();//以模式状态显示login对话框

    if(login.islogin)//登录对话框中用户点击登录按钮
    {
        if (db.sql_connect(login.hostip.toStdString().data(),
                           login.userid.toStdString().data(),
                           login.passwd.toStdString().data(),
                           login.dbname.toStdString().data()) == 0)
        {
            QMessageBox::information(this, tr("提示"), tr("成功登录"));
            scriptAction->setEnabled(true);//设置行为菜单状态为可用
            insert_cellAction->setEnabled(true);
            insert_bscAction->setEnabled(true);
            insert_mscAction->setEnabled(true);
            delete_cellAction->setEnabled(true);
            delete_bscAction->setEnabled(true);
            delete_mscAction->setEnabled(true);
            select_cellAction->setEnabled(true);
            select_bscAction->setEnabled(true);
            select_mscAction->setEnabled(true);
            update_cellAction->setEnabled(true);
            update_bscAction->setEnabled(true);
            update_mscAction->setEnabled(true);
            db.sql_exec("set names utf8");//设置数据库连接为uft8字符集
        }else
        {
            QMessageBox::information(this, "错误", db.get_error());//如果错误，弹出错误窗口
        }
    }
}

void MainWindow::on_logout()
{

    scriptAction->setEnabled(false);//设置行为不可用
    insert_cellAction->setEnabled(false);
    insert_bscAction->setEnabled(false);
    insert_mscAction->setEnabled(false);
    delete_cellAction->setEnabled(false);
    delete_bscAction->setEnabled(false);
    delete_mscAction->setEnabled(false);
    select_cellAction->setEnabled(false);
    select_bscAction->setEnabled(false);
    select_mscAction->setEnabled(false);
    update_cellAction->setEnabled(false);
    update_bscAction->setEnabled(false);
    update_mscAction->setEnabled(false);

}

void MainWindow::on_exit()
{
    close();//关闭主窗口
}


void MainWindow::on_script()
{  
    //-------------弹出执行脚本对话框------------------------------
    scriptDlg script(this);
    script.exec();//以模式状态显示执行脚本对话框

    if(script.isok)//执行脚本对话框中用户点击执行按钮
    {
        script_Msg(script.SQL.trimmed());
    }
}

void MainWindow::on_about()
{
    QMessageBox::about(this, tr("关于数据管理系统"), tr("中国电信CDMA无线基站管理系统\n\n\n作者：花澍\n2014版权所有"));
}



void MainWindow::closeEvent(QCloseEvent *event)//窗口在close前，系统自动调用closeEvent函数
{
    QMessageBox::StandardButton button = QMessageBox::question(this, tr("退出程序"),
                                                               QString(tr("是否退出?")),
                                                               QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
    {
        event->accept();  //接受退出信号，程序退出
    }
    else
    {
        event->ignore();  //忽略退出信号，程序继续运行
    }
}

//执行SQL语句，将执行返回值放入QStandardItemModel，通过QTableView显示出来
void MainWindow::script_Msg(QString SQL)
{
    const char *src = SQL.toStdString().data();
    if ((strncmp(src, "select", 6) == 0) || (strncmp(src, "SELECT", 6) == 0)
            || (strncmp(src, "show", 4) == 0) || (strncmp(src, "SHOW", 4) == 0)
            || (strncmp(src, "desc", 4) == 0) || (strncmp(src, "DESC", 4) == 0))
     //如果src为有返回数据集SQL语句，那么调用sql_open函数
    {
        QStandardItemModel *p = NULL;
        if (db.sql_open(SQL.toStdString().data(), &p) == 0)
        {
            QTableView *view1 = new QTableView;
            view1->setAttribute(Qt::WA_DeleteOnClose);//设置在view1控件close的时候自动delete
            view1->setModel(p);//将model1与view1关联
            view1->setWindowIcon(windowIcon());//设置view1图标
            mdiArea->addSubWindow(view1);//将view1加入mdiArea，以便view1可以成为子窗口
            view1->setWindowTitle(tr("查询结果显示窗口"));
            view1->setStyleSheet("border-image: url(3.jpg);");//设置view1背景图片
            view1->show();//将view1显示到屏幕
            mdiArea->activeSubWindow()->resize(width() - 100, height() - 100);//设置view1窗口的大小
        }else
        {
            QMessageBox::information(this, tr("错误"), db.get_error());
        }
    } else//如果为没有有返回数据集SQL语句，那么调用exec_db函数
    {
        if (db.sql_exec(SQL.toStdString().data()) == 0)
        {
            QMessageBox::information(this, tr("提示"), tr("成功"));
        }else
        {
            QMessageBox::information(this, tr("错误"), db.get_error());
        }
    }
}

void MainWindow::cascadeSubWindows()
{
    mdiArea->cascadeSubWindows();//并列子窗口
}

void MainWindow::tileSubWindows()
{
    mdiArea->tileSubWindows();//层叠子窗口
}

void MainWindow::on_help()
{   

}

void MainWindow::on_insert_cell()
{
    //-------------弹出添加基站对话框------------------------------
    insert_cellDlg insert_cell(this);
    insert_cell.resize(400, 200);
    insert_cell.exec();

    if(insert_cell.isok)//如果用户点击确定按钮
    {
        script_Msg(insert_cell.SQL.trimmed());
    }
}

void MainWindow::on_insert_bsc()
{
    //-------------弹出添加基站对话框------------------------------
    insert_bscDlg insert_bsc(this);
    insert_bsc.resize(400, 200);
    insert_bsc.exec();

    if(insert_bsc.isok)//如果用户点击确定按钮
    {
        script_Msg(insert_bsc.SQL.trimmed());
    }
}

void MainWindow::on_insert_msc()
{
    //-------------弹出添加MSC对话框------------------------------
    insert_mscDlg insert_msc(this);
    insert_msc.resize(400, 200);
    insert_msc.exec();

    if(insert_msc.isok)//如果用户点击确定按钮
    {
        script_Msg(insert_msc.SQL.trimmed());
    }
}

void MainWindow::on_delete_cell()
{
    //-------------弹出删除cell对话框------------------------------
    delete_cellDlg delete_cell(this);
    delete_cell.resize(400, 200);
    delete_cell.exec();

    if(delete_cell.isok)//如果用户点击确定按钮
    {
        script_Msg(delete_cell.SQL.trimmed());
    }
}

void MainWindow::on_delete_bsc()
{
    //-------------弹出删除MSC对话框------------------------------
    delete_bscDlg delete_bsc(this);
    delete_bsc.resize(400, 200);
    delete_bsc.exec();

    if(delete_bsc.isok)//如果用户点击确定按钮
    {
        script_Msg(delete_bsc.SQL.trimmed());
    }
}

void MainWindow::on_delete_msc()
{
    //-------------弹出删除MSC对话框------------------------------
    delete_mscDlg delete_msc(this);
    delete_msc.resize(400, 200);
    delete_msc.exec();

    if(delete_msc.isok)//如果用户点击确定按钮
    {
        script_Msg(delete_msc.SQL.trimmed());
    }
}

void MainWindow::on_select_cell()
{
    //-------------弹出查询cell对话框------------------------------
    select_cellDlg select_cell(this);
    select_cell.resize(400, 200);
    select_cell.exec();

    if(select_cell.isok)//如果用户点击确定按钮
    {
        script_Msg(select_cell.SQL.trimmed());
    }
}

void MainWindow::on_select_bsc()
{
    //-------------弹出查询基站控制器对话框------------------------------
    select_bscDlg select_bsc(this);
    select_bsc.resize(400, 200);
    select_bsc.exec();

    if(select_bsc.isok)//如果用户点击确定按钮
    {
        script_Msg(select_bsc.SQL.trimmed());
    }
}

void MainWindow::on_select_msc()
{
    //-------------弹出查询MSC对话框------------------------------
    select_mscDlg select_msc(this);
    select_msc.resize(400, 200);
    select_msc.exec();

    if(select_msc.isok)//如果用户点击确定按钮
    {
        script_Msg(select_msc.SQL.trimmed());
    }
}

void MainWindow::on_update_cell()
{
    //-------------弹出修改基站对话框------------------------------
    bool isok =  false;
    QString cellid = QInputDialog::getText(this, tr("输入"), tr("输入要修改的基站ID"), QLineEdit::Normal, tr(""), &isok);

    if(isok)
    {
        QString SQL = QString("select cellid, cellname, bscid, DATE_FORMAT(createdate, '%Y-%m-%d'), longitude, latitude, description from cells where cellid = %1").arg(cellid);
        QStringList list;
        db.sql_open_str(SQL.toStdString().data(), list);
        if (list.count() < 7)
        {
            QMessageBox::information(this, "错误", "没有此基站ID");
            return;
        }
        //-------------弹出修改对话框------------------------------

        update_cellDlg update_cell(list[0], list[1], list[2], list[3], list[4], list[5], list[6], this);
        update_cell.resize(400, 200);
        update_cell.exec();

        if(update_cell.isok)//如果用户点击确定按钮
        {
            script_Msg(update_cell.SQL.trimmed());
        }
    }
}

void MainWindow::on_update_bsc()
{
    //-------------弹出修改基站控制器对话框------------------------------
    bool isok =  false;
    QString bscid = QInputDialog::getText(this, tr("输入"), tr("输入要修改的基站控制器ID"), QLineEdit::Normal, tr(""), &isok);

    if(isok)
    {
        QString SQL = QString("select bscid, bscpc, bscname, mscid, branchname, DATE_FORMAT(createdate, '%Y-%m-%d'), description from bscs where bscid = %1").arg(bscid);
        QMessageBox::information(this, "list", SQL);

        QStringList list;
        db.sql_open_str(SQL.toStdString().data(), list);
        if (list.count() < 7)
        {
            QMessageBox::information(this, "错误", "没有此基站控制器ID");
            return;
        }
        //-------------弹出修改对话框------------------------------

        update_bscDlg update_bsc(list[0], list[1], list[2], list[3], list[4], list[5], list[6], this);
        update_bsc.resize(400, 200);
        update_bsc.exec();

        if(update_bsc.isok)//
        {
            script_Msg(update_bsc.SQL.trimmed());
        }
    }
}

void MainWindow::on_update_msc()
{
    //-------------弹出修改MSC对话框------------------------------
    bool isok =  false;
    QString mscid = QInputDialog::getText(this, tr("输入"), tr("输入要修改的MSCID"), QLineEdit::Normal, tr(""), &isok);

    if(isok)
    {
        QString SQL = QString("select mscid, mscpc, mscname, districtname, DATE_FORMAT(createdate, '%Y-%m-%d'), description from mscs where mscid = %1").arg(mscid);
        QStringList list;
        db.sql_open_str(SQL.toStdString().data(), list);
        if (list.count() < 6)
        {
            QMessageBox::information(this, "错误", "没有此MSCID");
            return;
        }
        //-------------弹出修改对话框------------------------------

        update_mscDlg update_msc(list[0], list[1], list[2], list[3], list[4], list[5], this);
        update_msc.resize(400, 200);
        update_msc.exec();

        if(update_msc.isok)//
        {
            script_Msg(update_msc.SQL.trimmed());
        }
    }
}
