#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include <QDialog>

namespace Ui {
class msgdialog;
}

class MsgDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MsgDialog(const QString& messaggio, QWidget *parent = 0);
    ~MsgDialog();

private:
    Ui::msgdialog *ui;
};

#endif // MSGDIALOG_H
