#include "main_window.h"

#include "editor/console_dock.h"
#include "ui_main_window.h"

#include <qapplication.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qstylefactory.h>
#include <qsettings.h>

#include <iostream>

namespace blowbox
{
  namespace editor
  {
    //--------------------------------------------------------------------------
    MainWindow::MainWindow(QApplication* app) :
      app_(app)
    {
      Q_INIT_RESOURCE(style);

      QFile f(":qdarkstyle/style.qss");
      
      if (!f.exists())
      {
        printf("Unable to set stylesheet, file not found\n");
      }
      else 
      {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app_->setStyleSheet(ts.readAll());
      }

      app_->setStyle(QStyleFactory::create("Fusion"));

      main_window_ = new Ui::MainWindow();
      main_window_->setupUi(this);

      console_dock_ = new ConsoleDock(
        main_window_->console_dock_contents,
        main_window_->channels_filter,
        main_window_->logs_checkbox,
        main_window_->warnings_checkbox,
        main_window_->errors_checkbox,
        main_window_->console_view,
        main_window_->console_input,
        main_window_->console_submit
      );

      RestoreLayout();
    }

    //------------------------------------------------------------------------------------------------------
    MainWindow::~MainWindow()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void MainWindow::SaveLayout()
    {
      QSettings settings("Riko Ophorst", "Blowbox");
      settings.setValue("geometry", saveGeometry());
      settings.setValue("windowState", saveState());
    }

    //------------------------------------------------------------------------------------------------------
    void MainWindow::RestoreLayout()
    {
      QSettings settings("Riko Ophorst", "Blowbox");
      QByteArray saved_geometry = settings.value("geometry").toByteArray();
      restoreGeometry(saved_geometry);
      QByteArray saved_state = settings.value("windowState").toByteArray();
      restoreState(saved_state);
    }

    //------------------------------------------------------------------------------------------------------
    void MainWindow::closeEvent(QCloseEvent *event)
    {
      SaveLayout();
    }
  }
}