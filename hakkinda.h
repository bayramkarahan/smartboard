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

class Hakkinda : public QWidget
{
    Q_OBJECT
public:
    explicit Hakkinda(int w, int h, QWidget *parent = nullptr);

protected slots:


protected:

signals:
    void hakkindaCloseSignal();

private:

};
#endif // HAKKINDA_H
