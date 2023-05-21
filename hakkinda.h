#ifndef HAKKINDA_H
#define HAKKINDA_H
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
#include<QTextEdit>
#include<QEventLoop>
#include<QColorDialog>
#include<QFontDialog>
#include <QApplication>
#include<QPoint>

class Hakkinda : public QWidget
{
    Q_OBJECT
public:
    explicit Hakkinda(int w, int h, QWidget *parent = nullptr);


protected slots:


protected:
    void paintEvent(QPaintEvent *pe)
    {
      QStyleOption o;
      o.initFrom(this);
      QPainter p(this);
      style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    }
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
                qDebug()<<"press"<<mouseClickState;
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
    void hakkindaCloseSignal();

private:

};
#endif // HAKKINDA_H
