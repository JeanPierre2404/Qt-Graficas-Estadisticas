#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();



    void on_pushPromediar_released();

private:
    Ui::Principal *ui;
    QPixmap lienzo;
    QPainter *mPaintor;
    void dibujar();

};
#endif // PRINCIPAL_H
