#ifndef TOOLSAYAC_H
#define TOOLSAYAC_H

#include <QWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>
#include<QProgressBar>
#include<QTimer>
#include<QTime>
#include<QDebug>
#include<tooltahta.h>
#include<QSlider>
#include <QApplication>
#include<QPoint>
class toolSayac : public QWidget
{
    Q_OBJECT
public:
    explicit toolSayac(int w, int h, QWidget *parent = nullptr);
    QSlider *sure;
protected slots:
    void saatslot();
    void setSure(int value);
    void paintEvent(QPaintEvent *pe) override;
protected:
    bool mouseClickState;
    QPoint oldPos;
    QLabel *baslik;
    void mousePressEvent(QMouseEvent *event)Q_DECL_OVERRIDE
    {
        if (QLabel *w =(QLabel*) qApp->widgetAt(QCursor::pos())) {
            if(w->objectName()=="baslik")
            {
                mouseClickState=true;
                oldPos = event->globalPos();
                //qDebug()<<"press"<<mouseClickState;
            }
        }
    }
    void mouseMoveEvent(QMouseEvent *event)Q_DECL_OVERRIDE
    {
        // qDebug()<<"move"<<mouseClickState;
        if(mouseClickState)
        {
            /// qDebug()<<"başlıktan tutup sürükleniyor";
            const QPoint delta = event->globalPos() - oldPos;
            move(x()+delta.x(), y()+delta.y());
            oldPos = event->globalPos();
        }
    }
    void mouseReleaseEvent(QMouseEvent *event)Q_DECL_OVERRIDE
    {

        mouseClickState=false;
        //  qDebug()<<"release"<<mouseClickState;
    }

signals:
    void sayacCloseSignal();

private:
    QLabel *suresayacLabel;
    int suresayac=30;
    QProgressBar *bar;
    QLabel  *sayac;
    qint64 saniye;
};

#endif // TOOLSAYAC_H
