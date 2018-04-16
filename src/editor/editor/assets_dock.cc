#include "assets_dock.h"

#include <qmainwindow.h>
#include <qdockwidget.h>
#include <qwidget.h>
#include <qboxlayout.h>
#include <qtreeview.h>

namespace blowbox
{
  namespace editor
  {
    //------------------------------------------------------------------------------------------------------
    AssetsDock::AssetsDock(QMainWindow* main_window) :
      QDockWidget(QStringLiteral("Assets"), main_window),
      dock_contents_(nullptr),
      dock_layout_(nullptr),
      assets_tree_(nullptr)
    {
      setObjectName(QStringLiteral("assets_dock"));
      setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
      
      dock_contents_ = new QWidget();
      dock_contents_->setObjectName(QStringLiteral("assets_dock_contents"));
      dock_layout_ = new QVBoxLayout(dock_contents_);
      dock_layout_->setObjectName(QStringLiteral("assets_dock_layout"));
      
      assets_tree_ = new QTreeView(dock_contents_);
      assets_tree_->setObjectName(QStringLiteral("assets_tree"));
      assets_tree_->setMinimumSize(QSize(50, 0));

      dock_layout_->addWidget(assets_tree_);
      
      setWidget(dock_contents_);

      main_window->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, this);
    }

    //------------------------------------------------------------------------------------------------------
    AssetsDock::~AssetsDock()
    {
      delete assets_tree_;
      delete dock_layout_;
      delete dock_contents_;
    }
  }
}