#pragma once

#include <qdockwidget.h>

class QWidget;
class QVBoxLayout;
class QTreeView;

namespace blowbox
{
  namespace editor
  {
    class AssetsDock : public QDockWidget
    {
    public:
      AssetsDock(QMainWindow* main_window);
      ~AssetsDock();

    private:
      QWidget* dock_contents_;
      QVBoxLayout* dock_layout_;
      QTreeView* assets_tree_;
    };
  }
}