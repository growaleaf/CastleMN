#include "axiomsannouncementrecord.h"
#include "ui_axiomsannouncementrecord.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

AxiomsAnnouncementRecord::AxiomsAnnouncementRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AxiomsAnnouncementRecord)
{
    ui->setupUi(this);
    ui->titleLabel->setText("ann.title");
    ui->infoLabel->setText("ann.info");
    ui->verticalLayout_2->setAlignment(Qt::AlignTop);
}

void AxiomsAnnouncementRecord::setData(AxiomsAnnouncement a){

    ui->titleLabel->setText(a.title);
    ui->infoLabel->setText(a.info);
    ui->linkButton->setText(a.link);

    ui->imageLabel->clear();
    ui->imageLabel->setPixmap(a.image);
    ui->imageLabel->setScaledContents(true);

}

QSize AxiomsAnnouncementRecord::getSize(){

    //int height = ui->titleLabel->height() + ui->infoLabel->height() + 18;

    int height = ui->verticalLayout->sizeHint().height() + 6;
    if(height<75) height=75;
    int width = ui->titleLabel->height() + ui->imageLabel->height() + 12;
    return QSize(width, height);

}
QSize AxiomsAnnouncementRecord::sizeHint() const  {
    int height = ui->verticalLayout->sizeHint().height() + 6;
    if(height<80) height=80;
    int width = ui->titleLabel->height() + ui->imageLabel->height() + 12;
    return QSize(width, height);
}


AxiomsAnnouncementRecord::~AxiomsAnnouncementRecord()
{
    delete ui;
}

void AxiomsAnnouncementRecord::on_linkButton_clicked()
{
    QDesktopServices::openUrl ( QUrl(  ui->linkButton->text()) );
}
