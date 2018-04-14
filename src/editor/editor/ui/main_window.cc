#include "editor/ui/main_window.h"

#include <qstylefactory.h>

namespace blowbox
{
  namespace editor
  {
    //--------------------------------------------------------------------------
    MainWindow::MainWindow(QApplication* app) :
      app_(app)
    {
      ui_.setupUi(this);

      ApplyStyle(app);
    }

    //--------------------------------------------------------------------------
    void MainWindow::ApplyStyle(QApplication* app)
    {
      app->setStyle(QStyleFactory::create("Fusion"));

      QPalette steam;
      steam.setColor(QPalette::Window, QColor(88, 106, 80));
      steam.setColor(QPalette::WindowText, Qt::white);
      steam.setColor(QPalette::Base, QColor(64, 70, 60));
      steam.setColor(QPalette::AlternateBase, QColor(88, 106, 80));
      steam.setColor(QPalette::ToolTipBase, Qt::white);
      steam.setColor(QPalette::ToolTipText, Qt::white);
      steam.setColor(QPalette::Text, Qt::white);
      steam.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
      steam.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);
      steam.setColor(QPalette::Disabled, QPalette::Light, QColor(64, 70, 60));
      steam.setColor(QPalette::Button, QColor(88, 106, 80));
      steam.setColor(QPalette::ButtonText, Qt::white);
      steam.setColor(QPalette::BrightText, Qt::red);
      steam.setColor(QPalette::Link, QColor(159, 164, 98));

      steam.setColor(QPalette::Highlight, QColor(159, 164, 98));
      steam.setColor(QPalette::HighlightedText, Qt::black);

      app->setPalette(steam);

      QString dock_col = "rgb(111, 134, 102)";

      app->setStyleSheet("                      \
        QMainWindow::separator                  \
        {                                       \
          background-color: " + dock_col + ";   \
        }                                       \
        QDockWidget::title                      \
        {                                       \
          background-color: " + dock_col + ";   \
          border: 1px solid rgb(88, 106, 80);   \
        }                                       \
        QDockWidget                             \
        {                                       \
          color: white;                         \
        }"
      );
    }
  }
}