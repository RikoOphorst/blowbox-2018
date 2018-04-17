#include "editor/main_window.h"

#include "core/core.h"
#include "core/logger.h"

#include <QtWidgets/qapplication.h>

using namespace blowbox;

int main(int argc, char** argv)
{
  core::Core blowbox_core = core::Core(argc, argv);
  QApplication app(argc, argv);

  editor::MainWindow* window = new editor::MainWindow(&app);

  window->show();

  return app.exec();
}