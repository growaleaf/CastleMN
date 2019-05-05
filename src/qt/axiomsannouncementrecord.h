#ifndef AXIOMSANNOUNCEMENTRECORD_H
#define AXIOMSANNOUNCEMENTRECORD_H

#include <QWidget>


class AxiomsAnnouncement{

public:
    QPixmap image;
    QString title;
    QString info;
    QString imageURL;
    int height;
    QString link;
};


namespace Ui {
class AxiomsAnnouncementRecord;
}


class AxiomsAnnouncementRecord : public QWidget
{
    Q_OBJECT

public:
    explicit AxiomsAnnouncementRecord(QWidget *parent = 0);
    ~AxiomsAnnouncementRecord();
    void setData(AxiomsAnnouncement a);
    QSize getSize();
    QSize sizeHint() const;

private slots:
    void on_linkButton_clicked();

private:
    Ui::AxiomsAnnouncementRecord *ui;
};

#endif // AXIOMSANNOUNCEMENTRECORD_H
