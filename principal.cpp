#include "principal.h"
#include "ui_principal.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();
    ui->outCuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);
     mPaintor = new QPainter(&lienzo);

    int x = 0;
    int y = 0;

    // CREAR UN PINCEL PARA LOS BORDES
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    painter.setPen(pincel);

    // DIBUJAR PRIMERA BARRA
    painter.drawRect(x+50, y+50,100,400);

    // CREAR UN OBJETO COLOR PARA EL RELLENO
    QColor colorRelleno(190,120,162);
    // CREAR UN OBJETO COLOR PARA EL RELLENO
    QColor colorBorde(234, 128, 252);

    // CAMBIAR EL COLOR DEL PINCEL
    painter.setPen(colorBorde);

    // VOLVER A ESTABLECER EL PINCEL AL "pintor"
    painter.setPen(pincel);
    // ESTABLECER EL COLOR AL brush (relleno)
    painter.drawRect(x+170,y+200,100,250);

    // CREANDO LOS COLORES DE LA TERCERA BARRA
    QColor cRellenoBarra3(253,253,115);
    QColor cBordeBarra3(123, 31, 162);

    // ESTABLECIENDO COLORES AL PINCEL Y AL PAINTER
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // DIBUJAR TERCERRA BARRA
    painter.drawRect(x+290,y+350,100,100);

// MOSTRAR  LOS VALORES DE LOS EJES X Y Y


    y=50;
    x=20;
    //EJES Y
    int num=100;
    for(int i=y;i<450;i+=100){

        painter.drawLine(x-5,i,x-5,i);
        QString linea=QString::number(num);
        num-=25;
        painter.drawText(x-20,i,linea);


    }
    painter.drawLine(x,y-30,x,y+400);
    // EJES X
    int notan=1;
    for(int u=x;u<450;u+=130){
        painter.drawLine(u,y+405,u,y+405);
        QString linea2=QString::number(notan);
        QString Nota="Nota ";
        painter.drawText(u,x+450,Nota+linea2);
        notan +=1;

    }
    painter.drawLine(x+5,y+400,x+400,y+400);
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar Imagen",QString(),"Imagenes(*.png)");
    if(!nombreArchivo.isEmpty()){
        if(lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardado imagen", "Guardado imagen en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen", "No se pudo guardar el archivo");
    }
}

void Principal::on_pushPromediar_released()
{
    float nota1=  ui->inNota1->value();
    float nota2 = ui->inNota2->value();
    float nota3=  ui->inNota3->value();
    float promedio;
    promedio =(nota1+nota2+nota3)/3.00;
    QString promedioS=QString::number(promedio);
    ui->outPromedio->setText(promedioS);
}
