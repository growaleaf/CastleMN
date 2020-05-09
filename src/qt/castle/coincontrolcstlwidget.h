// Copyright (c) 2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLCSTLWIDGET_H
#define COINCONTROLCSTLWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlCstlWidget;
}

class CoinControlCstlWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlCstlWidget(QWidget *parent = nullptr);
    ~CoinControlCstlWidget();

private:
    Ui::CoinControlCstlWidget *ui;
};

#endif // COINCONTROLCSTLWIDGET_H
