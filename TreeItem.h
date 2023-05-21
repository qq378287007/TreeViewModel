#pragma once

#include <QList>
#include <QVariant>

class TreeItem
{
public:
    explicit TreeItem(TreeItem *Parent = nullptr): m_Parent(Parent)
    {
    }
    ~TreeItem()
    {
        for(int i=0; i<childCount(); i++)
            delete childAt(i);
    }
    QVariant data() const {
        return m_Data;
    }
    void setData(QVariant Data){
        m_Data = Data;
    }

    TreeItem *parent() const
    {
        return m_Parent;
    }
    void setParent(TreeItem *Parent){
        m_Parent = Parent;
    }

    void appendChild(TreeItem *child)
    {
        m_Child.append(child);
        child->setParent(this);
    }

    TreeItem *childAt(int row) const
    {
        return m_Child.at(row);
    }

    int childCount() const
    {
        return m_Child.count();
    }

    int row() const
    {
        if (m_Parent)
            m_Parent->m_Child.indexOf(const_cast<TreeItem*>(this));
        return 0;
    }
private:
    QVariant m_Data;
    TreeItem* m_Parent;
    QList<TreeItem*> m_Child;
};
