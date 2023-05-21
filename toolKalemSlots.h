#ifndef TOOLKALEMSLOTS_H
#define TOOLKALEMSLOTS_H
#include<toolKalem.h>
void toolKalem::buttonStateClear()
{
    desktopButton->setChecked(false);
    handButton->setChecked(false);
    copyButton->setChecked(false);
    penButton->setChecked(false);
    eraseButton->setChecked(false);
    sekilButton->setChecked(false);

}

void toolKalem::handButtonSlot(bool menushow)
{
    buttonStateClear();handButton->setChecked(true);
    if(menushow) current_toolKalemMenu->hide();

    currentMode=Scene::Mode::SelectObject;oldMode=Scene::Mode::SelectObject;
    currentType=DiagramItem::DiagramType::NoType;;oldType=DiagramItem::DiagramType::NoType;;

    current_toolTahta->scene->sceneMode=Scene::Mode::SelectObject;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
    if(current_toolTahta->scene->pdfObjectAdded) current_toolTahta->scene->pdfMoved=true;
modeKontrolSlot();
}

void toolKalem::penButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
    penButton->setIcon(QIcon(":icons/pen.svg"));
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::NormalPen;
    oldType=DiagramItem::DiagramType::NormalPen;
modeKontrolSlot();
}
void toolKalem::patternpenButtonSlot(bool menushow)
{

    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
    penButton->setIcon(QIcon(":icons/patternpen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::PatternPen;
    oldType=DiagramItem::DiagramType::PatternPen;
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenPattern;


modeKontrolSlot();
}

void toolKalem::smartpenButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
     penButton->setIcon(QIcon(":icons/smartpen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(true);
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::SmartPen;
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::SmartPen;
    oldType=DiagramItem::DiagramType::SmartPen;;
modeKontrolSlot();

}
void toolKalem::fosforpenButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
      penButton->setIcon(QIcon(":icons/fosforlupen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    current_toolTahta->scene->setPenAlpha(50);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenFosfor;
    currentMode=Scene::Mode::DrawPenFosfor;
    oldMode=Scene::Mode::DrawPenFosfor;
    currentType=DiagramItem::DiagramType::FosforluPen;
    oldType=DiagramItem::DiagramType::FosforluPen;;
modeKontrolSlot();
}

void toolKalem::clearButtonSlot()
{
    oldMode=currentMode;
    oldType=currentType;
    current_toolTahta->scene->removeAllItem();
}

void toolKalem::eraseButtonSlot()
{
    buttonStateClear();eraseButton->setChecked(true);
    current_toolKalemMenu->toolKalemMenuOlustur(eraseTopMenu(parenth*0.045),parentw*0.2,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
    current_toolTahta->scene->setEraseSize(penSize);
    current_toolTahta->scene->sceneMode=Scene::Mode::EraseMode;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
    currentMode=Scene::Mode::EraseMode;oldMode=Scene::Mode::EraseMode;
    currentType=DiagramItem::DiagramType::NoType;oldType=DiagramItem::DiagramType::NoType;
    modeKontrolSlot();
}

void toolKalem::copyButtonSlot()
{
      buttonStateClear();copyButton->setChecked(true);
    current_toolKalemMenu->hide();
    current_toolTahta->scene->setMode(Scene::Mode::CopyMode, DiagramItem::DiagramType::Copy);
    current_toolTahta->scene->sceneMode=Scene::Mode::CopyMode;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::Copy;
    oldMode=Scene::Mode::CopyMode;oldType=DiagramItem::DiagramType::NoType;
    currentMode=Scene::Mode::CopyMode;currentType=DiagramItem::DiagramType::Copy;

    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    QPixmap desk = qApp->screens().at(0)->grabWindow(QDesktopWidget().winId(),0,0,parentw,parenth);
    current_toolTahta->scene->setImage(desk);
    modeKontrolSlot();
}

void toolKalem::zeminButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(zeminTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
    //emit kalemZeminModeSignal(DiagramItem::DiagramType::WhitePage);
    current_toolTahta->gvToTahta();

}
void toolKalem::sekilButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(sekilTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::pdfButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(pdfTopMenu(parenth*0.045),parentw*0.2,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::toolButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(toolTopMenu(parenth*0.045),parentw*0.3,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::sceneToPen()
{
    penSize=current_toolTahta->scene->myPenSize;
    penAlpha=current_toolTahta->scene->myPenAlpha;
    penColor=current_toolTahta->scene->myPenColor;
    penStyle=current_toolTahta->scene->myPenStyle;
    sekilType=current_toolTahta->scene->mySekilType;
    sekilZeminColor=current_toolTahta->scene->mySekilKalemColor;
    zeminDolguColor=current_toolTahta->scene->myzeminDolguColor;

    //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
    //   current_toolTahta->scene->makeItemsControllable(false);
    // connect(current_toolTahta->scene, SIGNAL(sceneItemAddedSignal()),
    //this,SLOT(sceneItemAddedSignalSlot()));
    //  sceneItemAddedSignalSlot();
    // handButtonSlot();
    //kalemPenModeSignalSlot(DiagramItem::DiagramType::NormalPen);



}

void toolKalem::desktopButtonSlot()
{
   qDebug()<<"Desktop Pen Modu Ayarlanır.."<<penDesktopStatus;
    buttonStateClear();
    if(!penDesktopStatus)
    {
        desktopButton->setChecked(false);
        penDesktopStatus=true;
        //current_toolTahta->hide();
        emit desktopSignal();
        //emit kalemModeSignal(Scene::Mode::PenMode,DiagramItem::DiagramType::NoType);
        desktopButton->setIcon(QIcon(":/icons/smartboard.svg"));

    }else
    {
        desktopButton->setChecked(true);
        //current_toolTahta->show();
        emit penSignal();
        penDesktopStatus=false;
        penButtonSlot(true);
        //emit kalemModeSignal(Scene::Mode::DesktopMode,DiagramItem::DiagramType::NoType);
        desktopButton->setIcon(QIcon(":/icons/desktop.svg"));
    }

}

void toolKalem::sagSolHizala()
{
    if (!sagSolHizaStatus)
    {
        move(parentw-this->width()-5,parenth/2- this->height()/2);
       if(sagSolHizaStatusInit) sagSolHizaStatus=true;
       sagSolHizaStatusInit=true;
    }else
    {
        move(5,parenth/2- this->height()/2);
        sagSolHizaStatus=false;
    }

}

void toolKalem::infoButtonClick(){
    //emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);


        Hakkinda *hakkinda=new Hakkinda(parentw*0.40,parenth*0.9);
        connect(hakkinda, SIGNAL(hakkindaCloseSignal()),
                this, SLOT(hakkindaCloseSignalSlot()));

        hakkinda->move(parentw/2-hakkinda->width()/2,parenth/2-hakkinda->height()/2);
        Qt::WindowFlags flags = 0;
        flags |= Qt::FramelessWindowHint;
        //flags |= Qt::X11BypassWindowManagerHint;
        hakkinda->setWindowFlags(flags);


        current_toolTahta->hide();
        current_toolKalemMenu->hide();
        current_toolPageMenu->hide();
        this->hide();
hakkinda->show();

}

bool toolKalem::eventFilter(QObject * obj, QEvent *event)
{
   /* if (event->type() == QEvent::Show && obj == sekilButton->menu())
    {
         int button_x = mapToParent(sekilButton->pos()).x();
        int button_y = mapToParent(sekilButton->pos()).y();

        int menu_width = sekilButton->menu()->size().width();
        int menu_height = sekilButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        sekilButton->menu()->move(pos);
        return true;
    }
    if (event->type() == QEvent::Show && obj == penButton->menu())
    {
         int button_x = mapToParent(penButton->pos()).x();
        int button_y = mapToParent(penButton->pos()).y();

        int menu_width = penButton->menu()->size().width();
        int menu_height = penButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y);
        penButton->menu()->move(pos);
        return true;
    }
    if (event->type() == QEvent::Show && obj == zeminButton->menu())
    {
         int button_x = mapToParent(zeminButton->pos()).x();
        int button_y = mapToParent(zeminButton->pos()).y();

        int menu_width = zeminButton->menu()->size().width();
        int menu_height = zeminButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        zeminButton->menu()->move(pos);
        return true;
    }
  /*  if (event->type() == QEvent::Show && obj == colorButton->menu())
    {
         int button_x = mapToParent(colorButton->pos()).x();
        int button_y = mapToParent(colorButton->pos()).y();

        int menu_width = colorButton->menu()->size().width();
        int menu_height = colorButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        colorButton->menu()->move(pos);
        return true;
    }*/
    return false;
}

void toolKalem::mouseMoveEvent(QMouseEvent *event)
{ //qDebug()<<"main mouse  move"<<event->pos();
       if ((event->buttons() & Qt::LeftButton) && mouseClick==true) {

          //this->move(mapToParent(event->pos()));
         /*  QPoint newpos_min = mapToParent(event->pos()-offset);
                 QPoint newpos_max = QPoint(newpos_min.x() + this->width(), newpos_min.y() + this->height());

                 if(newpos_min.x() > 0 &&
                    newpos_min.y() > 0 &&
                    newpos_max.x() < this->parentWidget()->width() &&
                    newpos_max.y() < this->parentWidget()->height()){

                     this->move(mapToParent(event->pos() - offset));
                 }
                 */
           //Excute movement follow mouse position
                /*  move(mapToParent(event->pos() - offset));
                  //Make sure control do not move out parent size
                  if (x() < 0)
                      move(1, y());
                  if (y() < 0)
                      move(x(), 1);
                  if (x() + width() > parentWidget()->width())
                      move(parentWidget()->width() - 1 - width(), y());
                  if (y() + height() > parentWidget()->height())
                      move(x(), parentWidget()->height() - 1 - height());
*/

   }

}

void toolKalem::mousePressEvent(QMouseEvent *event)
{
   // qDebug()<<"main press";

            if ((event->buttons() & Qt::LeftButton)) {
            offset = event->pos();

            mouseClick = true;


            }

}

void toolKalem::mouseReleaseEvent(QMouseEvent *event)
{
    // qDebug()<<"main mouse release";
    if (event->button() == Qt::LeftButton && mouseClick) {

          mouseClick = false;

      }
}

#endif // TOOLKALEMSLOTS_H
