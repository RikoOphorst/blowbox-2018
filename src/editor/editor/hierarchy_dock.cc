#include "hierarchy_dock.h"

#include <qdockwidget.h>
#include <qwidget.h>
#include <qboxlayout.h>
#include <qtreeview.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    HierarchyDock::HierarchyDock(QMainWindow* main_window) :
      QDockWidget(QStringLiteral("Hierarchy"), main_window),
      dock_contents_(nullptr),
      dock_layout_(nullptr),
      hierarchy_tree_(nullptr)
    {
      setObjectName(QStringLiteral("hierarchy_dock"));
      setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

      dock_contents_ = new QWidget();
      dock_contents_->setObjectName(QStringLiteral("hierarchy_dock_contents"));

      dock_layout_ = new QVBoxLayout(dock_contents_);
      dock_layout_->setObjectName(QStringLiteral("hierarchy_dock_layout"));

      hierarchy_tree_ = new QTreeView(dock_contents_);
      hierarchy_tree_->setObjectName(QStringLiteral("hierarchy_tree"));

      dock_layout_->addWidget(hierarchy_tree_);
      setWidget(dock_contents_);

      main_window->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, this);
    }

    //------------------------------------------------------------------------------------------------------
    HierarchyDock::~HierarchyDock()
    {
      delete hierarchy_tree_;
      delete dock_layout_;
      delete dock_contents_;
    }
  }
}