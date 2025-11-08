#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H
#include "global.h"
#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
    void showTip(QString str, bool b_ok);
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
    void initHttpHandlers();

private slots:
    void on_get_code_clicked();
    void on_sure_btn_clicked();

private:
    Ui::RegisterDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;

};

#endif // REGISTERDIALOG_H
