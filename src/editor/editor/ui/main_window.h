#pragma once

#include "ui_main_window.h"

#include <qmainwindow.h>

namespace blowbox
{
  namespace editor
  {
    class Console;

    class MainWindow : public QMainWindow
    {
    public:
      MainWindow(QApplication* app);
      void ApplyStyle(QApplication* app);

    private:
      Ui::main_window ui_;
      QApplication* app_;
    };
  }
}