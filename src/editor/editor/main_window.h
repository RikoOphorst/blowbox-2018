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

    /**
    * @brief The main editor window.
    *
    * Controls all of the UI of the editor. It creates the entire UI.
    * The UI is retrieved from main_window.ui.
    */
    class MainWindow : public QMainWindow
    {
    public:
      /**
      * @brief Constructs the MainWindow.
      * @param[in] app The QApplication that the MainWindow should be created under.
      */
      MainWindow(QApplication* app); 

      /**
      * @brief Destructs the MainWindow.
      */
      ~MainWindow();

      /**
      * @brief Saves the entire layout configuration that the user configured to disk.
      */
      void SaveLayout();

      /**
      * @brief Restores the entire layout configuration that was saved with SaveLayout().
      */
      void RestoreLayout();

    public:
      /**
      * @brief Overrides the close event for the MainWindow. Saves Layout & closes the application.
      * @param[in] evt The close event that is associated with closing the main window.
      */
      void closeEvent(QCloseEvent* evt) override;

    private:
      Ui::MainWindow* main_window_; //!< The MainWindow UI generated by UIC from main_window.ui.
      QApplication* app_; //!< The QApplication this MainWindow is part of.

      ConsoleDock* console_dock_; //!< UI controller that controls the console dock window in the MainWindow.
    };
  }
}