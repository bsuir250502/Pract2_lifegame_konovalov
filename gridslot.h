#include <QtQuick/QQuickView>
#ifndef GRIDSLOT_H
#define GRIDSLOT_H
class gridslot : public QObject
{
    Q_OBJECT
public slots:
    int signaltogrid(int x,int y);
    int gridtosignal(int x,int y);
};
#endif // GRIDSLOT_H
