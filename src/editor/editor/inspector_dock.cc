#include "inspector_dock.h"

#include <qdockwidget.h>
#include <qwidget.h>
#include <qboxlayout.h>
#include <qtreeview.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    InspectorDock::InspectorDock(QMainWindow* main_window) :
      QDockWidget(QStringLiteral("Inspector"), main_window),
      dock_contents_(nullptr),
      dock_layout_(nullptr),
      inspector_tree_(nullptr)
    {
      setObjectName(QStringLiteral("inspector_dock"));
      setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

      dock_contents_ = new QWidget();
      dock_contents_->setObjectName(QStringLiteral("hierarchy_dock_contents"));

      dock_layout_ = new QVBoxLayout(dock_contents_);
      dock_layout_->setObjectName(QStringLiteral("hierarchy_dock_layout"));

      inspector_tree_ = new QTreeView(dock_contents_);
      inspector_tree_->setObjectName(QStringLiteral("inspector_tree"));

      dock_layout_->addWidget(inspector_tree_);
      setWidget(dock_contents_);

      main_window->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, this);
    }

    //------------------------------------------------------------------------------------------------------
    InspectorDock::~InspectorDock()
    {
      delete inspector_tree_;
      delete dock_layout_;
      delete dock_contents_;
    }
  }
}