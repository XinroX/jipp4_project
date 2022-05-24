#ifndef LOADFORM_H
#define LOADFORM_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

namespace Ui {
class LoadForm;
}

class LoadForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit LoadForm(QWidget *parent = nullptr);
    ~LoadForm();
    void start();
private:
    Ui::LoadForm *ui;
    int index = 0;
    QTimer timer;
    
private slots:
    void add();
    
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // LOADFORM_H
