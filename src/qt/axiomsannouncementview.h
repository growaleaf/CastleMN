#ifndef AXIOMSANNOUNCEMENTVIEW_H
#define AXIOMSANNOUNCEMENTVIEW_H

#include <QWidget>
#include "axiomsannouncementrecord.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QListWidget>
#include <QListWidgetItem>



namespace Ui {
class AxiomsAnnouncementView;
}

class AxiomsAnnouncementView : public QWidget
{
    Q_OBJECT

public:
    explicit AxiomsAnnouncementView(QWidget *parent = 0);
    ~AxiomsAnnouncementView();

private:
    int lastUpdate=0;
    Ui::AxiomsAnnouncementView *ui;
    QList<AxiomsAnnouncement> annList;
    int annNumber = 0;
private slots:
    void replyFinished (QNetworkReply *reply);
    void replyFinishedImage (QNetworkReply *reply);
    void on_pushButton_clicked();
};

#endif // AXIOMSANNOUNCEMENTVIEW_H
