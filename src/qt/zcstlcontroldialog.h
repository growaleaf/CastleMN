// Copyright (c) 2017-35801 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCSTLCONTROLDIALOG_H
#define ZCSTLCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcstl/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZCstlControlDialog;
}

class CZCstlControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZCstlControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZCstlControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZCstlControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZCstlControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZCstlControlDialog(QWidget *parent);
    ~ZCstlControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZCstlControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZCstlControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZCSTLCONTROLDIALOG_H
