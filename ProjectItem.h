#pragma once

#include "TreeItem.h"

class ProjectItem
{
public:
    explicit ProjectItem()
    {
    }
    ~ProjectItem()
    {
    }
    void setRoot(TreeItem *RootItem){
        m_RootItem = RootItem;
    }
    void setArea(TreeItem *AreaItem){
        m_AreaItem = AreaItem;
    }
    void addRoot(){
        TreeItem* item_0_n = new TreeItem();
        item_0_n->setData("item_0_n");
        m_RootItem->appendChild(item_0_n);
    }
    void addArea(){
        TreeItem* item_0_0_n = new TreeItem();
        item_0_0_n->setData("item_0_0_n");
        m_AreaItem->appendChild(item_0_0_n);

    }
private:
    TreeItem *m_RootItem;
    TreeItem *m_AreaItem;
};
