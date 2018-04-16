#pragma once

#include <qmainwindow.h>

class QApplication;
class QMenuBar;
class QMenu;
class QWidget;
class QGridLayout;
class QCloseEvent;

namespace blowbox
{
  namespace editor
  {
    class InspectorDock;
    class HierarchyDock;
    class AssetsDock;
    class ConsoleDock;

    class MainWindow : public QMainWindow
    {
      Q_OBJECT
    public:
      MainWindow(QApplication* app); 
      ~MainWindow();

      void closeEvent(QCloseEvent* evt);

    private:
      QApplication* app_;

      QMenuBar* menubar_;
      QMenu* menu_file_;
      QMenu* menu_edit_;
      QMenu* menu_assets_;

      QWidget* central_widget_;
      QWidget* grid_layout_widget_;
      QGridLayout* central_layout_;
      QWidget* render_view_;

      HierarchyDock* hierarchy_dock_;
      AssetsDock* assets_dock_;
      ConsoleDock* console_dock_;
      InspectorDock* inspector_dock_;
    };
  }
}