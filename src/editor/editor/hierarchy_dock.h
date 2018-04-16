#pragma once

#include "editor/main_window.h"

#include <qdockwidget.h>

class QWidget;
class QVBoxLayout;
class QTreeView;

namespace blowbox
{
  namespace editor
  {
    class HierarchyDock : public QDockWidget
    {
    public:
      HierarchyDock(QMainWindow* main_window);
      ~HierarchyDock();

    private:
      QWidget* dock_contents_;
      QVBoxLayout* dock_layout_;
      QTreeView* hierarchy_tree_;
    };
  }
}