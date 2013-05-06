#include <QtQuick/QQuickView>
#ifndef GRIDSLOT_H
#define GRIDSLOT_H

int checkgriditem(int,int);

class gridslot : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE int getstate(int x, int y) const
    {
        return checkgriditem(x-1,y-1);
    }

public slots:
    void signaltogrid(int x,int y);
    void gridrecalculate(void);

signals:
    void gridupdated(void);

};
#endif // GRIDSLOT_H
