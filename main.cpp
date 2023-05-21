#include <QApplication>
#include "TreeView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeView treeView;
    treeView.show();
    return a.exec();
}
