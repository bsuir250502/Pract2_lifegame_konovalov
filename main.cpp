#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "stdio.h"
#include "stdlib.h"
#include "gridslot.h"

typedef struct _grid{
    int state;
    int previous_state;
} grid_t;

int change_grid_state(int x,int y,grid_t**);

grid_t** grid;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    gridslot slotclass;
    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/LifeGame/main.qml"));
    viewer.showExpanded();

    QObject::connect((QObject*)viewer.rootObject(), SIGNAL(gridwrite(int,int)), &slotclass, SLOT(signaltogrid(int,int)));
    QObject::connect((QObject*)viewer.rootObject(), SIGNAL(gridread(int,int)), &slotclass, SLOT(gridtosignal(int,int)));

    int i;
    grid=(grid_t**)calloc(10,sizeof(grid_t*));
    for (i=0;i<10;i++)
        grid[i]=(grid_t*)calloc(10,sizeof(grid_t));
    return app.exec();
}

int gridslot::signaltogrid(int x,int y)
{
    //state=change_grid_state(x,y,grid);
    qDebug("AHAHAHHA");
    return 1;
}

int gridslot::gridtosignal(int x,int y)
{
    return 0;
}
