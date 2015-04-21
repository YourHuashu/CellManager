#ifndef SCRIPTDLG_H
#define SCRIPTDLG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class scriptDlg : public QDialog
{
    Q_OBJECT
public:
    explicit scriptDlg(QWidget *parent = 0);

signals:

public slots:

private:

    QLabel *lable0;
    QTextEdit *textEditSQL;

    QPushButton *okBtn;
    QPushButton *cancelBtn;

private slots:
    void okBtnOnclick();
    void cancelBtnOnclick();

public:
    QString SQL;
    bool isok;

};

#endif // SCRIPTDLG_H
