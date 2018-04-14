#include "editor/ui/main_window.h"

#include <QtWidgets/qapplication.h>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  blowbox::editor::MainWindow* window = new blowbox::editor::MainWindow(&app);

  window->show();

  return app.exec();
}