#include <QtGui/QGuiApplication>
#include <QtQml>
#include "qtquick2applicationviewer.h"
#include "stdio.h"
#include "stdlib.h"
#include "gridslot.h"

typedef struct _grid{
    int state;
    int previous_state;
} grid_t;

int grid_check_circular(int, int);
void grid_debug(void);

grid_t** grid;
int grid_height;
int grid_width;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    gridslot slotclass;
    QtQuick2ApplicationViewer viewer;
    qmlRegisterType<gridslot>("Test", 1, 0, "Gridslot");
    viewer.setMainQmlFile(QStringLiteral("qml/LifeGame/main.qml"));
    viewer.showExpanded();

    QObject::connect((QObject*)viewer.rootObject(), SIGNAL(gridwrite(int,int)), &slotclass, SLOT(signaltogrid(int,int)));
    QObject::connect((QObject*)viewer.rootObject(), SIGNAL(updategrid()), &slotclass, SLOT(gridrecalculate()));
    QObject::connect(&slotclass, SIGNAL(gridupdated()), (QObject*)viewer.rootObject(), SIGNAL(gridupdated()));

    int i;
    grid=(grid_t**)calloc(10,sizeof(grid_t*));
    for (i=0;i<10;i++)
        grid[i]=(grid_t*)calloc(10,sizeof(grid_t));
    return app.exec();
}

void gridslot::signaltogrid(int x,int y)
{
    int *state=&(grid[x-1][y-1].state);
    char debug[20];
    *state=1-*state;
    sprintf(debug,"x=%d y=%d state=%d",x,y,*state);
    qDebug(debug);
    return;
}

void gridslot::gridrecalculate(void)
{
    int i,j,neighbours_n;
    qDebug("griderecalculate executed");
    for(i=0;i<10;i++)
        for (j=0;j<10;j++)
            grid[i][j].previous_state=grid[i][j].state;
    for(i=0;i<10;i++)
        for (j=0;j<10;j++)
        {
           neighbours_n=grid_check_circular(i,j);
           if (grid[i][j].previous_state==0)
               if (neighbours_n==3)
                   grid[i][j].state=1;
           if (grid[i][j].previous_state==1)
               if (neighbours_n<2 || neighbours_n>3)
                   grid[i][j].state=0;
        }
    emit gridupdated();
    grid_debug();
    qDebug("Grid successfully updated");
}

void grid_debug(void)
{
    int i,j;
    char temp[22];
    for (i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            sprintf (temp+j*2,"%d ",grid[i][j].state);
        *(temp+j*2)='\0';
        qDebug(temp);
    }
}

int checkgriditem(int x, int y)
{
    return grid[x][y].state;
}

int grid_check_circular(int x, int y)
{
    int neighbours_n=0;
    int x_c,y_c,i,j;
    for (i=-1;i<2;i++)
        for (j=-1;j<2;j++)
        {
            x_c=x+i;
            y_c=y+j;
            if (x_c<0)
                x_c=9;
            if (x_c>9)
                x_c=0;
            if (y_c<0)
                y_c=9;
            if (y_c>9)
                y_c=0;
            if (grid[x_c][y_c].previous_state==1)
                neighbours_n++;
        }
    neighbours_n=neighbours_n-grid[x][y].previous_state;
    return neighbours_n;
}
