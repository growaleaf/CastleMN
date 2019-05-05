#include "axiomsannouncementview.h"
#include "ui_axiomsannouncementview.h"
#include <QMessageBox>
#include <QModelIndex>


AxiomsAnnouncementView::AxiomsAnnouncementView(QWidget *parent) :   QWidget(parent),
                                                        ui(new Ui::AxiomsAnnouncementView)
{
    ui->setupUi(this);
    ui->verticalLayout_3->setAlignment(Qt::AlignTop);
    lastUpdate = 0;
    ui->mainTitleLable->setText(tr("Castle Announcement"));
    ui->pushButton->setText(tr("Refresh"));
    //Load Announcement data
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("https://projectcastle.tech/json/axiom.sjon")));
}

AxiomsAnnouncementView::~AxiomsAnnouncementView()
{
    delete ui;
}

void AxiomsAnnouncementView::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();

    }
    else
    {

        QString json = reply->readAll();

        QJsonDocument jdoc = QJsonDocument::fromJson(json.toUtf8());
        if(jdoc.isNull()){
            reply->deleteLater();
            return;
        }

        QJsonObject response = jdoc.object();

        QString status = response["status"].toString();
        if(status.isEmpty() || (status != "ok") ){
            reply->deleteLater();
            return;
        }

        QJsonArray jsonANNs = response["data"].toArray();
        annList.clear();
        annNumber = 0;

        foreach(QJsonValue obj, jsonANNs){
            QJsonObject ann = obj.toObject();
            AxiomsAnnouncement a;
            a.title = ann["title"].toString();
            a.info = ann["info"].toString();
            a.imageURL = ann["url"].toString();
            a.link =ann["link"].toString();
            annList << a;
        }

        if(annList.isEmpty()){
            reply->deleteLater();
            return;
        }
        int time = response["time"].toInt();
        if(time > lastUpdate){

            lastUpdate = time;

            QLayoutItem *child;
            while ((child = ui->verticalLayout->takeAt(0)) != 0) {
                delete child->widget();
                delete child;
            }

            QNetworkAccessManager *manager = new QNetworkAccessManager(this);
            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinishedImage(QNetworkReply*)));

            manager->get(QNetworkRequest(QUrl(annList[0].imageURL)));
        }else{
             ui->pushButton->setEnabled(true);
        }


    }
    reply->deleteLater();
}

void AxiomsAnnouncementView::replyFinishedImage(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();

    }
    else
    {
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;

        pixmap.loadFromData(jpegData);
        if (!pixmap.isNull())
        {
            annList[annNumber].image = pixmap;
            AxiomsAnnouncementRecord *ann_item = new AxiomsAnnouncementRecord(this);
            annList[annNumber].height = ann_item->getSize().height();
            ann_item->setData(annList[annNumber]);

            ui->verticalLayout->addWidget(ann_item);

            annNumber++;
            if(annNumber <= annList.size() -1){
                QNetworkAccessManager *manager = new QNetworkAccessManager(this);
                connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinishedImage(QNetworkReply*)));

                manager->get(QNetworkRequest(QUrl(annList[annNumber].imageURL)));
            }else{
                ui->pushButton->setEnabled(true);
            }
        }



    }
    reply->deleteLater();
}

void AxiomsAnnouncementView::on_pushButton_clicked()
{
    annList.clear();
    annNumber=0;


    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("https://projectcastle.tech/json/axiom.sjon")));
    ui->pushButton->setEnabled(false);
}
