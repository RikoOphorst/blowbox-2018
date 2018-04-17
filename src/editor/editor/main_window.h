#pragma once

#include <qmainwindow.h>

class QApplication;

namespace Ui
{
  class MainWindow;
}

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
    public:
      MainWindow(QApplication* app); 
      ~MainWindow();

      void SaveLayout();
      void RestoreLayout();

    public:
      void closeEvent(QCloseEvent* evt) override;

    private:
      Ui::MainWindow* main_window_;
      QApplication* app_;

      HierarchyDock* hierarchy_dock_;
      AssetsDock* assets_dock_;
      ConsoleDock* console_dock_;
      InspectorDock* inspector_dock_;
    };
  }
}