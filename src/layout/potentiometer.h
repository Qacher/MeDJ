#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <QWidget>
#include <QVBoxLayout>

class Potentiometer : public QWidget
{
    Q_OBJECT
public:
    explicit Potentiometer(QWidget *parent = nullptr);

    qreal getValue();
    void setValue(qreal val);
    void setMinValue(qreal min);
    void setMaxValue(qreal max);

    void setPotentiometerColor(QColor color);
    void setPinColor(QColor color);
    void setSize(int newSize);
    int getSize();
    void setLabel(QString newLabel);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    void displayChanged();

signals:
    void valueChanged(int a);
    void underMin();
    void overMax();

private:
    qreal value;
    qreal lastValue;
    qreal minValue;
    qreal maxValue;
    QColor potentiometerColor;
    QColor pinColor;
    int size;
    bool follow;
    QPoint lastPoint;
    QString label;
    QColor labelColor;

    QVBoxLayout *layout;


};

#endif // POTENTIOMETER_H
