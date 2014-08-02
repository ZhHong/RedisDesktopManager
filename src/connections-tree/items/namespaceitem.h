#ifndef NAMESPACEITEM_H
#define NAMESPACEITEM_H

#include "treeitem.h"
#include "connections-tree/operations.h"

namespace ConnectionsTree {

    class NamespaceItem : public TreeItem
    {
    public:
        NamespaceItem(const QString& fullPath,  QSharedPointer<Operations> operations, const TreeItem* parent);

        QString getDisplayName() const override;
        QIcon getIcon() const override;
        QList<QSharedPointer<TreeItem>> getAllChilds() const override;
        uint childCount() const override;
        QSharedPointer<TreeItem> child(int row) const override;
        const TreeItem* parent() const override;

        bool onClick(ParentView& treeView, TabWidget& tabs) override;
        void onWheelClick(ParentView& treeView, TabWidget& tabs) override;
        QSharedPointer<QMenu> getContextMenu(ParentView& treeView, TabWidget& tabs) override;

        bool isLocked() const override;

        void append(QSharedPointer<TreeItem> item);

    private:
        QString m_fullPath;
        QSharedPointer<Operations> m_operations;
        const TreeItem* m_parent;
        bool m_locked;
        QList<QSharedPointer<TreeItem>> m_childItems;
    };

}
#endif // NAMESPACEITEM_H
