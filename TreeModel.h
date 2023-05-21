#pragma once

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QList>

#include "TreeItem.h"
#include "ProjectItem.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(QObject *parent = nullptr) : QAbstractItemModel(parent)
    {
        m_RootItem = new TreeItem();
        //setupModelData(data.split(QString("\n")), rootItem);

        addProjectItem();
    }

    ~TreeModel()
    {
        delete m_RootItem;
    }


    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override
    {
        /*
        if (!hasIndex(row, column, parent))
            return QModelIndex();
        */
        TreeItem *parentItem = m_RootItem;
        if (parent.isValid())
            parentItem = static_cast<TreeItem*>(parent.internalPointer());

        TreeItem *childItem = parentItem->childAt(row);
        //if (childItem)
        return createIndex(row, column, childItem);
        //else
        //return QModelIndex();
    }

    QModelIndex parent(const QModelIndex &index) const override
    {
        /*
        if (!index.isValid())
            return QModelIndex();
        */
        TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
        TreeItem *parentItem = childItem->parent();

        if (parentItem == m_RootItem)
            return QModelIndex();


        return createIndex(parentItem->row(), 0, parentItem);
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        /*
        if (parent.column() > 0)
            return 0;
        */
        TreeItem *parentItem = m_RootItem;
        if (parent.isValid())
            parentItem = static_cast<TreeItem*>(parent.internalPointer());
        return parentItem->childCount();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return 1;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        if (!index.isValid())
            return QVariant();

        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        switch (role) {
        case Qt::DisplayRole:
            return item->data();
        default:
            return QVariant();
        }
    }


    /*
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    */

private:
    void addProjectItem(){
        TreeItem* item_0_0 = new TreeItem();
        item_0_0->setData("item_0_0");
        TreeItem* item_0_1 = new TreeItem();
        item_0_1->setData("item_0_1");
        TreeItem* item_0_2 = new TreeItem();
        item_0_2->setData("item_0_2");

        TreeItem* item_0 = new TreeItem();
        item_0->setData("item_0");
        item_0->appendChild(item_0_0);
        item_0->appendChild(item_0_1);
        item_0->appendChild(item_0_2);


        m_RootItem->appendChild(item_0);

        ProjectItem* projectItem= new ProjectItem();
        projectItem->setRoot(item_0);
        projectItem->setArea(item_0_0);
        projectItem->addArea();
        projectItem->addRoot();


        m_ProjectItem.append(projectItem);

    }
private:
    TreeItem *m_RootItem;
    QList<ProjectItem*> m_ProjectItem;
};
