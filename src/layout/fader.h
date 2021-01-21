#ifndef FADER_H
#define FADER_H

#include <QWidget>
#include <QVBoxLayout>

class Fader : public QWidget
{
    Q_OBJECT
public:
    explicit Fader(QWidget *parent = nullptr);
    qreal getValue();
    void setValue(qreal val);
    void setMinValue(qreal min);
    void setMaxValue(qreal max);
    void setFaderColor(QColor color);
    void setHoleColor(QColor color);
    int getFaderSize();
    void setFaderSize(int newFaderSize);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    void valueChanged();

signals:
    void valueChanged(int a);
    void overMax();
    void underMin();

private:
    qreal value;
    qreal lastValue;
    qreal minValue;
    qreal maxValue;
    QColor faderColor;
    QColor holeColor;
    int size;
    int faderSize;
    bool follow;
    QPoint lastPoint;


    QVBoxLayout *layout;


};

#endif // FADER_H
