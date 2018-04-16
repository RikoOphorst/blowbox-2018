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
    class InspectorDock : public QDockWidget
    {
    public:
      InspectorDock(QMainWindow* main_window);
      ~InspectorDock();

    private:
      QWidget* dock_contents_;
      QVBoxLayout* dock_layout_;
      QTreeView* inspector_tree_;
    };
  }
}