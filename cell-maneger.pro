
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cell-maneger
TEMPLATE = app

#windows使用下面指令
LIBS += -LC:\mysql\lib -llibmysql
#linux使用下面指令
#LIBS += -lmysqlclient


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    scriptdlg.cpp \
    mymysql.cpp \
    insert_celldlg.cpp \
    insert_bscdlg.cpp \
    insert_mscdlg.cpp \
    delete_celldlg.cpp \
    delete_bscdlg.cpp \
    delete_mscdlg.cpp \
    select_celldlg.cpp \
    select_bscdlg.cpp \
    select_mscdlg.cpp \
    update_celldlg.cpp \
    update_bscdlg.cpp \
    update_mscdlg.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    scriptdlg.h \
    mymysql.h \
    insert_celldlg.h \
    insert_bscdlg.h \
    insert_mscdlg.h \
    delete_celldlg.h \
    delete_bscdlg.h \
    delete_mscdlg.h \
    select_celldlg.h \
    select_bscdlg.h \
    select_mscdlg.h \
    update_celldlg.h \
    update_bscdlg.h \
    update_mscdlg.h
