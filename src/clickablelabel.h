#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

#include <QLabel>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    explicit ClickableLabel(const QString &text = "", QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();
};
namespace _Label {
class ClickableLabel : public QLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLICKABLELABEL_H
