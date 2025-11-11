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

    bool checkUserValid();
    bool checkPassValid();

    bool checkEmailValid();
    bool checkVarifyValid();
    // bool checkConfirmValid();

    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);

    void ChangeTipPage();

    void on_return_btn_clicked();

private:
    Ui::RegisterDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;
    QMap<TipErr, QString> _tip_errs;
    QTimer * _countdown_timer;
    int _countdown;


signals:
    void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
