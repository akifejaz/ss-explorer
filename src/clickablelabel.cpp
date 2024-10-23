#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
    QLabel::mousePressEvent(event);
}
