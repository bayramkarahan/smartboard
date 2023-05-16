#include "hakkinda.h"

Hakkinda::Hakkinda(int w, int h, QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(w,h);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    // setWindowFlags(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_StaticContents);
    // setAttribute(Qt::WA_TranslucentBackground, true);
    // this->setAttribute(Qt::WA_NoSystemBackground, false);
   /* QGridLayout *mainlayout = new QGridLayout(this);
    mainlayout->setAlignment(Qt::AlignCenter);
    mainlayout->setMargin(0);
    //mainlayout->addWidget(ml);*/
    setObjectName("promter");
    setStyleSheet("QWidget#promter{"
                  "border: 2px solid rgb(53, 132, 228);"
                  "border-radius: 5px;"
                  "background-color:rgba(250,250,250,255);"
                  "}");


    int en=w/20;
    int boy=h/20;
    //qDebug()<<en<<boy;

QLabel *hakkindaLabel=new QLabel(this);
QFont ff( "Arial", 10, QFont::Normal);
hakkindaLabel->setFont(ff);
//hakkindaLabel->hide();
hakkindaLabel->setFixedSize(w*0.4,h*0.8);
hakkindaLabel->move(width()/2-hakkindaLabel->width()/2,height()/2-hakkindaLabel->height()/2);
//hakkindaLabel->setStyleSheet("qproperty-alignment: AlignCenter;");

//hakkindaLabel->show();
hakkindaLabel->setText("Bu uygulama etkileşimli tahtalarda kullanılmak üzere yazılmıştır."
               "\n"
               "\nYapılabilecek Eylemler:"
               "\n\t* Çeşitli Kalem(Normal, Fosforlu)"
               "\n\t* Tahta Rengi (Şeffaf, Beyaz, Siyah,Özel Renk)"
               "\n\t* Tahta Desenleri(Yatay/Dikey Çizgi, Müzik,GüzelYazi)"
               "\n\t* Otomatik Silgi Seçimi(Kalem Kalınlığına Uygun)"
               "\n\t* Ekranda Taşıma Özelliği"
               "\n\t* Tam Ekran Modunda Çalışmalarda Üstte Konumlanma"
               "\n\t* Dışarıdan Arkaplan Resim Yükleme Özelliği"
               "\n\t* Ekran Görüntüsünü Kaydetme Özelliği"
               "\n\t* Geometrik Şekil Seçme,Taşıma,Boyutlandırma Özelliği"
               "\n\t* Farklı Sanal Masaüstünde Çalışma Özelliği"
               "\n\t* Geri ileri Alma Özelliği"
               "\n\t* Ekranın Her Alanına Yazma Özelliği"
               "\n\t* Pdf Dosyaları Yükleme ve Çalışma Kaydetme Özelliği"
               "\n\t* Nesne Olarak Resim Ekleme Özelliği"
               "\n\t* Yazdırma Özelliği"
               "\n\t* Ekranın Bölgesini (Kesme,Taşıma,Büyültme) Özelliği"
               "\n\t* Kullanıcı Ayarlarını Kaydetme ve Açma Özelliği"
               "\n\t* Sınavlar için Sayaç Özelliği"
               "\n*****************************************************************************"
               "\n   Copyright (C) 2023 by Bayram KARAHAN                                    "
               "\n\tgithub.com/bayramkarahan/E-Tahta"
               "\n\tbayramkarahan.blogspot.com"
               "\n\tbayramk@gmail.com  "
                "\n\n   This program is free software; you can redistribute it and/or modify    "
                "\n   it under the terms of the GNU General Public License as published by    "
                "\n   the Free Software Foundation; either version 3 of the License, or       "
                "\n   (at your option) any later version.                                     "
                "\n                                                                           "
                "\n   This program is distributed in the hope that it will be useful,         "
                "\n   but WITHOUT ANY WARRANTY; without even the implied warranty of          "
                "\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           "
                "\n   GNU General Public License for more details.                            "
                "\n                                                                           "
                "\n   You should have received a copy of the GNU General Public License       "
                "\n   along with this program; if not, write to the                          "
                "\n   Free Software Foundation, Inc.,                                         "
                "\n   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          "

               );


QPushButton *sayacExitButton= new QPushButton(this);
sayacExitButton->setFixedSize(en*0.5, boy*1);
sayacExitButton->setIconSize(QSize(en*1,boy*1));
sayacExitButton->setFlat(true);
sayacExitButton->setIcon(QIcon(":icons/exit.svg"));
sayacExitButton->move(width()-sayacExitButton->width(),0);
connect(sayacExitButton, &QPushButton::clicked, [=]() {
    emit hakkindaCloseSignal();
    this->close();
});
}


