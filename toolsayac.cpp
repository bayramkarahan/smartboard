#include "toolsayac.h"

toolSayac::toolSayac(int w, int h, QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(w,h);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
   // setWindowFlags(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_StaticContents);
   // setAttribute(Qt::WA_TranslucentBackground, true);
   // this->setAttribute(Qt::WA_NoSystemBackground, false);
    QGridLayout *mainlayout = new QGridLayout(this);
       mainlayout->setAlignment(Qt::AlignCenter);
      // mainlayout->setRowStretch(2,1);
      // mainlayout->setColumnStretch(2,1);
         // mainlayout->setContentsMargins(5,5,5,5);
        //  mainlayout->setHorizontalSpacing(5);
         // mainlayout->setVerticalSpacing(5);
            mainlayout->setMargin(0);
         //    mainlayout->setSpacing(5);
     /*  mainlayout->addWidget(menu);
       menu->setFixedSize(QSize(w,h));
       */
            setObjectName("sayac");
                   setStyleSheet("QWidget#sayac{"
                            "border: 2px solid rgb(53, 132, 228);"
                              "border-radius: 5px;"
                              "background-color:rgba(250,250,250,255);"
                            "}");


    int en=w/20;
    int boy=h/20;
    /************************************************************************/
        QPainterPath path;
        path.addRoundedRect(this->rect(), 5,5);//border-radius value:5 refer
        this->setMask(path.toFillPolygon().toPolygon());

        baslik=new QLabel(this);
        baslik->setText("Sınav Sayacı");
        baslik->setObjectName("baslik");
        baslik->setFixedSize(this->width()-4,boy);
        baslik->move(2,2);
        baslik->setAlignment(Qt::AlignCenter);
        int fnt=10;
        baslik->setStyleSheet("font-size:"+QString::number(fnt)+"px; border: 0.5px solid rgba(230, 220, 230,100);"
                              "border-radius: 5px;"
                                                                "background: rgba(0, 0, 0,30);");
                              //"background: qradialgradient(cx:0.5, cy:0.5, radius: 2.5,"
                              //"fx:0.5, fy:0.5, stop:0 white, stop:1 gray);");
    /************************************************************************/

    //qDebug()<<en<<boy;
    QTimer  *saat = new QTimer(this);
    connect(saat, SIGNAL(timeout()), this, SLOT(saatslot()));
    bar=new QProgressBar(this);
    bar->setFixedSize(this->width()*0.7, boy*3);
    bar->move(this->width()*0.15,boy*3);
    bar->show();
    suresayacLabel=new QLabel(this);
    suresayacLabel->setFixedSize(this->width()*0.1, boy*2);
    suresayacLabel->move(this->width()/2-suresayacLabel->width()/2,boy);

    suresayacLabel->show();
    QWidget *butongrub=new QWidget(this);
    butongrub->setFixedSize(en*4, boy*2.5);
    butongrub->move(this->width()/2-butongrub->width()/2,this->height()-butongrub->height()*2);
    QPushButton *sayacStopButton= new QPushButton(butongrub);
    QPushButton *sayacStartButton= new QPushButton(butongrub);
    sayacStartButton->hide();
    sayacStartButton->setFixedSize(en*2, boy*2);
    sayacStartButton->setIconSize(QSize(en*2,boy*2));
    sayacStartButton->setFlat(true);
    sayacStartButton->setIcon(QIcon(":icons/startsayac.svg"));
   // sayacStartButton->move(this->width()*0.5,this->height()-sayacStartButton->height()*2);
    sayacStartButton->move(0,5);

    sayacStartButton->show();

    connect(sayacStartButton, &QPushButton::clicked, [=]() {
        saniye=0;
        saat->start(1000);
        //delete sure;
        sure->hide();
        sayacStartButton->setEnabled(false);
        sayacStopButton->setEnabled(true);
       // bar->hide();

        bar->setMaximum(sure->value()*60);
});



     sayacStopButton->hide();
     sayacStopButton->setFixedSize(en*2, boy*2);
     sayacStopButton->setIconSize(QSize(en*2,boy*2));
     sayacStopButton->setFlat(true);
     sayacStopButton->setIcon(QIcon(":icons/stopsayac.svg"));
     sayacStopButton->move(butongrub->width()-sayacStopButton->width()-boy/2,5);
     sayacStopButton->show();
     sayacStopButton->setEnabled(false);
     connect(sayacStopButton, &QPushButton::clicked, [=]() {
         saat->stop();
         sayac->show();
         sure->show();
         bar->show();
         sayacStartButton->show();
         sayacStopButton->show();
         sayacStartButton->setEnabled(true);
         sayacStopButton->setEnabled(false);

     });
       sayac=new QLabel(this);
            // kalemKalinlik();
            sayac->hide();
    //sure=new QSlider(this);
        sure= new QSlider(Qt::Horizontal,this);
    sure->setRange(1,150);
    sure->setSliderPosition(30);
    sure->setFixedSize(QSize(this->width()*0.7,boy*1));
    sure->move(this->width()/2-sure->width()/2,bar->pos().y()+bar->height()+boy/2);
    //sure->setValue(30);



    suresayacLabel->setText("Süre: "+QString::number(suresayac));

    connect(sure,SIGNAL(valueChanged(int)),this,SLOT(setSure(int)));

    sure->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 50, 200);"
                                   "width:"+QString::number(en*14)+"px;"
                                    "height:"+QString::number(boy/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 50, 255);"
                                   "width: "+QString::number(en/2)+"px;"
                                   "height: "+QString::number(boy/4)+"px;"
                                    "margin:-"+QString::number(en/8*3)+"px   0   -"+QString::number(boy/8*3)+"px   0;"
                                   "}");
             sure->hide();
                    sure->show();
        sayac->setFixedSize(this->width()*0.5, this->height()*0.3);
        sayac->move(this->width()/2-sayac->width()/2,this->height()/2-sayac->height()/2);

        sayac->show();

        QPushButton *sayacExitButton= new QPushButton(this);
        sayacExitButton->setFixedSize(en*0.5, boy*1);
        sayacExitButton->setIconSize(QSize(en*1,boy*1));
        sayacExitButton->setFlat(true);
        sayacExitButton->setIcon(QIcon(":icons/exit.svg"));
        sayacExitButton->move(width()-sayacExitButton->width(),0);
        connect(sayacExitButton, &QPushButton::clicked, [=]() {
            emit sayacCloseSignal();
            this->close();
        });



}

void toolSayac::saatslot(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    //sayac->display(text);
    saniye+=1;
   //qDebug()<<saniye;
    int hour=saniye/3600;
     int minute=saniye/60;
     int second=saniye%60;
     int sr=suresayac*60;

    sayac->setText(QString::number(sure->value()-1-minute)+":"+QString::number(60-second));
bar->setValue(saniye);
//if(minute>(sr*0.3))
//sayac->setStyleSheet("QLabel{size:170px;}");
QFont f( "Arial", 120, QFont::Bold);
sayac->setFont(f);
sayac->setAlignment(Qt::AlignCenter);

sayac->setStyleSheet("QLabel{color: rgb(0, 255, 0);}");
if(saniye>sr*0.33)sayac->setStyleSheet("QLabel{color: rgb(255, 255, 0);}");
if(saniye>0.66*sr)sayac->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
if(saniye>sr){
    sayac->setText("-00-");
    sayac->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
}



}

void toolSayac::setSure(int value)
{
    suresayac=value;
    suresayacLabel->setText("Süre: "+QString::number(suresayac));
}

void toolSayac::paintEvent(QPaintEvent *pe)
{
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}
