#include "loadform.h"
#include "ui_loadform.h"

LoadForm::LoadForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadForm)
{
    ui->setupUi(this);
}

LoadForm::~LoadForm()
{
    delete ui;
}

void LoadForm::start()
{
    timer.setInterval(100);
    connect(&timer, &QTimer::timeout, this, &LoadForm::add);
    timer.start(); 
    setPalette(QPalette(QPalette::Window, Qt::black));
}

void LoadForm::add()
{
    index++;
    repaint();
}

void LoadForm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    QPen mPen;
    mPen.setColor(Qt::black);
    painter.setPen(mPen);
    int color = 0 + index%8 * 32;
    for (int i = color; i < 256; i += 32) {
        painter.setBrush(QColor::fromHsv(0, 0, i));
        painter.drawEllipse(-100, -100, 50, 50);
        painter.rotate(-45);
    }
    for (int i = 0; i < color; i += 32) {
        painter.setBrush(QColor::fromHsv(0, 0, i));
        painter.drawEllipse(-100, -100, 50, 50);
        painter.rotate(-45);
    }
}
