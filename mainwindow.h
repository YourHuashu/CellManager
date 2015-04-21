#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMdiArea>
#include <QCloseEvent>
#include "mymysql.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

    void createMunus();
    void createActions();
private:
    mymysql db;
    QString userid;
    QString passwd;
    QString dbname;
    QMdiArea *mdiArea;
    QMenu *adminMenu;
    QMenu *dataMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;
    QAction *loginAction;
    QAction *logoutAction;
    QAction *exitAction;


    QAction *insert_cellAction;
    QAction *insert_bscAction;
    QAction *insert_mscAction;
    QAction *delete_cellAction;
    QAction *delete_bscAction;
    QAction *delete_mscAction;
    QAction *select_cellAction;
    QAction *select_bscAction;
    QAction *select_mscAction;
    QAction *update_cellAction;
    QAction *update_bscAction;
    QAction *update_mscAction;

    QAction *scriptAction;

    QAction *cascadeAction;
    QAction *tileAction;
    QAction *helpAction;
    QAction *aboutAction;


    void script_Msg(QString SQL);//发送SQL消息


private slots:
    void on_login();
    void on_logout();
    void on_exit();

    void on_insert_cell();
    void on_insert_bsc();
    void on_insert_msc();

    void on_delete_cell();
    void on_delete_bsc();
    void on_delete_msc();

    void on_select_cell();
    void on_select_bsc();
    void on_select_msc();

    void on_update_cell();
    void on_update_bsc();
    void on_update_msc();

    void on_script();    

    void on_help();
    void on_about();

    void cascadeSubWindows();
    void tileSubWindows();
};

#endif // MAINWINDOW_H
