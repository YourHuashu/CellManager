#ifndef SELECT_MSCDLG_H
#define SELECT_MSCDLG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

class select_mscDlg : public QDialog
{
    Q_OBJECT
public:
    explicit select_mscDlg(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *mscidlabel;
    QLineEdit *mscid;

    QPushButton *okBtn;
    QPushButton *cancelBtn;

private slots:
    void okBtnOnclick();
    void cancelBtnOnclick();

public:
    QString SQL;
    bool isok;

};

#endif // SELECT_MSCDLG_H
